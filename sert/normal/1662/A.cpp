#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n;
  cin >> n;
  std::array<int, 10> mx{};
  while (n--) {
    int b, d;
    cin >> b >> d;
    mx[d - 1] = max(mx[d - 1], b);
  }
  if (*min_element(mx.begin(), mx.end()) == 0) {
    cout << "MOREPROBLEMS\n";
  } else {
    cout << accumulate(mx.begin(), mx.end(), 0) << "\n";
  }
}

#ifdef SERT
bool D = true;
#else
bool D = false;
#endif

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  if (D) {
    freopen("../a.in", "r", stdin);
    t = 3;
  }
  cin >> t;
  while (t--) {
    solve();
  }
}