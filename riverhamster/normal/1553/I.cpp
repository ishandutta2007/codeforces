#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <numeric>
#include <vector>
#include <cassert>
#include <string>
#include <sstream>
#include <array>
using namespace std;

#define LOG(f...) fprintf(stderr, f)
#define all(cont) begin(cont), end(cont)

using ll = long long;
using ull = unsigned long long;

template<class T> void read(T &x) {
  char ch; x = 0;
  int f = 1;
  while (isspace(ch = getchar()));
  if (ch == '-') ch = getchar(), f = -1;
  do x = x * 10 + (ch - '0'); while(isdigit(ch = getchar()));
  x *= f;
}
template<class T, class ...A> void read(T &x, A&... args) { read(x); read(args...); }

template<class T>
string to_string(const vector<T> &v) {
  ostringstream s;
  s << "{";
  for (auto it = cbegin(v); it != cend(v); ++it) {
    s << *it;
    if (next(it) != cend(v)) s << ", ";
  }
  s << "}";
  return s.str();
}

const int M = 998244353;

void reduceR(int &x) { x += M & (x >> 31); }
int reduceN(int x) { return x + (M & (x >> 31)); }
int add(int x, int y) { return reduceN(x + y - M); }
int sub(int x, int y) { return reduceN(x - y); }
void inc(int &x, int y) { reduceR(x += y - M); }
void dec(int &x, int y) { reduceR(x -= y); }
int power(int x, int y) {
  int p = 1;
  for (; y; y >>= 1, x = (ll)x * x % M)
    if (y & 1) p = (ll)p * x % M;
  return p;
}
int inv(int x) { return power(x, M - 2); }

namespace poly {
  const int N = 1 << 19;

  int A[N], B[N], w[N], rev[N];
  int last = -1;

  void poly_init() {
    for (int i = 2; i <= N; i <<= 1) {
      int *w = poly::w + N - i;
      w[0] = 1; w[1] = power(3, (M - 1) / i);
      for (int j = 2, li = i / 2; j < li; ++j)
        w[j] = (ll)w[j - 1] * w[1] % M;
    }
  }
  void gen_binrev(int n) {
    if (last == n) return;
    last = n;
    int s = __builtin_ctz(n) - 1;
    for (int i = 1; i < n; ++i)
      rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << s);
  }


  void DFT(const int *src, int s_len, int *dst, int n) {
    gen_binrev(n);
    static ull a[N];
    memset(a, 0, sizeof(ull) * n);
    for (int i = 0; i < s_len; ++i)
      a[rev[i]] = src[i];
    ull *i, *t1 = a + n;
    for (ull *p = a, *t = a + n; p != t; p += 2) {
      *p += p[1];
      p[1] = *p - (p[1] << 1) + M;
    }
    for (int l = 4, k = 2; k < n; l <<= 1, k <<= 1) {
      int *W = w + N - l;
      for (i = a; i != t1; i += l) {
        ull *q = i + k;
        for (int j = 0; j < k; ++j) {
          ull tp = q[j] * W[j] % M;
          q[j] = i[j] - tp + M;
          i[j] += tp;
        }
      }
    }
    for (int i = 0; i < n; ++i)
      dst[i] = a[i] % M;
  }
  void IDFT(int *a, int n) {
    DFT(a, n, a, n);
    reverse(a + 1, a + n);
    int in = inv(n);
    for (int i = 0; i < n; ++i)
      a[i] = (ll)a[i] * in % M;
  }

  void dot(int *a, int *b, int n) {
    if (n < 16) {
      for (int i = 0; i < n; ++i)
        a[i] = (ll)a[i] * b[i] % M;
      return;
    }
  #define E(I) a[I] = (ull)a[I] * b[I] % M
    for (int *t = a + n; a != t; a += 16, b += 16) {
      E(0); E(1); E(2); E(3); E(4); E(5); E(6); E(7);
      E(8); E(9); E(10); E(11); E(12); E(13); E(14); E(15);
    }
  #undef E
  }

  int length(int n) {
    return n & (n - 1) ? 1 << (__lg(n) + 1) : n;
  }
}

vector<int> operator+(const vector<int> &a, const vector<int> &b) {
  vector<int> c(max(a.size(), b.size()));
  copy(all(a), begin(c));
  for (size_t i = 0; i < b.size(); ++i)
    inc(c[i], b[i]);
  return c;
}

void operator+=(vector<int> &a, const vector<int> &b) {
  a.resize(max(a.size(), b.size()));
  for (int i = 0, li = b.size(); i < li; ++i)
    inc(a[i], b[i]);
}

vector<int> operator*(const vector<int> &a, const vector<int> &b) {
  if (a.empty() || b.empty()) return vector<int>();
  using namespace poly;
  int L = length(a.size() + b.size() - 1);
  DFT(a.data(), a.size(), A, L);
  DFT(b.data(), b.size(), B, L);
  dot(A, B, L);
  IDFT(A, L);
  return vector<int>(A, A + a.size() + b.size() - 1);
}

vector<int> fac, ifac;

void prefac(int n) {
  fac.resize(n + 1); ifac.resize(n + 1);
  fac[0] = 1;
  for (int i = 1; i <= n; ++i)
    fac[i] = (ll)fac[i - 1] * i % M;
  ifac[n] = inv(fac[n]);
  for (int i = n; i; --i)
    ifac[i - 1] = (ll)ifac[i] * i % M;
}

const int N = 100005;

int a[N];

using mat = array<array<vector<int>, 3>, 3>;

mat solve(vector<int>::const_iterator l, vector<int>::const_iterator r) {
  if (r - l <= 3) {
    using vi = vector<int>;
    int n = r - l;
    mat res;
    int U = (1 << (n - 1)) - 1;
    for (int s = 0; s < U + (n == 1); ++s) {
      int sum1 = 0;
      for (int i = 0; ; ++i) {
        sum1 += l[i];
        if ((~s >> i) & 1) break;
      }
      int sum2 = 0;
      for (int i = n - 1; ; --i) {
        sum2 += l[i];
        if (!i || ((~s >> (i - 1)) & 1)) break;
      }
      vi L = sum1 == 1 ? vi{0} : vi{1, 2};
      vi R = sum2 == 1 ? vi{0} : vi{1, 2};
      int val = 1 + (n == 3 && !s && l[1] == 2);
      size_t cnt = n - __builtin_popcount(s);
      for (int p : L)
        for (int q : R) {
          res[p][q].resize(max(res[p][q].size(), cnt + 1));
          res[p][q][cnt] += val;
        }
    }
    if (n > 1) {
      res[1][1].resize(max<size_t>(res[1][1].size(), 2ul)); res[2][2].resize(max<size_t>(res[2][2].size(), 2ul));
      ++res[1][1][1];
      ++res[2][2][1];
    }
    return res;
  }
  vector<int>::const_iterator mid = l + (r - l) / 2;
  mat L = solve(l, mid), R = solve(mid, r);
  vector<int> SL[3], SR[3];
  for (int i = 0; i < 3; ++i)
    for (int j = 0; j < 3; ++j)
      SL[i] += L[i][j];
  for (int i = 0; i < 3; ++i)
    for (int j = 0; j < 3; ++j)
      SR[j] += R[i][j];
  mat res;
  for (int i = 0; i < 3; ++i)
    for (int j = 0; j < 3; ++j) {
      res[i][j] = (L[i][0] + L[i][1]) * (R[0][j] + R[1][j]);
      res[i][j] += (L[i][0] + L[i][2]) * (R[0][j] + R[2][j]);
    }
  for (int i = 0; i < 3; ++i)
    for (int j = 0; j < 3; ++j)
      if (!res[i][j].empty()) {
        res[i][j].erase(begin(res[i][j]));
      }
  for (int i = 0; i < 3; ++i)
    for (int j = 0; j < 3; ++j)
      res[i][j] += SL[i] * SR[j];
  return res;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  poly::poly_init();
  int n;
  read(n);
  vector<int> c;
  int cnt = 0;
  for (int i = 1; i <= n; ++i) {
    read(a[i]);
    if (!cnt) c.push_back(a[i]), cnt = a[i] - 1;
    else {
      if (a[i] != a[i - 1]) {
        puts("0");
        return 0;
      }
      --cnt;
    }
  }
  auto R = solve(all(c));
  vector<int> res;
  for (int i = 0; i < 3; ++i)
    for (int j = 0; j < 3; ++j)
      res = res + R[i][j];
  prefac(n);
  int s = 0;
  for (int i = 1, li = res.size(); i < li; ++i)
    s = (s + (ll)fac[i] * res[i] * ((c.size() - i) & 1 ? -1 : 1)) % M;
  printf("%d\n", reduceN(s));
  return 0;
}