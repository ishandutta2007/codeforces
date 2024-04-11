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

using num = modnum<1000000007>;

struct pt {
  int x, y;

  long long operator*(const pt& o) const {
    return (long long) x * o.y - (long long) y * o.x;
  }
};

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<pt> p(n);
  for (int i = 0; i < n; ++i) {
    cin >> p[i].x >> p[i].y;
  }
  reverse(p.begin(), p.end());
  for (int i = 0; i < n; ++i) {
    p.push_back(p[i]);
  }
  long long area = 0;
  for (int i = 0; i < n; ++i) {
    area += p[i] * p[i + 1];
  }
  long long cur = 0;
  long long cnt = 0;
  num sum = 0;
  num ans = 0;
  num x = 0;
  num y = 0;
  for (int i = 0, j = 1; i < n; ++i) {
    while (cur + p[i] * p[j] + p[j] * p[j + 1] + p[j + 1] * p[i] <= area / 2) {
      cur += p[i] * p[j] + p[j] * p[j + 1] + p[j + 1] * p[i];
      sum += cur;
      j++;
      x += p[j].x;
      y += p[j].y;
    }
    cnt += j - i - 1;
    ans += sum;
    sum -= (num) (p[i] * p[i + 1]) * (j - i - 1);
    sum -= (pt) {int(x), int(y)} * p[i];
    sum += (pt) {int(x), int(y)} * p[i + 1];
    cur -= p[i] * p[i + 1] + p[i + 1] * p[j] + p[j] * p[i];
    x -= p[i + 2].x;
    y -= p[i + 2].y;
  }
  cout << (num) area * cnt - ans * 2 << "\n";
  return 0;
}