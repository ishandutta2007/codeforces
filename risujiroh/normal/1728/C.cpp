#include <bits/stdc++.h>

using namespace std::literals;

using i64 = long long;

void solve(std::istream& is, std::ostream& os) {
  int n;
  is >> n;

  std::priority_queue<int> a;
  for (int _ = n; _--;) {
    int t;
    is >> t;
    a.push(t);
  }

  std::priority_queue<int> b;
  for (int _ = n; _--;) {
    int t;
    is >> t;
    b.push(t);
  }

  auto f = [&](int x) {
    int ret = 1;
    int y = 10;
    while (y <= x) {
      y *= 10;
      ++ret;
    }
    return ret;
  };

  int ans = 0;
  while (!a.empty()) {
    int x = a.top();
    a.pop();
    int y = b.top();
    b.pop();
    if (x < y) {
      ++ans;
      a.push(x);
      b.push(f(y));
    } else if (y < x) {
      ++ans;
      a.push(f(x));
      b.push(y);
    }
  }

  os << ans << '\n';
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int T;
  std::cin >> T;

  while (T--) {
    solve(std::cin, std::cout);
  }
}