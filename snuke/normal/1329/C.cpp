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
inline void priv(vi a) { rep(i,sz(a)) printf("%d%c",a[i],i==sz(a)-1?'\n':' ');}

int n, m;
int n2, m2;
vi a;
vi ans;
bool can(int i) {
  if (!a[i]) return false;
  if (i >= m2) return true;
  int li = i<<1, ri = li|1;
  if (!a[li] && !a[ri]) return false;
  int ni = li;
  if (a[li] < a[ri]) ni = ri;
  return can(ni);
}
void pop(int i) {
  a[i] = 0;
  int li = i<<1, ri = li|1;
  if (li >= n2) return;
  if (!a[li] && !a[ri]) return;
  int ni = li;
  if (a[li] < a[ri]) ni = ri;
  a[i] = a[ni];
  return pop(ni);
}
void dfs(int v) {
  if (v >= n2) return;
  while (can(v)) {
    ans.pb(v);
    pop(v);
  }
  dfs(v<<1);
  dfs(v<<1|1);
}

void solve() {
  scanf("%d%d",&n,&m);
  n2 = 1<<n;
  m2 = 1<<m;
  a = vi(n2);
  rrep(i,n2-1) scanf("%d",&a[i]);
  ans = vi();
  dfs(1);
  printf("%lld\n",suma(a));
  priv(ans);
}

int main() {
  int ts;
  scanf("%d",&ts);
  rep(ti,ts) solve();
  return 0;
}