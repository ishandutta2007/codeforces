#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, a, b;
  cin >> n >> a >> b;

  string s;
  cin >> s;
  int z = 0;
  bool k = false;
  for(int i = 0; i < n; ++i) {
    if (s[i] == '0') {
      if (!k) {
        ++z;
      }
      k = true;
    } else {
      k = false;
    }
  }

  ll ans = 0;
  if (z > 0) {
    --z;
    ans += b;
  }
  ans += ll(min(a, b)) * z;
  cout << ans << "\n";
}