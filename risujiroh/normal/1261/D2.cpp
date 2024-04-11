#include <bits/stdc++.h>
using namespace std;

constexpr int P = 998244353;
struct Mint {
  int v;
  Mint(long long a = 0) : v((a %= P) < 0 ? a + P : a) {}
  Mint& operator*=(Mint r) { v = (long long)v * r.v % P; return *this; }
  Mint& operator/=(Mint r) { return *this *= r.inv(); }
  Mint& operator+=(Mint r) { if ((v += r.v) >= P) v -= P; return *this; }
  Mint& operator-=(Mint r) { if ((v -= r.v) < 0) v += P; return *this; }
  friend Mint operator*(Mint l, Mint r) { return l *= r; }
  friend Mint operator/(Mint l, Mint r) { return l /= r; }
  friend Mint operator+(Mint l, Mint r) { return l += r; }
  friend Mint operator-(Mint l, Mint r) { return l -= r; }
  Mint pow(long long n) const {
    Mint res = 1, t = *this;
    while (n) {
      if (n & 1) res *= t;
      t *= t;
      n >>= 1;
    }
    return res;
  }
  Mint inv() const { return pow(P - 2); }
};

const Mint G = [&] {
  Mint x = 1;
  while (true) {
    if (x.pow((P - 1) / 2).v != 1) {
      return x;
    }
    ++x.v;
  }
}();
void ntt(vector<Mint>& a, bool inv = false) {
  int n = a.size();
  for (int i = 1, j = 0; i < n; ++i) {
    int w = n >> 1;
    while (j >= w) {
      j -= w;
      w >>= 1;
    }
    j += w;
    if (i < j) {
      swap(a[i], a[j]);
    }
  }
  for (int w = 1; w < n; w *= 2) {
    Mint dt = G.pow((P - 1) / (2 * w));
    if (inv) {
      dt = dt.inv();
    }
    for (int s = 0; s < n; s += 2 * w) {
      Mint t = 1;
      for (int i = s, j = s + w; i < s + w; ++i, ++j) {
        Mint x = a[i], y = a[j] * t;
        a[i] = x + y;
        a[j] = x - y;
        t *= dt;
      }
    }
  }
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n, k;
  cin >> n >> k;
  vector<int> h(n);
  for (auto&& e : h) {
    cin >> e;
  }
  h.push_back(h[0]);
  int a = 0;
  for (int i = 0; i < n; ++i) {
    a += h[i] == h[i + 1];
  }
  int b = n - a;
  int sz = 2 * n + 1;
  sz = 1 << __lg(2 * sz - 1);
  vector<Mint> f(sz), g(sz);
  f[1] = k;
  g[0] = 1, g[1] = k - 2, g[2] = 1;
  ntt(f), ntt(g);
  for (int i = 0; i < sz; ++i) {
    f[i] = f[i].pow(a) * g[i].pow(b);
  }
  ntt(f, true);
  Mint res = accumulate(begin(f) + n + 1, end(f), Mint(0));
  res /= sz;
  cout << res.v << '\n';
}