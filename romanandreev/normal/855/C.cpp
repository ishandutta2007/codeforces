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
const int md = (int)1e9 + 7;
const int maxn = (int)2e5 + 10;
vector<int> g[maxn];
int n, m, k, C;
int dp[maxn][3][11];
int l[3];
int r[3];
int mul(int x, int y) {
  return int(((ll)x * (ll)y) % md);
}
void add(int& x, int y) {
  x += y;
  if (x >= md) {
    x -= md;
  }
}
void dfs(int v, int pr) {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j <= C; j++) {
      dp[v][i][j] = 0;
    }
  }
  dp[v][0][0] = r[0] - l[0] + 1;
  dp[v][1][1] = r[1] - l[1] + 1;
  dp[v][2][0] = r[2] - l[2] + 1;
  for (int e : g[v]) if (e != pr) {
    dfs(e, v);
    vector<vector<int>> cur(3, vector<int>(C + 1, 0));
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j <= C; j++) {
        for (int i1 = 0; i1 < 3; i1++) {
          if (i == 1 && i1 != 0) {
            continue;
          }
          if (i != 0 && i1 == 1) {
            continue;
          }
          for (int j1 = 0; j + j1 <= C; j1++) {
            add(cur[i][j + j1], mul(dp[v][i][j], dp[e][i1][j1]));
          }
        }
      }
    }
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j <= C; j++) {
        dp[v][i][j] = cur[i][j];
      }
    }
  }  
}
void solve() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n - 1; i++) {
    int x, y;
    scanf("%d %d", &x, &y);
    x--, y--;
    g[x].pb(y);
    g[y].pb(x);
  }
  scanf("%d %d", &k, &C);
  l[0] = 1;
  r[0] = k - 1;
  l[1] = k;
  r[1] = k;
  l[2] = k + 1;
  r[2] = m;
  dfs(0, -1);
  int ans = 0;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j <= C; j++) {
      add(ans, dp[0][i][j]);
    }
  }
  cout << ans << endl;
}

int main(){
  #ifdef home
  assert(freopen("a.out","wt",stdout));
  assert(freopen("a.in","rt",stdin));
  #endif
  solve();
  return 0;
}