#include <bits/stdc++.h>

using namespace std;

struct my_map {
  vector<long long> a;
  int n, m;

  my_map(int n):n(n) {
    a.resize(n);
    m = 0;
  }

  void insert(long long x) {
    a[m++] = x;
    if (m == n) {
      sort(a.begin(), a.end());
    }
  }

  int count(long long x) {
    return upper_bound(a.begin(), a.end(), x) - lower_bound(a.begin(), a.end(), x);
  }
};

long long slope(pair<int, int> p, pair<int, int> q) {
  int x = p.first - q.first, y = p.second - q.second;
  if (x < 0 || (!x && y < 0)) {
    x = -x;
    y = -y;
  }
  int gcd = abs(__gcd(x, y));
  x /= gcd;
  y /= gcd;
  return ((long long)x << 30) + y;
}

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  int n;
  cin >> n;
  n <<= 1;
  vector<pair<int, int>> p(n);
  for (int i = 0; i < n; ++i) {
    cin >> p[i].first >> p[i].second;
  }
  random_shuffle(p.begin(), p.end());
  vector<my_map> s(n, n - 1);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < i; ++j) {
      long long value = slope(p[i], p[j]);
      s[i].insert(value);
      s[j].insert(value);
    }
  }

  vector<pair<int, int>> points = p;
  sort(points.begin(), points.end());
  
  auto check = [&](pair<int, int> q) {
    for (int i = 0; i < n; ++i) {
      if (s[i].count(slope(p[i], q)) != 1) {
        return;
      }
    }
    puts("Yes");
    printf("%d %d\n", q.first, q.second);
    exit(0);
  };

  auto solve = [&](pair<int, int> a, pair<int, int> b, pair<int, int> c, pair<int, int> d) {
    long long u = (long long)(a.first - c.first) * (d.second - c.second) - (long long)(a.second - c.second) * (d.first - c.first);
    long long v = (long long)(d.first - c.first) * (b.second - c.second) - (long long)(d.second - c.second) * (b.first - c.first);
    if (u + v == 0) {
      return;
    }
    long long x = a.first * v + b.first * u;
    long long y = a.second * v + b.second * u;
    if (x % (u + v) || y % (u + v)) {
      return;
    }
    x /= (u + v);
    y /= (u + v);
    if (abs(x) > 1000000 || abs(y) > 1000000) {
      return;
    }
    int t = lower_bound(points.begin(), points.end(), make_pair((int)x, (int)y)) - points.begin();
    if (t != points.size() && points[t] == make_pair((int)x, (int)y)) {
      return;
    }
    check(make_pair(x, y));
  };

  for (int i = 2; i < n; ++i) {
    for (int j = 2; j < n; ++j) {
      if (i != j) {
        solve(p[0], p[i], p[1], p[j]);
        if (i < j) {
          solve(p[0], p[1], p[i], p[j]);
        }
      }
    }
  }
  puts("No");
  return 0;
}