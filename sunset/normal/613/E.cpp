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

template <typename T>
T inverse(T a, T m) {
  a %= m;
  if (a < 0) {
    a += m;
  }
  T b = m, u = 0, v = 1;
  while (a) {
    T t = b / a;
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

using num = modnum<1000000007>;

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  string a0, a1, s;
  cin >> a0 >> a1 >> s;
  int n = a0.size();
  int m = s.size();
  vector<vector<int>> lcp0(n, vector<int>(m)), lcp1(n, vector<int>(m));
  vector<vector<int>> lcs0(n, vector<int>(m)), lcs1(n, vector<int>(m));
  for (int i = n - 1; ~i; --i) {
    for (int j = m - 1; ~j; --j) {
      if (a0[i] == s[j]) {
        lcp0[i][j] = i == n - 1 || j == m - 1 ? 1 : lcp0[i + 1][j + 1] + 1;
      }
      if (a1[i] == s[j]) {
        lcp1[i][j] = i == n - 1 || j == m - 1 ? 1 : lcp1[i + 1][j + 1] + 1;
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (a0[i] == s[j]) {
        lcs0[i][j] = !i || j == m - 1 ? 1 : lcs0[i - 1][j + 1] + 1;
      }
      if (a1[i] == s[j]) {
        lcs1[i][j] = !i || j == m - 1 ? 1 : lcs1[i - 1][j + 1] + 1;
      }
    }
  }
  num ans = 0;
  auto solve = [&](bool first) {
    vector<num> f0(m + 1), f1(m + 1);
    for (int i = 0; i < n; ++i) {
      f0[0] = f1[0] = 1;
      ans += f0[m] + f1[m];
      for (int j = 1; i + j <= n && j * 2 <= m; ++j) {
        if (j * 2 < m || (first && m > 2)) {
          if (lcp0[i][m - j * 2] >= j && lcs1[i + j - 1][m - j] >= j) {
            ans += f0[m - j * 2];
          }
          if (lcp1[i][m - j * 2] >= j && lcs0[i + j - 1][m - j] >= j) {
            ans += f1[m - j * 2];
          }
        }
      }
      vector<num> g0(m + 1), g1(m + 1);
      for (int j = 0; j < m; ++j) {
        if (a0[i] == s[j]) {
          g0[j + 1] += f0[j];
          if (j && j + 2 < m && a1[i] == s[j + 1]) {
            g1[j + 2] += f0[j];
          }
        }
        if (a1[i] == s[j]) {
          g1[j + 1] += f1[j];
          if (j && j + 2 < m && a0[i] == s[j + 1]) {
            g0[j + 2] += f1[j];
          }
        }
      }
      for (int j = 1; i - j + 1 >= 0 && j * 2 <= m; ++j) {
        if (j * 2 < m || first) {
          if (lcs1[i][0] >= j && lcp0[i - j + 1][j] >= j) {
            g0[j * 2]++;
          }
          if (lcs0[i][0] >= j && lcp1[i - j + 1][j] >= j) {
            g1[j * 2]++;
          }
        }
      }
      swap(f0, g0);
      swap(f1, g1);
    }
    ans += f0[m] + f1[m];
  };
  solve(true);
  if (m > 1) {
    reverse(s.begin(), s.end());
    for (int i = n - 1; ~i; --i) {
      for (int j = m - 1; ~j; --j) {
        if (a0[i] == s[j]) {
          lcp0[i][j] = i == n - 1 || j == m - 1 ? 1 : lcp0[i + 1][j + 1] + 1;
        } else {
          lcp0[i][j] = 0;
        }
        if (a1[i] == s[j]) {
          lcp1[i][j] = i == n - 1 || j == m - 1 ? 1 : lcp1[i + 1][j + 1] + 1;
        } else {
          lcp1[i][j] = 0;
        }
      }
    }
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (a0[i] == s[j]) {
          lcs0[i][j] = !i || j == m - 1 ? 1 : lcs0[i - 1][j + 1] + 1;
        } else {
          lcs0[i][j] = 0;
        }
        if (a1[i] == s[j]) {
          lcs1[i][j] = !i || j == m - 1 ? 1 : lcs1[i - 1][j + 1] + 1;
        } else {
          lcs1[i][j] = 0;
        }
      }
    }
    solve(false);
  }
  cout << ans << "\n";
  return 0;
}