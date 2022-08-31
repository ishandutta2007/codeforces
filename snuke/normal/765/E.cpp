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
#include <random>
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
#define uni(x) x.erase(unique(rng(x)),x.end())
#define snuke srand((unsigned)clock()+(unsigned)time(NULL));
#define df(x) int x = in()
#define dame { puts("-1"); return 0;}
#define show(x) cout<<#x<<" = "<<x<<endl;
#define PQ(T) priority_queue<T,vector<T>,greater<T> >
#define bn(x) ((1<<x)-1)
#define newline puts("")
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

vvi to;
vvi e;
vi res;

int afs(int v, int p=-1) {
  rep(i,sz(to[v])) {
    int u = to[v][i];
    if (u == p) continue;
    e[v].pb(afs(u,v));
  }
  if (sz(e[v]) == 0) return res[v] = 1;
  sort(rng(e[v]));
  // cout<<v<<" : "<<e[v]<<endl;
  if (e[v][0] != e[v].back()) return res[v] = INF;
  return res[v] = e[v][0]+1;
}
void bfs(int v, int x, int p=-1) {
  // cout<<v<<" "<<x<<endl;
  if (v) e[v].pb(x);
  sort(rng(e[v]));
  rep(i,sz(to[v])) {
    int u = to[v][i];
    if (u == p) continue;
    int l = 0, r = sz(e[v])-1;
    if (e[v][l] == res[u]) ++l;
    else if (e[v][r] == res[u]) --r;
    int y = 0;
    if (l <= r) {
      if (e[v][l] != e[v][r]) y = INF;
      else y = e[v][l];
    }
    bfs(u,y+1,v);
  }
}

int main() {
  int n;
  scanf("%d",&n);
  to = e = vvi(n);
  res = vi(n);
  rep(i,n-1) {
    int a,b;
    scanf("%d%d",&a,&b);
    --a; --b;
    to[a].pb(b);
    to[b].pb(a);
  }
  afs(0);
  bfs(0,0);
  rep(i,n) {
    vi a = e[i];
    uni(a);
    if (sz(a) > 2) continue;
    if (a.back() > n) continue;
    int l = e[i][0]+e[i].back();
    while (l%2 == 0) l >>= 1;
    cout<<l<<endl;
    return 0;
  }
  dame;
  return 0;
}