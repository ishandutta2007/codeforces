#include <bits/stdc++.h>
#define fi first
#define se second
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
#define srep(i,s,t) for (int i = s; i < t; ++i)
#define rng(a) a.begin(),a.end()
#define rrng(a) a.rbegin(),a.rend()
#define isin(x,l,r) ((l) <= (x) && (x) < (r))
#define pb push_back
#define eb emplace_back
#define sz(x) (int)(x).size()
#define pcnt __builtin_popcountll
#define uni(x) x.erase(unique(rng(x)),x.end())
#define snuke srand((unsigned)clock()+(unsigned)time(NULL));
#define show(x) cerr<<#x<<" = "<<x<<endl;
#define PQ(T) priority_queue<T,v(T),greater<T> >
#define bn(x) ((1<<x)-1)
#define dup(x,y) (((x)+(y)-1)/(y))
#define newline puts("")
#define v(T) vector<T>
#define vv(T) v(v(T))
using namespace std;
typedef long long int ll;
typedef unsigned uint;
typedef unsigned long long ull;
typedef pair<int,int> P;
typedef tuple<int,int,int> T;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<P> vp;
typedef vector<T> vt;
int getInt(){int x;scanf("%d",&x);return x;}
template<typename T>istream& operator>>(istream&i,v(T)&v){rep(j,sz(v))i>>v[j];return i;}
template<typename T>string join(const v(T)&v){stringstream s;rep(i,sz(v))s<<' '<<v[i];return s.str().substr(1);}
template<typename T>ostream& operator<<(ostream&o,const v(T)&v){if(sz(v))o<<join(v);return o;}
template<typename T1,typename T2>istream& operator>>(istream&i,pair<T1,T2>&v){return i>>v.fi>>v.se;}
template<typename T1,typename T2>ostream& operator<<(ostream&o,const pair<T1,T2>&v){return o<<v.fi<<","<<v.se;}
template<typename T>bool mins(T& x,const T&y){if(x>y){x=y;return true;}else return false;}
template<typename T>bool maxs(T& x,const T&y){if(x<y){x=y;return true;}else return false;}
template<typename T>ll suma(const v(T)&a){ll res(0);for(auto&&x:a)res+=x;return res;}
const double eps = 1e-10;
const ll LINF = 1001002003004005006ll;
const int INF = 1001001001;
#define dame { puts("-1"); return 0;}
#define yn {puts("Yes");}else{puts("No");}
const int MX = 200005;
const int di[] = {-1,0,1,0}, dj[] = {0,-1,0,1}; //^<v>
//const int di[] = {-1,0,1,-1,1,-1,0,1}, dj[] = {-1,-1,-1,0,0,1,1,1};

// Max flow
// !! Be care of double and INF !!
struct Maxflow {
  typedef int TT;
  int n;
  vi to, next, head, dist;
  vector<TT> lim;
  Maxflow(){}
  Maxflow(int n):n(n),head(n,-1),used(n){}
  void add(int a, int b, TT c=1) {
    next.pb(head[a]); head[a] = sz(to); to.pb(b); lim.pb(c);
    next.pb(head[b]); head[b] = sz(to); to.pb(a); lim.pb(0); 
  }
  void add2(int a, int b, TT c=1) {
    next.pb(head[a]); head[a] = sz(to); to.pb(b); lim.pb(c);
    next.pb(head[b]); head[b] = sz(to); to.pb(a); lim.pb(c); 
  }

  vi used; int ui;
  bool dfs(int v, int tv) {
    if (v == tv) return true;
    used[v] = ui;
    for (int i = head[v]; i != -1; i = next[i]) {
      if (!lim[i]) continue;
      int u = to[i];
      if (used[u] == ui) continue;
      if (dfs(u,tv)) {
        lim[i]--; lim[i^1]++;
        return true;
      }
    }
    return false;
  }

  TT solve(int sv, int tv, int mx=INF) {
    TT flow = 0;
    while (mx) {
      ++ui;
      if (dfs(sv,tv)) flow += 1, mx -= 1;
      else break;
    }
    return flow;
  }
};
//



int main() {
  int n;
  scanf("%d",&n);
  vvi x(n,vi(n));
  cin>>x;

  int sv = n*n, tv = sv+1;
  Maxflow g(tv+1);

  vvi e(n,vi(n));
  map<int,vi> mp;
  rep(i,n)rep(j,n) {
    int a = i*n+j;
    if (i == 0 || j == 0 || i == n-1 || j == n-1) {
      mp[x[i][j]].pb(a);
      e[i][j] = sz(g.lim);
      g.add(sv,a,0);
      g.add(a,tv,INF);
    }
    if (x[i][j] == -1) continue;
    rep(v,2) {
      int ni = i+di[v], nj = j+dj[v];
      if (ni<0||nj<0||ni>=n||nj>=n) continue;
      if (x[ni][nj] == -1) continue;
      int b = ni*n+nj;
      g.add2(a,b,1);
    }
  }

  int now = 0;
  int pre = 0;
  ll ans = 0;
  for (auto p : mp) {
    ans += ll(p.fi-pre)*now;
    pre = p.fi;
    for (int v : p.se) {
      int es = e[v/n][v%n];
      int et = es+2;
      int x = INF-g.lim[et];
      g.lim[et] = g.lim[et^1] = 0;
      assert(g.solve(v,sv,x) == x);
      now -= x;
      g.lim[es] = INF;
    }
    now += g.solve(sv,tv);
  }

  cout<<ans<<endl;
  return 0;
}