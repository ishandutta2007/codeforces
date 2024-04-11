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
#include <bitset>
#include <cassert>
#define fi first
#define se second
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
#define gep(i,g,j) for(int i = g.head[j]; i != -1; i = g.e[i].next)
#define each(it,c) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define rng(a) a.begin(),a.end()
#define maxs(x,y) x = max(x,y)
#define mins(x,y) x = min(x,y)
#define pb push_back
#define sz(x) (int)(x).size()
#define pcnt __builtin_popcount
#define snuke srand((unsigned)clock()+(unsigned)time(NULL));
#define df(x) int x = in()
#define dame { puts("0"); return 0;}
#define show(x) cout<<#x<<" = "<<x<<endl;
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<P> vp;
inline int in() { int x; scanf("%d",&x); return x;}
inline void priv(vi a) { rep(i,sz(a)) printf("%d%c",a[i],i==sz(a)-1?'\n':' ');}
template<typename T>istream& operator>>(istream&i,vector<T>&v)
{rep(j,sz(v))i>>v[j];return i;}
template<typename T>string join(vector<T>&v)
{stringstream s;rep(i,sz(v))s<<' '<<v[i];return s.str().substr(1);}
template<typename T>ostream& operator<<(ostream&o,vector<T>&v)
{if(sz(v))o<<join(v);return o;}
template<typename T1,typename T2>istream& operator>>(istream&i,pair<T1,T2>&v)
{return i>>v.fi>>v.se;}
template<typename T1,typename T2>ostream& operator<<(ostream&o,pair<T1,T2>&v)
{return o<<v.fi<<","<<v.se;}

const int MX = 100005, INF = 1001001001;
const ll LINF = 1e18;
const double eps = 1e-10;

int n, m;
vi to[MX], co[MX];
int used[MX];
vi d, as;

int cnt;
int dfs(int v, int c=0) {
  ++cnt;
  used[v] = 1;
  d[v] = c;
  int res = c;
  rep(i,sz(to[v])) {
    int u = to[v][i];
    if (used[u]) {
      if ((d[u] == c) == co[v][i]) return INF;
    } else {
      int r = dfs(u, c^co[v][i]);
      if (r == INF) return INF;
      res += r;
    }
  }
  return res;
}
void efs(int v) {
  if (used[v] == 2) return;
  used[v] = 2;
  d[v] ^= 1;
  for (int u : to[v]) efs(u);
}

int main() {
  scanf("%d%d",&n,&m);
  rep(i,m) {
    int a, b;
    scanf("%d%d",&a,&b);
    --a; --b;
    char c;
    scanf(" %c",&c);
    to[a].pb(b); co[a].pb(c=='R');
    to[b].pb(a); co[b].pb(c=='R');
  }
  int ans = INF;
  d = vi(n);
  rep(ti,2) {
    rep(i,n) used[i] = 0;
    int sum = 0;
    rep(i,n) if (!used[i]) {
      cnt = 0;
      int res = dfs(i);
      if (res == INF) {
        sum = INF;
        break;
      } else {
        sum += min(res, cnt-res);
        if (res > cnt-res) efs(i);
      }
    }
    if (ans > sum) {
      ans = sum;
      as = d;
    }
    rep(i,n) for (int& x : co[i]) x ^= 1;
  }
  if (ans == INF) {
    cout<<-1<<endl;
    return 0;
  }
  printf("%d\n",ans);
  vi av;
  rep(i,n) if (as[i]) av.pb(i+1);
  priv(av);
  return 0;
}