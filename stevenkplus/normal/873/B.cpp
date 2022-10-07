// =========== Template ========== //
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define fi first
#define se second

// =========== Book ============ //

// =========== Solution ============= //

int main()  {
  int n;
  cin >> n;
  string s;
  cin >> s;
  map<int, int> ix;
  int ans = 0;
  int cur = 0;
  for(int i = 0; i <= n; ++i) {
    if (ix.find(cur) != ix.end()) {
      int len = i - ix[cur];
      ans = max(ans, len);
    } else {
      ix[cur] = i;
    }
    if (i < n) {
      if (s[i] == '0') ++cur;
      else --cur;
    }
  }

  cout << ans << "\n";
}