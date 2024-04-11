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
const int maxn = 201000;
int was[maxn];
vector<int> g[maxn];
int dp1[maxn];
ll dp2[maxn];
int dp3[maxn][5];
ll dp4[maxn];
int dp5[maxn][5];
int n, k;
void dfs(int v) {
  was[v] = 1;
  dp1[v] = 1;
  dp2[v] = 0;
  dp3[v][0]++;
  for (int e : g[v]) if (was[e] == 0) {
    dfs(e);
    dp1[v] += dp1[e];
    dp2[v] += dp2[e] + dp1[e];
    for (int i = 0; i < k; i++) {
      dp3[v][i] += dp3[e][(i - 1 + k) % k];
    }
  }
}
ll ans = 0;
void dfs2(int v) {
  was[v] = 1;
  for (int e : g[v]) if (was[e] == 0) {    
    dp4[e] = dp2[e] + dp4[v] - (dp2[e] + dp1[e]) + n - dp1[e];
    for (int i = 0; i < k; i++) {
      dp5[e][i] = dp3[e][i] + dp5[v][(i - 1 + k) % k] - dp3[e][(i - 2 + k * 2) % k];
    }
    dfs2(e);    
  }    
  ll x = dp4[v] - (n - 1);
  dp5[v][0]--;
  for (int i = 0; i < k; i++) {
    x -= i * dp5[v][(i + 1) % k];
  }
  ans += x / k + n - 1;  
}
void solve() {
  scanf("%d %d", &n, &k);
  for (int i = 0; i < n - 1; i++) {
    int x, y;
    scanf("%d %d", &x, &y);
    x--, y--;
    g[x].pb(y);
    g[y].pb(x);
  }  
  for (int i = 0; i < n; i++) {
    was[i] = 0;
  }
  dfs(0);
  for (int i = 0; i < n; i++) {
    was[i] = 0;
  }
  dp4[0] = dp2[0];
  for (int i = 0; i < k; i++) {
    dp5[0][i] = dp3[0][i];
  }
  dfs2(0);
  cout << ans / 2 << endl;
}

int main(){
  #ifdef home
  assert(freopen("a.out","wt",stdout));
  assert(freopen("a.in","rt",stdin));
  #endif
  solve();
  return 0;
}