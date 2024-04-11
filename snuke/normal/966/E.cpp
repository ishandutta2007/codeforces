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
const int MX = 100005;

// coordinate compression
struct X {
  typedef int T;
  vector<T> d;
  X() {}
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

const int D = 400, D2 = D*2+1;

vi to[MX];
vi pa, x;
vi va;

vi gi;
vi eve;
vi gp;
vvi gd;
vi gx;

int dfs(int v) {
  int g = -1, cnt = 0;
  if (eve[v]) {
    gi[v] = sz(gp);
    gp.pb(-1);
    gd.pb(vi(D2));
    g = gi[v];
    cnt = 2;
  }
  for (int u : to[v]) {
    int r = dfs(u);
    if (r == -1) continue;
    if (g != -1) {
      if (cnt == 1) {
        gi[v] = sz(gp);
        gp[g] = gi[v];
        gp.pb(-1);
        gd.pb(vi(D2));
        g = gi[v];
      }
      gp[r] = g;
      cnt = 2;
    } else {
      gi[v] = r;
      g = r;
      cnt = 1;
    }
  }
  if (g != -1 && !va[v] && abs(x[v]) <= D) {
    gd[g][x[v]+D]++;
  }
  return g;
}

int main() {
  int n,q;
  scanf("%d%d",&n,&q);
  pa = vi(n,-1);
  rrep(i,n-1) {
    int p;
    scanf("%d",&p);
    --p;
    pa[i] = p;
    to[p].pb(i);
  }
  x = vi(n);
  cin>>x;
  vp qs;
  rep(qi,q) {
    int v;
    scanf("%d",&v);
    if (v < 0) {
      v = -v-1;
      qs.pb(P(v,1));
    } else {
      v--;
      qs.pb(P(v,-1));
    }
  }

  va = vi(n);
  int ans = 0;
  vi as;

  for (int si = 0; si < q; si += D) {
    int ti = min(si+D,q);
    eve = vi(n);
    gi = vi(n,-1);
    srep(i,si,ti) eve[qs[i].fi] = 1;
    gp = vi(); gd = vvi();
    dfs(0);
    gx = vi(sz(gp));
    // cerr<<gi<<endl;
    // cerr<<gp<<endl;
    srep(i,si,ti) {
      int v = qs[i].fi;
      int g = gi[v];
      int a = qs[i].se;
      while (g != -1) {
        if (a == -1) {
          ans += gd[g][D-gx[g]];
          if (v != -1) {
            if (abs(x[v]) <= D) {
              gd[g][x[v]+D]--;
            }
            if (x[v]+gx[g] <= 0) ans--;
            va[v] = 1;
          }
        }
        gx[g] += a;
        if (a == 1) {
          ans -= gd[g][D-gx[g]];
          if (v != -1) {
            if (abs(x[v]) <= D) {
              gd[g][x[v]+D]++;
            }
            if (x[v]+gx[g] < 0) ans++;
            va[v] = 0;
          }
        }
        g = gp[g]; v = -1;
        // cerr<<g<<" "<<ans<<endl;
      }
      as.pb(ans);
    }
    rep(i,n) if (gi[i] != -1) x[i] += gx[gi[i]];
    // cerr<<x<<endl;
    // cerr<<va<<endl;
  } 
  cout<<as<<endl;
  return 0;
}