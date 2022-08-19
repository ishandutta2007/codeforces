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
#define dame { puts("No"); return 0;}
#define yn {puts("YES");}else{puts("NO");}
const int MX = 200005;

vi to[MX];

vp ans;
int dfs(int v, int p=-1) {
  vi s;
  for (int u : to[v]) {
    if (u == p) continue;
    int r = dfs(u,v);
    if (r == -1) return -1;
    s.pb(r);
  }
  if (sz(s) == 0) return v;
  if (p != -1 && sz(s)%2 == 0) return -1;
  for (int i = 0; i+1 < sz(s); i += 2) {
    ans.pb(P(s[i],s[i+1]));
  }
  return s.back();
}

int main() {
  int n;
  scanf("%d",&n);
  rep(i,n-1) {
    int a,b;
    scanf("%d%d",&a,&b);
    --a; --b;
    to[a].pb(b);
    to[b].pb(a);
  }
  if (n == 2) {
    cout<<"Yes"<<endl;
    cout<<1<<endl;
    cout<<1<<" "<<2<<endl;
    return 0;
  }

  // rep(i,n) {
  //   if (sz(to[i]) == 1) continue;
  //   int res = dfs(i);
  //   if (res == -1) {
  //     cout<<"No"<<endl;
  //   } else {
  //     puts("Yes");
  //     printf("%d\n",sz(ans));
  //     for (P p : ans) {
  //       printf("%d %d\n",p.fi+1,p.se+1);
  //     }
  //   }
  //   break;
  // }

  vi s;
  rep(i,n) {
    if (sz(to[i]) > 2) s.pb(i);
  }

  if (sz(s) > 1) dame;

  if (sz(s) == 0) s.pb(0);

  int v = s[0];
  vi l;
  rep(i,n) {
    if (i == v) continue;
    if (sz(to[i]) == 1) l.pb(i);
  }

  cout<<"Yes"<<endl;
  cout<<sz(l)<<endl;
  for (int u : l) {
    printf("%d %d\n",v+1,u+1);
  }
  return 0;
}