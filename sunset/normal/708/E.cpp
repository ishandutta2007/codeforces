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
  int n, m, t;
  num a, b;
  cin >> n >> m >> a >> b >> t;
  vector<num> fact(t + 1);
  fact[0] = 1;
  for (int i = 1; i <= t; ++i) {
    fact[i] = fact[i - 1] * i;
  }
  num p = a / b;
  vector<num> prob(m);
  for (int i = 0; i < m && i <= t; ++i) {
    prob[i] = power(p, i) * power(-p + 1, t - i) * fact[t] / (fact[i] * fact[t - i]);
  }
  vector<num> dpl(m + 1), suml(m + 1);
  vector<num> dpr(m + 1), sumr(m + 1);
  dpl[0] = suml[0] = 1;
  dpr[m] = sumr[m] = 1;
  while (n--) {
    vector<num> new_dpl(m + 1), new_suml(m + 1);
    vector<num> new_dpr(m + 1), new_sumr(m + 1);
    {
      num sum_prob = prob[0];
      num sum_prod = 0;
      for (int l = m - 1; ~l; --l) {
        new_dpl[l] = prob[l] * (sum_prob * (sumr[m] - sumr[l]) - sum_prod);
        new_suml[l] = new_dpl[l] + new_suml[l + 1];
        sum_prob += prob[m - l];
        sum_prod += prob[m - l] * suml[l];
      }
    }
    {
      num sum_prob = prob[0];
      num sum_prod = 0;
      for (int r = 1; r <= m; ++r) {
        new_dpr[r] = prob[m - r] * (sum_prob * (suml[0] - suml[r]) - sum_prod);
        new_sumr[r] = new_dpr[r] + new_sumr[r - 1];
        sum_prob += prob[r];
        sum_prod += prob[r] * sumr[r];
      }
    }
    swap(dpl, new_dpl); swap(suml, new_suml);
    swap(dpr, new_dpr); swap(sumr, new_sumr);
  }
  cout << sumr[m] << "\n";
  return 0;
}