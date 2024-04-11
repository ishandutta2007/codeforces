#include <bits/stdc++.h>

using namespace std;

const int N = 2097155;
const double pi = acos(-1);

struct complex_t {
  double x, y;

  complex_t(double x = 0, double y = 0):x(x), y(y) {
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
} fft_i[N], fft_w[N], fft_x[N];

int n, m, fft_l, fft_n, fft_r[N];

void init(int n) {
  for (fft_n = 1, fft_l = 0; fft_n < n; fft_n <<= 1, ++fft_l);
  for (int i = 0; i < fft_n; ++i) {
    fft_w[i] = complex_t(cos(2 * pi * i / fft_n), sin(2 * pi * i / fft_n));
    fft_i[i] = complex_t(fft_w[i].x, -fft_w[i].y);
    fft_r[i] = fft_r[i >> 1] >> 1 | (i & 1) << fft_l - 1;
  }
}

void dft(complex_t *x, complex_t *w) {
  for (int i = 0; i < fft_n; ++i) {
    if (i < fft_r[i]) {
      swap(x[i], x[fft_r[i]]);
    }
  }
  for (int i = 1; i < fft_n; i <<= 1) {
    for (int j = 0; j < fft_n; j += i << 1) {
      for (int k = 0; k < i; ++k) {
        complex_t u = x[j + k], v = x[j + k + i] * w[fft_n / (i << 1) * k];
        x[j + k] = u + v;
        x[j + k + i] = u - v;
      }
    }
  }
}

vector<int> sqr(vector<int> a) {
  int n = a.size();
  init((n << 1) - 1);
  for (int i = 0; i < fft_n; ++i) {
    fft_x[i] = i < n ? complex_t(a[i], 0) : complex_t(0, 0);
  }
  dft(fft_x, fft_w);
  for (int i = 0; i < fft_n; ++i) {
    fft_x[i] = fft_x[i] * fft_x[i];
  }
  dft(fft_x, fft_i);
  vector<int> c(n + m - 1);
  for (int i = 0; i < n + m - 1; ++i) {
    c[i] = fft_x[i].x / fft_n + 0.5;
  }
  return c;
}

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  scanf("%d %d", &n, &m);
  vector<int> a(m + 1, 0);
  for (int i = 1; i <= n; ++i) {
    int x;
    scanf("%d", &x);
    ++a[x];
  }
  vector<int> b = sqr(a), answer;
  for (int i = 1; i <= m; ++i) {
    if (b[i] && !a[i]) {
      puts("NO");
      return 0;
    } else if (a[i] && !b[i]) {
      answer.push_back(i);
    }
  }
  puts("YES");
  printf("%d\n", answer.size());
  for (int i = 0; i < answer.size(); ++i) {
    printf("%d%c", answer[i], i == answer.size() - 1 ? '\n' : ' ');
  }
  return 0;
}