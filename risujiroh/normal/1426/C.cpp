#include <bits/extc++.h>

int main() {
  using namespace std;
  cin.tie(nullptr)->sync_with_stdio(false);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    int a = sqrt(n);
    int b = (n + a - 1) / a;
    cout << a + b - 2 << '\n';
  }
}