#include <bits/stdc++.h>

using namespace std;

const int md = 490019;

int add(int x, int y) {
  x += y;
  if (x >= md) {
    x -= md;
  }
  return x;
}

int mul(int x, int y) {
  return (long long)x * y % md;
}

namespace fft {
typedef double ld;

const ld pi = acos(-1);
  
struct complex_t {
  ld x, y;
  
  complex_t(ld x = 0, ld y = 0):x(x), y(y) {
  }

  complex_t operator + (const complex_t &b) const {
    return complex_t(x + b.x, y + b.y);
  }

  complex_t operator - (const complex_t &b) const {
    return complex_t(x - b.x, y - b.y);
  }

  complex_t operator * (const complex_t &b) const {
    return complex_t(x * b.x - y * b.y, x * b.y + y * b.x);
  }
};

complex_t conj(complex_t a) {
  return complex_t(a.x, -a.y);
}

vector<complex_t> fa, fb, roots = {complex_t(0, 0), complex_t(1, 0)};
vector<int> rev = {0, 1};
int base = 1;

void ensure_base(int nbase) {
  if (nbase <= base) {
    return;
  }
  rev.resize(1 << nbase);
  for (int i = 0; i < (1 << nbase); ++i) {
    rev[i] = rev[i >> 1] >> 1 | ((i & 1) << nbase - 1);
  }
  roots.resize(1 << nbase);
  while (base < nbase) {
    ld angle = 2 * pi / (1 << base + 1);
    for (int i = 1 << base - 1; i < 1 << base; ++i) {
      roots[i << 1] = roots[i];
      ld angle_i = angle * ((i << 1) + 1 - (1 << base));
      roots[i << 1 | 1] = complex_t(cos(angle_i), sin(angle_i));
    }
    ++base;
  }
}

void dft(vector<complex_t> &a, int n) {
  int zeros = __builtin_ctz(n);
  ensure_base(zeros);
  int shift = base - zeros;
  for (int i = 0; i < n; ++i) {
    if (i < rev[i] >> shift) {
      swap(a[i], a[rev[i] >> shift]);
    }
  }
  for (int i = 1; i < n; i <<= 1) {
    for (int j = 0; j < n; j += i << 1) {
      for (int k = 0; k < i; ++k) {
        complex_t x = a[j + k], y = a[j + k + i] * roots[i + k];
        a[j + k] = x + y;
        a[j + k + i] = x - y;
      }
    }
  }
}
vector<int> pmul(vector<int> &a, vector<int> &b) {
  int need = a.size() + b.size() - 1, nbase = 0;
  while (1 << nbase < need) {
    ++nbase;
  }
  ensure_base(nbase);
  int size = 1 << nbase;
  if (size > fa.size()) {
    fa.resize(size);
  }
  if (size > fb.size()) {
    fb.resize(size);
  }
  for (int i = 0; i < a.size(); i++) {
    int x = (a[i] % md + md) % md;
    fa[i] = complex_t(x & (1 << 15) - 1, x >> 15);
  }
  for (int i = a.size(); i < size; ++i) {
    fa[i] = complex_t(0, 0);
  }
  dft(fa, size);
  for (int i = 0; i < b.size(); ++i) {
    int x = (b[i] % md + md) % md;
    fb[i] = complex_t(x & (1 << 15) - 1, x >> 15);
  }
  for (int i = b.size(); i < size; ++i) {
    fb[i] = complex_t(0, 0);
  }
  dft(fb, size);
  ld ratio = 0.25 / size;
  complex_t r1(1, 0);
  complex_t r2(0, -1);
  complex_t r3(ratio, 0);
  complex_t r4(0, -ratio);
  complex_t r5(0, 1);
  for (int i = 0; i <= size >> 1; ++i) {
    int j = size - i & size - 1;
    complex_t a1 = (fa[i] + conj(fa[j])) * r1;
    complex_t a2 = (fa[i] - conj(fa[j])) * r2;
    complex_t b1 = (fb[i] + conj(fb[j])) * r3;
    complex_t b2 = (fb[i] - conj(fb[j])) * r4;
    if (i != j) {
      complex_t c1 = (fa[j] + conj(fa[i])) * r1;
      complex_t c2 = (fa[j] - conj(fa[i])) * r2;
      complex_t d1 = (fb[j] + conj(fb[i])) * r3;
      complex_t d2 = (fb[j] - conj(fb[i])) * r4;
      fa[i] = c1 * d1 + c2 * d2 * r5;
      fb[i] = c1 * d2 + c2 * d1;
    }
    fa[j] = a1 * b1 + a2 * b2 * r5;
    fb[j] = a1 * b2 + a2 * b1;
  }
  dft(fa, size);
  dft(fb, size);
  vector<int> c(need);
  for (int i = 0; i < need; i++) {
    long long aa = fa[i].x + 0.5;
    long long bb = fb[i].x + 0.5;
    long long cc = fa[i].y + 0.5;
    c[i] = (aa + (bb % md << 15) + (cc % md << 30)) % md;
  }
  return c;
}
}

using fft::pmul;

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  int n, m, c;
  cin >> n >> m >> c;
  vector<int> a(md - 1), b(md - 1);
  for (int i = 0; i < n; ++i) {
    int index = (long long)i * i % (md - 1), value;
    cin >> value;
    a[index] = add(a[index], value);
  }
  for (int i = 0; i < m; ++i) {
    int index = (long long)i * i * i % (md - 1), value;
    cin >> value;
    b[index] = add(b[index], value);
  }
  vector<int> inv(md);
  inv[0] = inv[1] = 1;
  for (int i = 2; i < md; ++i) {
    inv[i] = mul(md - md / i, inv[md % i]);
  }
  vector<int> power(md - 1);
  power[0] = 1;
  for (int i = 1; i < md - 1; ++i) {
    power[i] = mul(power[i - 1], c);
  }
  int answer = 0;
  {
    vector<int> f(md - 1), g(md - 1);
    for (int i = 0; i < md - 1; ++i) {
      f[i] = mul(a[i], inv[power[((long long)i * i >> 1) % (md - 1)]]);
      g[i] = mul(b[i], inv[power[((long long)i * i >> 1) % (md - 1)]]);
      if (i & 1) {
        g[i] = mul(g[i], inv[c]);
      }
    }
    vector<int> h = pmul(f, g);
    for (int i = 0; i < h.size(); ++i) {
      if (!(i & 1)) {
        answer = add(answer, mul(h[i], power[((long long)i * i >> 1) % (md - 1)]));
      }
    }
  }
  {
    vector<int> f(md - 1), g(md - 1);
    for (int i = 0; i < md - 1; ++i) {
      f[i] = mul(a[i], inv[power[((long long)i * i >> 1) % (md - 1)]]);
      g[i] = mul(b[i], inv[power[((long long)i * i >> 1) % (md - 1)]]);
    }
    vector<int> h = pmul(f, g);
    for (int i = 0; i < h.size(); ++i) {
      if (i & 1) {
        answer = add(answer, mul(h[i], power[((long long)i * i >> 1) % (md - 1)]));
      }
    }
  }
  cout << answer << endl;
  return 0;
}