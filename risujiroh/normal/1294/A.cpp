#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int tt;
  cin >> tt;
  while (tt--) {
    vector<int> a(3);
    cin >> a[0] >> a[1] >> a[2];
    int n;
    cin >> n;
    sort(begin(a), end(a));
    if ((a[0] + a[1] + a[2] + n) % 3 == 0 and (a[2] - a[0]) + (a[2] - a[1]) <= n) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
}