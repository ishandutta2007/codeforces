#include <bits/stdc++.h>

using namespace std;

int n, t;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> t;
  int ans = 0;
  int twait = 1000000000;
  int s, d;

  for (int cur = 1; cur <= n; cur++) {
    cin >> s >> d;
    while (s < t) s += d;
    if (s - t < twait) {
      twait = s-t;
      ans = cur;
    }
  }
  cout << ans << endl;
}