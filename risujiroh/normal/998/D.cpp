#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using VI = vector<int>;
using VVI = vector<VI>;

int main() {
  cin.tie(0); ios::sync_with_stdio(false);
  lint n; cin >> n;
  if (n < 20) {
    set<int> s;
    for (int a = 0; a <= n; a++) {
      for (int b = 0; b <= n - a; b++) {
        for (int c = 0; c <= n - a - b; c++) {
          int d = n - a - b - c;
          int x = a + 5 * b + 10 * c + 50 * d;
          s.insert(x);
        }
      }
    }
    cout << s.size() << '\n';
  } else {
    cout << 49 * n - 247 << '\n';
  }
  return 0;
}