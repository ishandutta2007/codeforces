#include <bits/stdc++.h>

// https://qiita.com/drken/items/b97ff231e43bce50199a
// : a  b 
// ax + by = gcd(a, b)  (x, y) 
long long extGCD(long long a, long long b, long long& x, long long& y) {
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  }
  long long d = extGCD(b, a % b, y, x);
  y -= a / b * x;
  return d;
}

using namespace std::literals;

using i64 = long long;

i64 div_floor(i64 x, i64 y) { return x / y - ((x ^ y) < 0 && x % y); }

void solve(std::istream& is, std::ostream& os) {
  int n;
  is >> n;

  std::vector<int> red(n);
  std::vector<int> black(n);
  for (int i = 0; i < n; ++i) {
    is >> red[i] >> black[i];
  }

  std::vector<int> order(n);
  std::iota(order.begin(), order.end(), 0);
  std::sort(order.begin(), order.end(), [&](int i, int j) {
    return red[i] - black[i] < red[j] - black[j];
  });

  std::vector<i64> f(n + 1);
  f[0] = std::accumulate(red.begin(), red.end(), 0ll);
  for (int z = 0; z < n; ++z) {
    int i = order[z];
    f[z + 1] = f[z];
    f[z + 1] -= red[i];
    f[z + 1] += black[i];
  }

  int L = int(std::max_element(f.begin(), f.end()) - f.begin());
  int R = L;
  while (R < n && f[L] == f[R + 1]) {
    ++R;
  }

  int q;
  is >> q;

  while (q--) {
    i64 a, b;
    is >> a >> b;

    i64 x;
    i64 y;
    i64 g = extGCD(a, b, x, y);

    if (n % g) {
      os << "-1\n";
      continue;
    }

    i64 k_min = -div_floor(n * x, b);
    i64 k_max = div_floor(n * y, a);

    if (k_max < k_min) {
      os << "-1\n";
      continue;
    }

    i64 l = b * ((n * y - k_max * a) / g);
    i64 r = b * ((n * y - k_min * a) / g);
    i64 s = b * (a / g);

    l -= s;
    r += s;
    while (l + s < r - s) {
      i64 ml = l + ((r - l) >> 1) / s * s;
      i64 mr = ml + s;
      if (f[ml] < f[mr]) {
        l = ml;
      } else {
        r = mr;
      }
    }

    os << f[l + s] << '\n';
  }
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  solve(std::cin, std::cout);
}