#include <iostream>
#include <iomanip>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <cassert>
#include <cmath>

using namespace std;
typedef long long ll;
const long long MAXN = 200100;

namespace fft {
  typedef long double dbl;

  struct num {
    dbl x, y;
    num() { x = y = 0; }
    num(dbl x, dbl y) : x(x), y(y) { }
  };

  inline num operator+(num a, num b) { return num(a.x + b.x, a.y + b.y); }
  inline num operator-(num a, num b) { return num(a.x - b.x, a.y - b.y); }
  inline num operator*(num a, num b) { return num(a.x * b.x - a.y * b.y, a.x * b.y + a.y * b.x); }
  inline num conj(num a) { return num(a.x, -a.y); }

  long long base = 1;
  vector<num> roots = {{0, 0}, {1, 0}};
  vector<long long> rev = {0, 1};

  const dbl PI = acosl(-1.0);

  void ensure_base(long long nbase) {
    if (nbase <= base) {
      return;
    }
    rev.resize(1 << nbase);
    for (long long i = 0; i < (1 << nbase); i++) {
      rev[i] = (rev[i >> 1] >> 1) + ((i & 1) << (nbase - 1));
    }
    roots.resize(1 << nbase);
    while (base < nbase) {
      dbl angle = 2 * PI / (1 << (base + 1));
//      num z(cos(angle), sin(angle));
      for (long long i = 1 << (base - 1); i < (1 << base); i++) {
        roots[i << 1] = roots[i];
//        roots[(i << 1) + 1] = roots[i] * z;
        dbl angle_i = angle * (2 * i + 1 - (1 << base));
        roots[(i << 1) + 1] = num(cos(angle_i), sin(angle_i));
      }
      base++;
    }
  }

  void fft(vector<num> &a, long long n = -1) {
    if (n == -1) {
      n = a.size();
    }
    assert((n & (n - 1)) == 0);
    long long zeros = __builtin_ctz(n);
    ensure_base(zeros);
    long long shift = base - zeros;
    for (long long i = 0; i < n; i++) {
      if (i < (rev[i] >> shift)) {
        swap(a[i], a[rev[i] >> shift]);
      }
    }
    for (long long k = 1; k < n; k <<= 1) {
      for (long long i = 0; i < n; i += 2 * k) {
        for (long long j = 0; j < k; j++) {
          num z = a[i + j + k] * roots[j + k];
          a[i + j + k] = a[i + j] - z;
          a[i + j] = a[i + j] + z;
        }
      }
    }
/*    for (long long len = 1; len < n; len <<= 1) {
      for (long long i = 0; i < n; i += 2 * len) {
        for (long long j = i, k = i + len; j < i + len; j++, k++) {
          num z = a[k] * roots[k - i];
          a[k] = a[j] - z;
          a[j] = a[j] + z;
        }
      }
    }*/
  }

  vector<num> fa, fb;

  vector<long long> multiply(vector<long long> &a, vector<long long> &b) {
    long long need = a.size() + b.size() - 1;
    long long nbase = 0;
    while ((1 << nbase) < need) nbase++;
    ensure_base(nbase);
    long long sz = 1 << nbase;
    if (sz > (long long) fa.size()) {
      fa.resize(sz);
    }
    for (long long i = 0; i < sz; i++) {
      long long x = (i < (long long) a.size() ? a[i] : 0);
      long long y = (i < (long long) b.size() ? b[i] : 0);
      fa[i] = num(x, y);
    }
    fft(fa, sz);
    num r(0, -0.25 / sz);
    for (long long i = 0; i <= (sz >> 1); i++) {
      long long j = (sz - i) & (sz - 1);
      num z = (fa[j] * fa[j] - conj(fa[i] * fa[i])) * r;
      if (i != j) {
        fa[j] = (fa[i] * fa[i] - conj(fa[j] * fa[j])) * r;
      }
      fa[i] = z;
    }
    fft(fa, sz);
    vector<long long> res(need);
    for (long long i = 0; i < need; i++) {
      res[i] = fa[i].x + 0.5;
    }
    return res;
  }

  vector<long long> multiply_mod(vector<long long> &a, vector<long long> &b, long long m, long long eq = 0) {
    long long need = a.size() + b.size() - 1;
    long long nbase = 0;
    while ((1 << nbase) < need) nbase++;
    ensure_base(nbase);
    long long sz = 1 << nbase;
    if (sz > (long long) fa.size()) {
      fa.resize(sz);
    }
    for (long long i = 0; i < (long long) a.size(); i++) {
      long long x = (a[i] % m + m) % m;
      fa[i] = num(x & ((1 << 15) - 1), x >> 15);
    }
    fill(fa.begin() + a.size(), fa.begin() + sz, num {0, 0});
    fft(fa, sz);
    if (sz > (long long) fb.size()) {
      fb.resize(sz);
    }
    if (eq) {
      copy(fa.begin(), fa.begin() + sz, fb.begin());
    } else {
      for (long long i = 0; i < (long long) b.size(); i++) {
        long long x = (b[i] % m + m) % m;
        fb[i] = num(x & ((1 << 15) - 1), x >> 15);
      }
      fill(fb.begin() + b.size(), fb.begin() + sz, num {0, 0});
      fft(fb, sz);
    }
    dbl ratio = 0.25 / sz;
    num r2(0, -1);
    num r3(ratio, 0);
    num r4(0, -ratio);
    num r5(0, 1);
    for (long long i = 0; i <= (sz >> 1); i++) {
      long long j = (sz - i) & (sz - 1);
      num a1 = (fa[i] + conj(fa[j]));
      num a2 = (fa[i] - conj(fa[j])) * r2;
      num b1 = (fb[i] + conj(fb[j])) * r3;
      num b2 = (fb[i] - conj(fb[j])) * r4;
      if (i != j) {
        num c1 = (fa[j] + conj(fa[i]));
        num c2 = (fa[j] - conj(fa[i])) * r2;
        num d1 = (fb[j] + conj(fb[i])) * r3;
        num d2 = (fb[j] - conj(fb[i])) * r4;
        fa[i] = c1 * d1 + c2 * d2 * r5;
        fb[i] = c1 * d2 + c2 * d1;
      }
      fa[j] = a1 * b1 + a2 * b2 * r5;
      fb[j] = a1 * b2 + a2 * b1;
    }
    fft(fa, sz);
    fft(fb, sz);
    vector<long long> res(need);
    for (long long i = 0; i < need; i++) {
      long long aa = fa[i].x + 0.5;
      long long bb = fb[i].x + 0.5;
      long long cc = fa[i].y + 0.5;
      res[i] = (aa + ((bb % m) << 15) + ((cc % m) << 30)) % m;
    }
    return res;
  }

  vector<long long> square_mod(vector<long long> &a, long long m) {
    return multiply_mod(a, a, m, 1);
  }
};

long long N, X;
long long arr[MAXN];
long long nps[MAXN];
vector <long long> l, r;
ll ans[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> N >> X;
    for (long long i = 0; i < N; i++)
    {
        long long t; cin >> t;
        if (t < X)
            arr[i] = 1;
        else
            arr[i] = 0;
    }

    for (long long i = 0; i < MAXN; i++)
        nps[i] = 0;
    nps[0] = 1;

    long long csum = 0;
    for (long long i = 0; i < N; i++)
    {
        csum += arr[i];
        nps[csum]++;
    }

    for (long long i = 0; i <= N; i++)
        l.push_back(nps[i]);
    for (long long i = N; i >= 0; i--)
        r.push_back(nps[i]);

    vector <long long> res = fft::multiply(l, r);
    for (long long i = 1; i <= N; i++)
        ans[i] = res[i+N];

    ans[0] = 0;
    for (long long i = 0; i <= N; i++)
    {
        ll x = nps[i];
        ans[0] += x * (x - 1) / 2;
    }
    for (long long i = 0; i <= N; i++)
    {
        if (i) cout << " ";
        cout << ans[i];
    }
    cout << "\n";
}