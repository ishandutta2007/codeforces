#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    if (n == 1) {
      cout << "-1\n";
    } else {
      cout << "2" + string(n - 1, '3') << '\n';
    }
  }
}