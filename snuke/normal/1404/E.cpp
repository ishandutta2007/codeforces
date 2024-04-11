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
typedef v(string) vs;
const int di[] = {-1,0,1,0}, dj[] = {0,-1,0,1}; //^<v>
//const int di[] = {-1,0,1,-1,1,-1,0,1}, dj[] = {-1,-1,-1,0,0,1,1,1};

// Max flow
// !! Be care of double and INF !!
struct Maxflow {
  typedef ll TT;
  int n;
  vi to, next, head, dist, it;
  vector<TT> lim;
  Maxflow(){}
  Maxflow(int n):n(n),head(n,-1),it(n){}
  void add(int a, int b, TT c=1) {
    next.pb(head[a]); head[a] = sz(to); to.pb(b); lim.pb(c);
    next.pb(head[b]); head[b] = sz(to); to.pb(a); lim.pb(0); 
  }
  void bfs(int sv) {
    dist = vi(n,INF);
    queue<int> q;
    dist[sv] = 0; q.push(sv);
    while (!q.empty()){
      int v = q.front(); q.pop();
      for (int i = head[v]; i != -1; i = next[i]) {
        if (lim[i] && dist[to[i]] == INF) { // double !!
          dist[to[i]] = dist[v]+1; q.push(to[i]);
        }
      }
    }
  }
  TT dfs(int v, int tv, TT nf=LINF) { // INF !!
    if (v == tv) return nf;
    for (; it[v] != -1; it[v] = next[it[v]]) {
      int u = to[it[v]]; TT f;
      if (!lim[it[v]] || dist[v] >= dist[u]) continue; // double !!
      if (f = dfs(u, tv, min(nf, lim[it[v]])), f) { // double !!
        lim[it[v]] -= f;
        lim[it[v]^1] += f;
        return f;
      }
    }
    return 0;
  }
  TT solve(int sv, int tv) {
    TT flow = 0, f;
    while (1) {
      bfs(sv);
      if (dist[tv] == INF) return flow;
      rep(i,n) it[i] = head[i];
      while (f = dfs(sv,tv), f) flow += f;
    }
  }
};
//



int main() {
  int h,w;
  scanf("%d%d",&h,&w);
  vs s(h);
  cin>>s;
  int n = h*w;
  int sv = n*2, tv = sv+1;
  Maxflow g(tv+1);
  int tot = 0;
  ll base = 0;
  rep(i,h)rep(j,w) {
    if (s[i][j] == '.') continue;
    int a = i*w+j, ia = a+n;
    vi e(2);
    rep(v,4) {
      int ni = i+di[v], nj = j+dj[v];
      if (ni<0||nj<0||ni>=h||nj>=w) continue;
      if (s[ni][nj] == '.') continue;
      tot++;
      int b = ni*w+nj, ib = b+n;
      g.add(a,ib,1);
      e[v&1]++;
    }
    g.add(sv,a,INF+e[0]);
    g.add(ia,tv,INF+e[1]);
    g.add(a,ia,LINF);
    base += INF;
  }

  ll ans = g.solve(sv,tv)-base;
  ans = base/INF - (tot-ans)/2;
  cout<<ans<<endl;
  return 0;
}