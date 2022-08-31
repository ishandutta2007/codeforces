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
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  vector<int> primes;
  map<int, int> id;
  int m = 0;
  auto factorize = [&](int x) {
    for (int i = 2; i * i <= x; ++i) {
      if (x % i == 0) {
        if (!id.count(i)) {
          id[i] = m++;
          primes.push_back(i);
        }
        while (x % i == 0) {
          x /= i;
        }
      }
    }
    if (x != 1) {
      if (!id.count(x)) {
        id[x] = m++;
        primes.push_back(x);
      }
    }
  };
  for (int i = 0; i < n; ++i) {
    cin >> a[i] >> b[i];
    factorize(a[i]);
    factorize(b[i]);
  }
  vector<vector<int>> aa(n, vector<int>(m));
  vector<vector<int>> bb(n, vector<int>(m));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      while (a[i] % primes[j] == 0) {
        a[i] /= primes[j];
        aa[i][j]++;
      }
      while (b[i] % primes[j] == 0) {
        b[i] /= primes[j];
        bb[i][j]++;
      }
    }
  }
  auto no_solution = [&]() {
    cout << -1 << "\n";
    exit(0);
  };
  auto check_solution = [&](int who, long long which) {
    vector<long long> already(n, -1);
    num ans = 1;
    for (int j = 0; j < m; ++j) {
      long long e = aa[who][j] + bb[who][j] * which;
      for (int i = 0; i < n; ++i) {
        if (bb[i][j]) {
          if (already[i] == -1) {
            if (e - aa[i][j] < 0 || (e - aa[i][j]) % bb[i][j] != 0) {
              no_solution();
            }
            already[i] = (e - aa[i][j]) / bb[i][j];
          } else if (aa[i][j] + bb[i][j] * already[i] != e) {
            no_solution();
          }
        } else if (aa[i][j] != e) {
          no_solution();
        }
      }
      ans *= power(num(primes[j]), e);
    }
    cout << ans << "\n";
    exit(0);
  };
  vector<bool> done(m);
  for (int j = 0; j < m; ++j) {
    int who = -1;
    for (int i = 0; i < n; ++i) {
      if (!bb[i][j]) {
        who = i;
        break;
      }
    }
    if (who == -1) {
      continue;
    }
    done[j] = true;
    for (int i = 0; i < n; ++i) {
      if (bb[i][j]) {
        if (aa[who][j] - aa[i][j] < 0 || (aa[who][j] - aa[i][j]) % bb[i][j] != 0) {
          no_solution();
        }
        check_solution(i, (aa[who][j] - aa[i][j]) / bb[i][j]);
      } else if (aa[i][j] != aa[who][j]) {
        no_solution();
      }
    }
  }
  int p = -1;
  for (int j = 0; j < m; ++j) {
    if (!done[j]) {
      p = j;
      break;
    }
  }
  if (p == -1) {
    check_solution(0, 0);
  }
  for (int j = p + 1; j < m; ++j) {
    if (!done[j]) {
      for (int i = 1; i < n; ++i) {
        int pp = aa[i][p] - aa[0][p];
        int jj = aa[i][j] - aa[0][j];
        if (bb[0][p] * bb[i][j] != bb[0][j] * bb[i][p]) {
          int num = pp * bb[i][j] - jj * bb[i][p];
          int den = bb[0][p] * bb[i][j] - bb[0][j] * bb[i][p];
          if (num % den != 0 || num / den < 0) {
            no_solution();
          }
          check_solution(0, num / den);
        } else if (pp * bb[0][j] != jj * bb[0][p]) {
          no_solution();
        }
      }
    }
  }
  auto merge = [&](long long m1, long long a1, long long m2, long long a2) {
    long long g = __gcd(m1, m2);
    if ((a2 - a1) % g != 0) {
      no_solution();
    }
    long long m = m1 / g * m2;
    long long a = inverse(m1 / g, m2 / g) * ((a2 - a1) / g) % (m2 / g) * m1 + a1;
    a = (a % m + m) % m;
    return make_pair(m, a);
  };
  long long modular = 1, reminder = 0;
  for (int i = 0; i < n; ++i) {
    tie(modular, reminder) = merge(modular, reminder, bb[i][p], aa[i][p] % bb[i][p]);
  }
  for (int i = 0; i < n; ++i) {
    while (reminder < aa[i][p]) {
      reminder += modular;
    }
  }
  check_solution(0, (reminder - aa[0][p]) / bb[0][p]);
  return 0;
}