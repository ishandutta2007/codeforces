#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) {
    int h, m;
    cin >> h >> m;
    int res = 60 * 24 - (60 * h + m);
    cout << res << '\n';
  }
}