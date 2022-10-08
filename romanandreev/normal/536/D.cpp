#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstdarg>
#include <cassert>
#include <climits>
#include <cstring>
#include <complex>
#include <cstdio>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
#include <ctime>
#include <set>
#include <map>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pi;
typedef vector<int> vi;


#define all(c) (c).begin(),(c).end()
#define sz(c) (int)(c).size()

#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define x first
#define y second
#define y1 y1_gdssdfjsdgf
#define y0 y0_fsdjfsdogfs
#define ws ws_fdfsdfsdgfs
#define image(a) {sort(all(a)),a.resize(unique(all(a))-a.begin());}
#define eprintf(...) {fprintf(stderr,__VA_ARGS__),fflush(stderr);}

#define forn(i,n) for( int i = 0 ; i < (n) ; i++ )
#define forit(it,c) for( __typeof((c).begin()) it = (c).begin() ; it != (c).end() ; it++ )
#define problem_name "a"
const int maxn = 2010;
int n, m, S, T;
int p[maxn];
vector<pair<int, int> > g[maxn];
const ll inf = 1e18;
ll d[2][maxn];
int was[maxn];
ll dp[maxn][maxn][2];
ll mx[maxn][maxn][2];
int nx[maxn][maxn][2];

ll sum[maxn][maxn];
int cc[maxn][maxn];

vector<int> K;
void dijkstra(int v, ll* d) {
  for (int i = 0; i < n; i++) {
    d[i] = inf;
    was[i] = 0;
  }
  d[v] = 0;
  for (int it = 0; it < n; it++) {
    int mn = -1;
    for (int i = 0; i < n; i++) if (was[i] == 0 && (mn == -1 || d[mn] > d[i])) {
      mn = i;
    }
    was[mn] = 1;
    for (int i = 0; i < sz(g[mn]); i++) {
      d[g[mn][i].x] = min(d[g[mn][i].x], d[mn] + g[mn][i].y);
    }
  }
}
int main(){
  #ifdef home
  assert(freopen(problem_name".out","wt",stdout));
  assert(freopen(problem_name".in","rt",stdin));
  #endif
  scanf("%d %d", &n, &m);
  scanf("%d %d", &S, &T);
  S--, T--;
  for (int i = 0; i < n; i++) {
    scanf("%d", &p[i]);
  }
  for (int i = 0; i < m; i++) {
    int x, y, w;
    scanf("%d %d %d", &x, &y, &w);
    x--,y--;
    g[x].pb(mp(y, w));
    g[y].pb(mp(x, w));
  }
  dijkstra(S, d[0]);
  dijkstra(T, d[1]);  
  for (int i = 0; i < 2; i++) {
    vector<ll> ls;
    for (int j = 0; j < n; j++) {
      ls.pb(d[i][j]);
    }
    image(ls);
    for (int j = 0; j < n; j++) {
      d[i][j] = lower_bound(all(ls), d[i][j]) - ls.begin() + 1;
    }
    K.pb(sz(ls));
  }
  for (int i = 0; i < n; i++) {
    sum[d[0][i]][d[1][i]] += p[i];
    cc[d[0][i]][d[1][i]]++;
  }
  for (int i = K[0] + 1; i >= 0; i--) {
    for (int j = K[1] + 1; j >= 0; j--) {
      sum[i][j] += sum[i + 1][j] + sum[i][j + 1] - sum[i + 1][j + 1];
      cc[i][j] += cc[i + 1][j] + cc[i][j + 1] - cc[i + 1][j + 1];
      mx[i][j][0] = -sum[i + 1][j + 1];
      mx[i][j][1] = -sum[i + 1][j + 1];
    }
  }
  for (int i = K[0]; i >= 0; i--) {
    for (int j = K[1]; j >= 0; j--) {
      nx[i][j][0] = nx[i + 1][j][0];
      if (cc[i + 1][j + 1] - cc[i + 1 + 1][j + 1] > 0) {
        nx[i][j][0] = i + 1;
      }
      nx[i][j][1] = nx[i][j + 1][1];
      if (cc[i + 1][j + 1] - cc[i + 1][j + 1 + 1] > 0) {
        nx[i][j][1] = j + 1;
      }
    }
  }
  for (int i = K[0]; i >= 0; i--) {
    for (int j = K[1]; j >= 0; j--) {
      if (cc[i + 1][j + 1] == 0) {
        continue;
      }
      int i1 = nx[i][j][0];
      dp[i][j][0] = mx[i1][j][0] + sum[i + 1][j + 1];        
      int j1 = nx[i][j][1];
      dp[i][j][1] = mx[i][j1][1] + sum[i + 1][j + 1];
      mx[i][j][0] = max(mx[i + 1][j][0], -dp[i][j][1] - sum[i + 1][j + 1]);
      mx[i][j][1] = max(mx[i][j + 1][1], -dp[i][j][0] - sum[i + 1][j + 1]);
//      cerr<<i<<" "<<j<<" "<<dp[i][j][0]<<" "<<dp[i][j][1]<<endl;
    }
  }
  cerr<<dp[0][0][0]<<endl;
  if (dp[0][0][0] > 0) {
    printf("Break a heart\n");
  } else
  if (dp[0][0][0] == 0) {
    printf("Flowers\n");
  } else {
    printf("Cry\n");
  }
  return 0;                   
}