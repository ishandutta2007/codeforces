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

// BFS
struct bfs {
  vi d, p, vs;
  bfs(){}
  //*
  vvi to;
  bfs(int n):d(n),p(n),to(n){}
  void add(int a, int b) {
    to[a].pb(b); //to[b].pb(a);
  }
  //*/ bfs(int n):d(n),p(n){}
  void solve(int sv) {
    vs = vi();
    d = vi(n,INF); p = vi(n,-1);
    queue<int> q;
    d[sv] = 0; q.push(sv);
    while (q.size()) {
      int v = q.front(); q.pop();
      vs.pb(v);
      rep(i,to[v].size()) {
        int u = to[v][i];
        if (d[u] != INF) continue;
        d[u] = d[v]+1; p[u] = v;
        q.push(u);
      }
    }
    reverse(rng(vs));
  }
};
//

int main() {
  scanf("%d%d",&n,&m);
  bfs g(n);
  rep(i,m) {
    int a, b;
    scanf("%d%d",&a,&b);
    --a; --b;
    g.add(a,b);
  }
  vvi d(n);
  rep(i,n) {
    g.solve(i);
    d[i] = g.d;
  }
  vi as; int ans = -1;
  vvi da(n), db(n);
  rep(i,n) {
    rep(j,n) if (i != j && d[i][j] != INF) da[i].pb(j);
    sort(rng(da[i]), [&](int a, int b) {
      return d[i][a] > d[i][b];
    });
  }
  rep(i,n) {
    rep(j,n) if (i != j && d[j][i] != INF) db[i].pb(j);
    sort(rng(db[i]), [&](int a, int b) {
      return d[a][i] > d[b][i];
    });
  }
  rep(i,n)rep(j,n) if (i != j && d[i][j] != INF) {
    int now = d[i][j], mx = -INF; P p(0,0);
    drep(bi,min(3,sz(db[i])))drep(ai,min(3,sz(da[j]))) {
      int aj = da[j][ai];
      int bj = db[i][bi];
      if (aj != bj && aj != i && bj != j) {
        int nc = d[bj][i];
        nc += d[j][aj];
        if (nc > mx) {
          mx = nc;
          p = P(bj,aj);
        }
      }
    }
    if (mx == -INF) continue;
    now += mx;
    if (ans < now) {
      ans = now;
      as = {p.fi,i,j,p.se};
    }
  }
  // cout<<ans<<endl;
  for (int& i : as) i++;
  cout<<as<<endl;
  return 0;
}