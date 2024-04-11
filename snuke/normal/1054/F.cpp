#include <bits/stdc++.h>
#define fi first
#define se second
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
#define srep(i,s,t) for (int i = s; i < t; ++i)
#define rng(a) a.begin(),a.end()
#define maxs(x,y) (x = max(x,y))
#define mins(x,y) (x = min(x,y))
#define limit(x,l,r) max(l,min(x,r))
#define lims(x,l,r) (x = max(l,min(x,r)))
#define isin(x,l,r) ((l) <= (x) && (x) < (r))
#define pb push_back
#define sz(x) (int)(x).size()
#define pcnt __builtin_popcountll
#define uni(x) x.erase(unique(rng(x)),x.end())
#define snuke srand((unsigned)clock()+(unsigned)time(NULL));
#define show(x) cout<<#x<<" = "<<x<<endl;
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
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<P> vp;
inline int in() { int x; scanf("%d",&x); return x;}
template<typename T>inline istream& operator>>(istream&i,v(T)&v)
{rep(j,sz(v))i>>v[j];return i;}
template<typename T>string join(const v(T)&v)
{stringstream s;rep(i,sz(v))s<<' '<<v[i];return s.str().substr(1);}
template<typename T>inline ostream& operator<<(ostream&o,const v(T)&v)
{if(sz(v))o<<join(v);return o;}
template<typename T1,typename T2>inline istream& operator>>(istream&i,pair<T1,T2>&v)
{return i>>v.fi>>v.se;}
template<typename T1,typename T2>inline ostream& operator<<(ostream&o,const pair<T1,T2>&v)
{return o<<v.fi<<","<<v.se;}
template<typename T>inline ll suma(const v(T)& a) { ll res(0); for (auto&& x : a) res += x; return res;}
const double eps = 1e-10;
const ll LINF = 1001002003004005006ll;
const int INF = 1001001001;
#define dame { puts("-1"); return 0;}
#define yn {puts("YES");}else{puts("NO");}
const int MX = 200005;
typedef pair<int,P> Q;
typedef vector<Q> vq;

// binary matching
struct match {
  vi used;
  vvi to;
  vi p, q;
  int n, m;
  match(int n, int m):used(n),to(n),p(n,-1),q(m,-1),n(n),m(m){}
  void add(int a, int b) { to[a].pb(b);}
  bool dfs(int v){
    if(used[v]) return false;
    used[v] = 1;
    rep(i,sz(to[v])) {
      int u = to[v][i];
      if (q[u] == -1 || dfs(q[u])){
        q[u] = v;
        return true;
      }
    }
    return false;
  }


  vi x, y;
  int solve(){
    int res = 0;
    rep(i,n) {
      rep(j,n) used[j] = 0;
      if(dfs(i)) ++res;
    }
    rep(i,m) if (q[i] != -1) p[q[i]] = i;

    x = vi(n);
    y = vi(m);
    queue<int> s;
    rep(i,n) if (p[i] == -1) {
      x[i] = 1;
      s.push(i);
    }
    while (sz(s)) {
      int v = s.front(); s.pop();
      if (v < n) {
        for (int u : to[v]) {
          if (y[u]) continue;
          y[u] = 1;
          s.push(u+n);
        }
      } else {
        v -= n;
        if (q[v] != -1) {
          int u = q[v];
          if (x[u]) continue;
          x[u] = 1;
          s.push(u);
        }
      }
    }
    rep(i,m) y[i] ^= 1;

    return res;
  }

};
//

// coordinate compression
struct X {
  typedef int T;
  vector<T> d;
  X() {}
  // X(vector<T>& a): d(a) {
  //   init();
  //   for (T& na : a) na = (*this)(na);
  // }
  void add(T x) { d.pb(x);}
  void init() {
    sort(rng(d));
    d.erase(unique(rng(d)), d.end());
  }
  int size() const { return sz(d);}
  T operator[](int i) const { return d[i];}
  int operator()(T x) const { return upper_bound(rng(d),x)-d.begin()-1;}
};
//

X xs, ys;
void initXY(vp& a) {
  for (P& p : a) xs.add(p.fi), ys.add(p.se);
  xs.init(); ys.init();
  for (P& p : a) p.fi = xs(p.fi), p.se = ys(p.se);
}

bool cross(const Q& a, const Q& b) {
  if (a.fi < b.se.fi || b.se.se < a.fi) return false;
  if (b.fi < a.se.fi || a.se.se < b.fi) return false;
  if (a.fi != b.se.fi && a.fi != b.se.se) return true;
  if (b.fi != a.se.fi && b.fi != a.se.se) return true;
  return false;
}

int main() {
  int n;
  scanf("%d",&n);
  vp p(n);
  cin>>p;
  sort(rng(p));
  initXY(p);
  vq a, b;

  {
    vvi x(sz(xs));
    rep(i,n) x[p[i].fi].pb(p[i].se);
    rep(i,sz(xs)) {
      rep(j,sz(x[i])-1) {
        a.pb(Q(i,P(x[i][j],x[i][j+1])));
      }
    }
  }
  {
    vvi x(sz(ys));
    rep(i,n) x[p[i].se].pb(p[i].fi);
    rep(i,sz(ys)) {
      rep(j,sz(x[i])-1) {
        b.pb(Q(i,P(x[i][j],x[i][j+1])));
      }
    }
  }

  match g(sz(a),sz(b));
  rep(i,sz(a))rep(j,sz(b)) {
    if (cross(a[i],b[j])) g.add(i,j);
  }
  g.solve();

  map<P,int> mx, my;
  rep(i,sz(a)) {
    if (g.x[i]) mx[P(a[i].fi,a[i].se.fi)] = i;
  }
  rep(i,sz(b)) {
    if (g.y[i]) my[P(b[i].se.fi,b[i].fi)] = i;
  }

  vp px = p;
  vp py = p;
  vvi as, bs;
  rep(i,n) {
    int fl = 3;
    {
      auto it = mx.find(p[i]);
      if (it != mx.end()) {
        int k = it->se;
        int j = lower_bound(rng(p),P(a[k].fi,a[k].se.se))-p.begin();
        px[j] = px[i];
        fl ^= 2;
      }
    }
    {
      auto it = my.find(p[i]);
      if (it != my.end()) {
        int k = it->se;
        int j = lower_bound(rng(p),P(b[k].se.se,b[k].fi))-p.begin();
        py[j] = py[i];
        fl ^= 1;
      }
    }

    if (fl&1) {
      as.pb({py[i].fi,py[i].se,p[i].fi,p[i].se});
    }
    if (fl&2) {
      bs.pb({px[i].fi,px[i].se,p[i].fi,p[i].se});
    }
  }

  printf("%d\n",sz(as));
  rep(i,sz(as)) {
    int si = xs[as[i][0]], sj = ys[as[i][1]];
    int ti = xs[as[i][2]], tj = ys[as[i][3]];
    printf("%d %d %d %d\n",si,sj,ti,tj);
  }
  printf("%d\n",sz(bs));
  rep(i,sz(bs)) {
    int si = xs[bs[i][0]], sj = ys[bs[i][1]];
    int ti = xs[bs[i][2]], tj = ys[bs[i][3]];
    printf("%d %d %d %d\n",si,sj,ti,tj);
  }
  return 0;
}