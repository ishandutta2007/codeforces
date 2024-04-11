#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 998244353;
int main() {
  ios_base::sync_with_stdio(0);
  int n, k;
  cin >> n >> k;
  int prv = -1;
  ll ans = 1;
  ll sm = 0;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    if (x > n - k) {
      if (prv != -1) {
      int ways = i - prv;
      ans = ans * ways % MOD;
      }
      prv = i;
      sm += x;
    }
  }
  cout << sm << " " << ans << "\n";
}