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
inline int getInt() { int x; scanf("%d",&x); return x;}
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
#define yn {puts("Yes");}else{puts("No");}
const int MX = 200005;

// Union find
struct uf {
  vi d, w;
  uf(){}
  uf(int mx):d(mx,-1),w(mx){}
  int root(int x) {
    if(d[x] < 0) return x;
    return d[x] = root(d[x]);
  }
  bool unite(int x, int y) {
    x = root(x); y = root(y);
    if(x == y) return false;
    if(d[x] > d[y]) swap(x,y);
    w[x] += w[y];
    d[x] += d[y]; d[y] = x;
    return true;
  }
  bool same(int x, int y) { return root(x) == root(y);}
  int size(int x) { return -d[root(x)];}
  int operator[](int x) { return root(x);}
  int operator()(int x) { return w[root(x)];}
};
//



int main() {
  int n,m;
  scanf("%d%d",&n,&m);
  string s;
  cin>>s;
  vvi g(n);
  rep(i,m) {
    int k;
    scanf("%d",&k);
    vi a(k);
    cin>>a;
    rep(j,k) --a[j], g[a[j]].pb(i);
  }

  int ans = 0;
  uf t(m*2+2);
  int sv = m, tv = m*2+1;
  rep(i,m) t.w[m+1+i] = 1;
  t.w[tv] = INF;
  auto add = [&](int i) {
    i %= m+1;
    int w = min(t(i),t(m+1+i));
    ans += w;
  };
  auto del = [&](int i) {
    i %= m+1;
    int w = min(t(i),t(m+1+i));
    ans -= w;
  };
  auto join = [&](int a, int b) {
    // cerr<<a<<" "<<b<<endl;
    if (t.same(a,b)) return;
    del(a);
    del(b);
    t.unite(a,b);
    int ia = a<m+1?a+(m+1):a-(m+1);
    int ib = b<m+1?b+(m+1):b-(m+1);
    t.unite(ia,ib);
    add(a);
  };
  rep(i,m+1) add(i);
  rep(i,n) {
    int x = s[i]-'0';
    if (sz(g[i]) == 0) {
      assert(x);
    } else if (sz(g[i]) == 1) {
      int a = g[i][0];
      int ia = a+m+1;
      if (!x) swap(a,ia);
      join(a,sv);
    } else {
      int a = g[i][0], ia = a+m+1;
      int b = g[i][1], ib = b+m+1;
      if (!x) swap(b,ib);
      join(a,b);
    }
    printf("%d\n",ans);
  }
  return 0;
}