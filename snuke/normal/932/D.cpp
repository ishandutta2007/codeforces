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
{return o<<v.fi<<","<<v.se;}
template<typename T>inline ll suma(const v(T)& a) { ll res(0); for (auto&& x : a) res += x; return res;}
const double eps = 1e-10;
const ll LINF = 1001002003004005006ll;
const int INF = 1001001001;
#define dame { puts("-1"); return 0;}
#define yn {puts("Yes");}else{puts("No");}
const int MX = 200005;
typedef v(vl) vvl;

const int M = 20;

vvi p;
vvl s;
vl W;

int main() {
  int q;
  scanf("%d",&q);
  int last = 0;
  p.pb(vi());
  s.pb(vl());
  W.pb(0);
  rep(qi,q) {
    int ty;
    scanf("%d",&ty);
    if (ty == 1) {
      ll r, w;
      scanf("%lld%lld",&r,&w);
      r ^= last;
      w ^= last;
      --r;
      int v = sz(p);
      if (W[r] < w) {
        drep(i,M) {
          if (sz(p[r]) <= i) continue;
          if (W[p[r][i]] < w) r = p[r][i];
        }
        if (sz(p[r])) r = p[r][0];
        else r = -1;
      }
      vi np;
      vl ns;
      if (r != -1) {
        np.pb(r);
        ns.pb(W[r]);
        rep(i,M) {
          if (sz(p[r]) <= i) break;
          ns.pb(ns.back()+s[r][i]);
          r = p[r][i];
          np.pb(r);
        }
      }
      p.pb(np);
      s.pb(ns);
      W.pb(w);
    } else {
      ll r, w;
      scanf("%lld%lld",&r,&w);
      r ^= last;
      w ^= last;
      --r;
      int ans = 0;
      if (W[r] <= w) {
        w -= W[r];
        ans = 1;
        drep(i,M) {
          if (sz(p[r]) <= i) continue;
          if (s[r][i] <= w) {
            w -= s[r][i];
            r = p[r][i];
            ans += 1<<i;
          }
        }
      }
      printf("%d\n",ans);
      last = ans;
    }
  }
  return 0;
}