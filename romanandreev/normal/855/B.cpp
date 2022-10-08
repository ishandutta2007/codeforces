#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

#define all(c) (c).begin(),(c).end()
#define sz(c) (int)(c).size()
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define image(a) {sort(all(a)), a.resize(unique(all(a)) - a.begin());}
const ll INF = (ll)5e18;
void solve() {
  int n;
  int c[3];
  scanf("%d %d %d %d", &n, &c[0], &c[1], &c[2]);
  vector<int> a(n);  
  vector<vector<ll>> dp(n + 1, vector<ll>(4, -INF));    
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  dp[0][0] = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= 3; j++) {
      dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
      if (j + 1 <= 3) {
        dp[i][j + 1] = max(dp[i][j + 1], dp[i][j] + (ll)c[j] * (ll)a[i]);
      }
    }
  }
  cout << dp[n][3] << endl;
}

int main(){
  #ifdef home
  assert(freopen("a.out","wt",stdout));
  assert(freopen("a.in","rt",stdin));
  #endif
  solve();
  return 0;
}