#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main() {
  int T;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    int n, d;
    cin >> n >> d;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      int x;
      cin >> x;
      int take = min(x, i > 0 ? d / i : x);
      ans += take;
      d -= take * i;
    }
    cout << ans << "\n";
  }
}