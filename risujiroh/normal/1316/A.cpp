#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, m;
    cin >> n >> m;
    int sum = 0;
    while (n--) {
      int a;
      cin >> a;
      sum += a;
    }
    cout << min(sum, m) << '\n';
  }
}