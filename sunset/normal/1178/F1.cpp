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
  int n, m;
  cin >> n >> m;
  vector<int> a;
  for (int i = 0; i < m; ++i) {
    int x;
    cin >> x;
    --x;
    if (a.empty() || a.back() != x) {
      a.push_back(x);
    }
  }
  m = a.size();
  if (m > n * 2 + 1) {
    cout << 0 << "\n";
    return 0;
  }
  vector<int> foo(n, m);
  vector<int> bar(n, -1);
  for (int i = 0; i < m; ++i) {
    foo[a[i]] = min(foo[a[i]], i);
    bar[a[i]] = max(bar[a[i]], i);
  }
  vector<vector<int>> rmq(m, vector<int>(m));
  for (int l = 0; l < m; ++l) {
    rmq[l][l] = a[l];
    for (int r = l + 1; r < m; ++r) {
      rmq[l][r] = min(rmq[l][r - 1], a[r]);
    }
  }
  vector<vector<num>> f(m, vector<num>(m));
  vector<vector<num>> g(m, vector<num>(m));
  for (int len = 0; len < m; ++len) {
    for (int l = 0; l + len < m; ++l) {
      int r = l + len;
      if (foo[rmq[l][r]] >= l && bar[rmq[l][r]] <= r) {
        f[l][r] = 1;
        int last = l - 1;
        for (int k = l; k <= r; ++k) {
          if (a[k] == rmq[l][r]) {
            if (last + 1 <= k - 1) {
              f[l][r] *= g[last + 1][k - 1];
            }
            last = k;
          }
        }
        if (last + 1 <= r) {
          f[l][r] *= g[last + 1][r];
        }
      }
    }
    for (int l = 0; l + len < m; ++l) {
      int r = l + len;
      g[l][r] = f[l][r];
      for (int k = l; k < r; ++k) {
        g[l][r] += f[l][k] * g[k + 1][r];
      }
    }
  }
  cout << g[0][m - 1] << "\n";
  return 0;
}