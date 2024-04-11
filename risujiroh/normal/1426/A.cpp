#include <bits/extc++.h>

int main() {
  using namespace std;
  cin.tie(nullptr)->sync_with_stdio(false);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, x;
    cin >> n >> x;
    if (n <= 2) {
      cout << "1\n";
    } else {
      n -= 3;
      n /= x;
      cout << n + 2 << '\n';
    }
  }
}