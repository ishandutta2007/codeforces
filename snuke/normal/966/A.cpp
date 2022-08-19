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



int main() {
  int n,m,s,t,v;
  scanf("%d%d%d%d%d",&n,&m,&s,&t,&v);
  vi xs(s);
  cin>>xs;
  vi xt(t);
  cin>>xt;
  sort(rng(xs));
  sort(rng(xt));
  int q;
  scanf("%d",&q);
  rep(qi,q) {
    int l,sj,r,tj;
    scanf("%d%d%d%d",&sj,&l,&tj,&r);
    int y = abs(sj-tj);
    if (r < l) swap(l,r);
    int ans = INF;
    if (!y) {
      ans = r-l;
    } else {
      {
        auto f = [&](int x) {
          int now = abs(r-x)+abs(x-l)+y;
          mins(ans,now);
        };
        rep(ti,2) {
          int x = ti?l:r;
          int i = lower_bound(rng(xs),x)-xs.begin();
          if (i < sz(xs)) f(xs[i]);
          if (i) f(xs[i-1]);
        }
      }
      {
        auto f = [&](int x) {
          int now = abs(r-x)+abs(x-l)+(dup(y,v));
          mins(ans,now);
        };
        rep(ti,2) {
          int x = ti?l:r;
          int i = lower_bound(rng(xt),x)-xt.begin();
          if (i < sz(xt)) f(xt[i]);
          if (i) f(xt[i-1]);
        }
      }
    }
    printf("%d\n",ans);
  }
  return 0;
}