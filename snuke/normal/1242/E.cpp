#include <bits/stdc++.h>
#define fi first
#define se second
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
#define srep(i,s,t) for (int i = s; i < t; ++i)
#define rng(a) a.begin(),a.end()
#define rrng(a) a.rbegin(),a.rend()
#define maxs(x,y) (x = max(x,y))
#define mins(x,y) (x = min(x,y))
#define limit(x,l,r) max(l,min(x,r))
#define lims(x,l,r) (x = max(l,min(x,r)))
#define isin(x,l,r) ((l) <= (x) && (x) < (r))
#define pb push_back
#define eb emplace_back
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
typedef tuple<int,int,int> T;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<P> vp;
typedef vector<T> vt;
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
{return o<<v.fi<<" "<<v.se;}
template<typename T>inline ll suma(const v(T)& a) { ll res(0); for (auto&& x : a) res += x; return res;}
const double eps = 1e-10;
const ll LINF = 1001002003004005006ll;
const int INF = 1001001001;
#define dame { puts("-1"); return 0;}
#define yn {puts("Yes");}else{puts("No");}
const int MX = 200005;
inline void priv(vi a) { rep(i,sz(a)) printf("%d%c",a[i],i==sz(a)-1?'\n':' ');}

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

// Union find
struct uf {
  vi d;
  uf(){}
  uf(int mx):d(mx,-1){}
  int root(int x) {
    if(d[x] < 0) return x;
    return d[x] = root(d[x]);
  }
  bool unite(int x, int y) {
    x = root(x); y = root(y);
    if(x == y) return false;
    if(d[x] > d[y]) swap(x,y);
    d[x] += d[y]; d[y] = x;
    return true;
  }
  int size(int x) { return -d[root(x)];}
  int operator[](int x) { return root(x);}
  int operator()(int x) { return size(x);}
};
//

int f(int a, int b) {
  int c = a-b+2;
  if (c < 3) c += 2;
  return c;
}

int g(int tot, int mx, int n) {
  int res = mx-(tot-mx)+2*(n-1);
  if (res < 3) return 4-(tot%2);
  return res;
}

int main() {
  int n;
  scanf("%d",&n);
  vi A(n);
  cin>>A;
  int tot = suma(A);
  priority_queue<P> q;
  rep(i,n) q.push(P(A[i],i));
  int ans = g(tot,q.top().fi,n);
  vp to(n,P(-1,-1)); vi co(n);
  while (sz(q) > 1) {
    P a = q.top(); q.pop();
    P b = q.top(); q.pop();
    tot -= a.fi; tot -= b.fi;
    P c(f(a.fi,b.fi),sz(to));
    if (sz(q) && g(tot+c.fi,max(q.top().fi,c.fi),sz(q)+1) != ans) {
      int mx = q.top().fi;
      int now = mx - (tot+c.fi-mx) + 2*sz(q);
      assert(now-ans > 0);
      c.fi += now-ans;
    }
    to.pb(P(a.se,b.se));
    co.pb((a.fi+b.fi-c.fi)/2);
    q.push(c);
    // cerr<<a<<" "<<b<<" "<<c<<endl;
    tot += c.fi;
  }
  v(deque<int>) vs(sz(to));
  vvi ovs(n);
  int m = 0;
  rep(i,n) {
    rep(j,A[i]) vs[i].pb(m), ovs[i].pb(m++);
  }
  uf t(m);
  for (int i = n; i < sz(to); ++i) {
    int a = to[i].fi, b = to[i].se;
    int c = co[i];
    int tv = vs[a].back(), sv = -1;
    // cerr<<vs[a]<<endl;
    // cerr<<vs[b]<<endl;
    rep(j,c+1) {
      int na = vs[a].back(); vs[a].pop_back();
      int nb = vs[b].front(); vs[b].pop_front();
      t.unite(na,nb);
      sv = na;
    }
    // reverse(rng(vs[b]));
    vs[a].pb(sv);
    vs[a].insert(vs[a].end(), rng(vs[b]));
    vs[a].push_front(tv);
    swap(vs[a],vs[i]);
    // cerr<<vs[i]<<endl;
    // cerr<<"---"<<endl;
  }
  // assert(sz(vs.back()) == ans);
  X xs;
  rep(i,m) if (t.root(i) == i) xs.add(i);
  xs.init();
  printf("%d\n",sz(xs));
  rep(i,n) {
    rep(j,A[i]) ovs[i][j] = xs(t.root(ovs[i][j]))+1;
    priv(ovs[i]);
  }
  // cout<<"ok"<<endl;
  return 0;
}