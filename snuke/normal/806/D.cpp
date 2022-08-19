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
#define uni(x) x.erase(unique(rng(x)),x.end())
#define snuke srand((unsigned)clock()+(unsigned)time(NULL));
#define df(x) int x = in()
#define dame { puts("-1"); return 0;}
#define show(x) cout<<#x<<" = "<<x<<endl;
#define PQ(T) priority_queue<T,vector<T>,greater<T> >
#define bn(x) ((1<<x)-1)
#define newline puts("")
#define v(T) vector<T>
#define vv(T) vector<vector<T>>
using namespace std;
typedef long long int ll;
typedef unsigned uint;
typedef unsigned long long ull;
typedef pair<ll,int> P;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<P> vp;
inline int in() { int x; scanf("%d",&x); return x;}
inline void priv(vi a) { rep(i,sz(a)) printf("%d%c",a[i],i==sz(a)-1?'\n':' ');}
template<typename T>istream& operator>>(istream&i,vector<T>&v)
{rep(j,sz(v))i>>v[j];return i;}
template<typename T>string join(const vector<T>&v)
{stringstream s;rep(i,sz(v))s<<' '<<v[i];return s.str().substr(1);}
template<typename T>ostream& operator<<(ostream&o,const vector<T>&v)
{if(sz(v))o<<join(v);return o;}
template<typename T1,typename T2>istream& operator>>(istream&i,pair<T1,T2>&v)
{return i>>v.fi>>v.se;}
template<typename T1,typename T2>ostream& operator<<(ostream&o,const pair<T1,T2>&v)
{return o<<v.fi<<","<<v.se;}
const int MX = 100005, INF = 1001001001;
const ll LINF = 1e18;
const double eps = 1e-10;

int n, tv;
vvl g;


int main() {
  scanf("%d",&n);
  g = vvl(n,vl(n,LINF));
  P p(INF,0);
  rep(i,n-1)for (int j = i+1; j < n; ++j) {
    scanf("%I64d",&g[i][j]);
    g[j][i] = g[i][j];
    mins(p,P(g[i][j],i));
  }
  tv = p.se;
  ll c = p.fi;
  rep(i,n)rep(j,n) {
    g[i][j] -= c;
  }
  vl dist(n,LINF);
  rep(i,n) {
    ll mn = LINF;
    rep(j,n) mins(mn,g[i][j]);
    dist[i] = mn*2;
  }
  dist[tv] = 0;
  vi used(n);
  rep(ti,n) {
    // cerr<<dist<<endl;
    p = P(LINF,-1);
    rep(i,n) if (!used[i]) mins(p,P(dist[i],i));
    int v = p.se;
    used[v] = 1;
    rep(i,n) {
      mins(dist[i],dist[v]+g[v][i]);
    }
  }
  rep(i,n) {
    ll ans = dist[i]+c*(n-1);
    printf("%I64d\n",ans);
  }
  return 0;
}