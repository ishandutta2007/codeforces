#include <cstdio>
#include <algorithm>
#include <stack>
#include <queue>
#include <deque>
#include <vector>
#include <string>
#include <string.h>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <map>
#include <set>
#include <iostream>
#include <sstream>
#include <numeric>
#include <cctype>
#define fi first
#define se second
#define rep(i,n) for(int i = 0; i < n; ++i)
#define rrep(i,n) for(int i = 1; i <= n; ++i)
#define drep(i,n) for(int i = n-1; i >= 0; --i)
#define gep(i,g,j) for(int i = g.head[j]; i != -1; i = g.e[i].next)
#define each(it,c) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define rng(a) a.begin(),a.end()
#define maxs(x,y) x = max(x,y)
#define mins(x,y) x = min(x,y)
#define pb push_back
#define sz(x) (int)(x).size()
#define pcnt __builtin_popcount
#define snuke srand((unsigned)clock()+(unsigned)time(NULL));
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;
typedef vector<int> vi;
inline int in() { int x; scanf("%d",&x); return x;}
inline void priv(vi a) { rep(i,sz(a)) printf("%d%c",a[i],i==sz(a)-1?'\n':' ');}

const int MX = 3005, INF = 1000010000;
const ll LINF = 1000000000000000000ll;
const double eps = 1e-10;

int n, m;
vi to[MX];

int s[2], t[2], l[2];
int d[MX][MX];

void calc(int s) {
  rep(i,n) d[s][i] = INF;
  queue<int> q;
  q.push(s); d[s][s] = 0;
  while(sz(q)) {
    int v = q.front(); q.pop();
    for(int u: to[v]) {
      if (d[s][u] != INF) continue;
      d[s][u] = d[s][v]+1;
      q.push(u);
    }
  }
}

int main(){
  scanf("%d%d",&n,&m);
  rep(i,m) {
    int a, b;
    scanf("%d%d",&a,&b);
    --a; --b;
    to[a].pb(b);
    to[b].pb(a);
  }
  rep(i,2) scanf("%d%d%d",&s[i],&t[i],&l[i]);
  rep(i,2) s[i]--, t[i]--;
  rep(i,n) calc(i);
  //rep(i,n)rep(j,n) cout<<i<<" "<<j<<" "<<d[i][j]<<endl;
  ll ans = INF;
  if (d[s[0]][t[0]] <= l[0] && d[s[1]][t[1]] <= l[1]) {
    mins(ans,(ll)d[s[0]][t[0]] + d[s[1]][t[1]]);
  }
  if (ans >= INF) {
    cout << -1 << endl;
    return 0;
  }
  rep(i,n)rep(j,n) {
    if (d[s[0]][i]+d[t[0]][j]+d[i][j] > l[0]) continue;
    if (d[s[1]][j]+d[t[1]][i]+d[i][j] > l[1]) continue;
    ll now = 0;
    now += d[s[0]][i];
    now += d[t[1]][i];
    now += d[t[0]][j];
    now += d[s[1]][j];
    now += d[i][j];
    mins(ans,now);
  }
  rep(i,n)rep(j,n) {
    if (d[s[0]][i]+d[t[0]][j]+d[i][j] > l[0]) continue;
    if (d[s[1]][i]+d[t[1]][j]+d[i][j] > l[1]) continue;
    ll now = 0;
    now += d[s[0]][i];
    now += d[s[1]][i];
    now += d[t[1]][j];
    now += d[t[0]][j];
    now += d[i][j];
    mins(ans,now);
  }
  cout<<m-ans<<endl;
  return 0;
}