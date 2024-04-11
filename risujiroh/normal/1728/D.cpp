#include <bits/stdc++.h>

using namespace std::literals;

using i64 = long long;

void solve(std::istream& is, std::ostream& os) {
  std::string s;
  is >> s;

  int n = int(s.size());

  std::vector f(n + 1, std::vector<bool>(n + 1));
  for (int r = 2; r <= n; ++r) {
    for (int l = r; 0 <= (l -= 2);) {
      if (l + 2 == r) {
        f[l][r] = s[l] != s[r - 1];
      } else {
        int ll = f[l + 2][r] ? f[l + 2][r] : s[l + 1] - s[l];
        int lr = f[l + 1][r - 1] ? f[l + 1][r - 1] : s[r - 1] - s[l];
        int rl = f[l + 1][r - 1] ? f[l + 1][r - 1] : s[l] - s[r - 1];
        int rr = f[l][r - 2] ? f[l][r - 2] : s[r - 2] - s[r - 1];
        f[l][r] = std::max(std::min(ll, lr), std::min(rl, rr));
      }
    }
  }

  if (f[0][n] < 0) {
    os << "Bob\n";
  } else if (0 < f[0][n]) {
    os << "Alice\n";
  } else {
    os << "Draw\n";
  }
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