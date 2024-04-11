#include <bits/stdc++.h>

using namespace std;

template <typename T>
T power(T a, long long b) {
  T r = 1;
  while (b) {
    if (b & 1) {
      r *= a;
    }
    a *= a;
    b >>= 1;
  }
  return r;
}

int inverse(int a, int m) {
  a %= m;
  if (a < 0) {
    a += m;
  }
  int b = m, u = 0, v = 1;
  while (a) {
    int t = b / a;
    b -= a * t;
    swap(a, b);
    u -= v * t;
    swap(u, v);
  }
  if (u < 0) {
    u += m;
  }
  return u;
}

template <int _P>
struct modnum {
  static constexpr int P = _P;

 private:
  int v;

 public:
  modnum() : v(0) {
  }

  modnum(long long _v) {
    v = _v % P;
    if (v < 0) {
      v += P;
    }
  }

  explicit operator int() const {
    return v;
  }

  bool operator==(const modnum& o) const {
    return v == o.v;
  }

  bool operator!=(const modnum& o) const {
    return v != o.v;
  }

  modnum inverse() const {
    return modnum(::inverse(v, P));
  }

  modnum operator-() const {
    return modnum(v ? P - v : 0);
  }
  
  modnum operator+() const {
    return *this;
  }

  modnum& operator++() {
    v++;
    if (v == P) {
      v = 0;
    }
    return *this;
  }
  
  modnum& operator--() {
    if (v == 0) {
      v = P;
    }
    v--;
    return *this;
  }

  modnum operator++(int) {
    modnum r = *this;
    ++*this;
    return r;
  }
  
  modnum operator--(int) {
    modnum r = *this;
    --*this;
    return r;
  }

  modnum& operator+=(const modnum& o) {
    v += o.v;
    if (v >= P) {
      v -= P;
    }
    return *this;
  }

  modnum operator+(const modnum& o) const {
    return modnum(*this) += o;
  }

  modnum& operator-=(const modnum& o) {
    v -= o.v;
    if (v < 0) {
      v += P;
    }
    return *this;
  }

  modnum operator-(const modnum& o) const {
    return modnum(*this) -= o;
  }

  modnum& operator*=(const modnum& o) {
    v = (int) ((long long) v * o.v % P);
    return *this;
  }

  modnum operator*(const modnum& o) const {
    return modnum(*this) *= o;
  }
  
  modnum& operator/=(const modnum& o) {
    return *this *= o.inverse();
  }

  modnum operator/(const modnum& o) const {
    return modnum(*this) /= o;
  }
};

template <int _P>
ostream& operator<<(ostream& out, const modnum<_P>& n) {
  return out << int(n);
}

template <int _P>
istream& operator>>(istream& in, modnum<_P>& n) {
  long long _v;
  in >> _v;
  n = modnum<_P>(_v);
  return in;
}

using num = modnum<998244353>;

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m, q;
  cin >> n >> m >> q;
  vector<bool> r(n);
  vector<bool> c(m);
  for (int i = 0; i < q * 2; ++i) {
    int x, y;
    cin >> x >> y;
    r[--x] = true;
    c[--y] = true;
  }
  vector<vector<num>> f(n + 1, vector<num>(n + 1));
  f[0][0] = 1;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j <= i; ++j) {
      if (f[i][j] != 0) {
        f[i + 1][j] += f[i][j];
        if (i && !r[i] && !r[i - 1]) {
          f[i + 1][j + 1] += f[i - 1][j];
        }
      }
    }
  }
  vector<vector<num>> g(m + 1, vector<num>(m + 1));
  g[0][0] = 1;
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j <= i; ++j) {
      if (g[i][j] != 0) {
        g[i + 1][j] += g[i][j];
        if (i && !c[i] && !c[i - 1]) {
          g[i + 1][j + 1] += g[i - 1][j];
        }
      }
    }
  }
  int row = 0;
  for (int i = 0; i < n; ++i) {
    if (!r[i]) {
      ++row;
    }
  }
  int col = 0;
  for (int i = 0; i < m; ++i) {
    if (!c[i]) {
      ++col;
    }
  }
  int k = max(n, m);
  vector<num> fact(k + 1);
  fact[0] = 1;
  for (int i = 1; i <= k; ++i) {
    fact[i] = fact[i - 1] * i;
  }
  vector<vector<num>> binom(k + 1, vector<num>(k + 1));
  for (int i = 0; i <= k; ++i) {
    binom[i][0] = 1;
    for (int j = 1; j <= i; ++j) {
      binom[i][j] = binom[i - 1][j] + binom[i - 1][j - 1];
    }
  }
  num ans = 0;
  for (int i = 0; i <= n; ++i) {
    if (f[n][i] != 0) {
      for (int j = 0; j <= m; ++j) {
        if (g[m][j] != 0) {
          ans += f[n][i] * g[m][j] * binom[col - j * 2][i] * binom[row - i * 2][j] * fact[i] * fact[j];
        }
      }
    }
  }
  cout << ans << "\n";
  return 0;
}