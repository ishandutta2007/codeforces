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
typedef long long ll;
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
#define dame { puts("-1"); return;}
#define yn {puts("YES");}else{puts("NO");}
const int MX = 2005;

// bitset
typedef unsigned long long ull;
int bsf(ull x) { return __builtin_ctzll(x);}
struct bs {
  int n;
  v(ull) d;
  bs() {};
  bs(int n, int x=0):n(n), d((n+63)/64,x?~0ull:0) {
    if (n&63) d.back() &= (1ull<<(n&63))-1;
  }
  int get(int i) { return d[i>>6]>>(i&63)&1;}
  void set(int i) { d[i>>6] |= 1ull<<(i&63);}
  void unset(int i) { d[i>>6] &= ~(1ull<<(i&63));}
  void set(int i, int x) { x?set(i):unset(i);}
  void flip(int i) { d[i>>6] ^= 1ull<<(i&63);}
  void flip() { rep(i,sz(d)) d[i] ^= ~0ull;}
  bs& operator&=(const bs& a) { rep(i,sz(d)) d[i] &= a.d[i]; return *this;}
  bs& operator|=(const bs& a) { rep(i,sz(d)) d[i] |= a.d[i]; return *this;}
  bs& operator^=(const bs& a) { rep(i,sz(d)) d[i] ^= a.d[i]; return *this;}
  bs operator&(const bs& a) const { return bs(*this) &= a;}
  bs operator|(const bs& a) const { return bs(*this) |= a;}
  bs operator^(const bs& a) const { return bs(*this) ^= a;}
  int count() const {
    int res = 0;
    rep(i,sz(d)) res += __builtin_popcountll(d[i]);
    return res;
  }
  int first() {
    rep(i,sz(d)) if (d[i]) {
      return i<<6 | bsf(d[i]);
    }
    return -1;
  }
};
ostream& operator<<(ostream& o, const bs& a) {
  rep(i,a.n) o << (a.d[i>>8]>>(i&63)&1);
  return o;
}
//

char ins[MX];

struct Solver {
  void solve() {
    int n,m;
    scanf("%d%d",&n,&m);
    bs all(n,1);
    v(bs) a(m,bs(n)), d(n,bs(n,1));
    rep(i,m) {
      scanf("%s",ins);
      rep(j,n) if (ins[j]-'0') a[i].set(j);
    }
    rep(i,n) {
      d[i].unset(i);
      rep(j,m) if (a[j].get(i)) d[i] &= a[j];
    }

    vi live(m,1);
    auto re = [&](int i) {
      d[i] = all;
      d[i].unset(i);
      rep(j,m) if (live[j]) {
        if (a[j].get(i)) d[i] &= a[j];
      }
    };
    auto rm = [&] {
      rep(i,m) if (live[i]) {
        if (a[i].count() == 1) {
          live[i] = 0;
          re(a[i].first());
        }
      }
    };
    vi p(n,-1);
    bool up = true;
    while (up) {
      up = false;
      rm();
      rep(i,n) if (p[i] == -1) {
        int u = d[i].first();
        if (u == -1) continue;
        p[i] = u;
        rep(j,n) d[j].unset(i);
        rep(j,m) a[j].unset(i);
        all.unset(i);
        up = true;
        break;
      }
    }
    if (suma(live)) {
      puts("NO");
      return;
    }
    puts("YES");
    int root = 0;
    rep(i,n) if (p[i] == -1) root = i;
    rep(i,n) if (i != root) {
      if (p[i] == -1) p[i] = root;
      printf("%d %d\n",i+1,p[i]+1);
    }
  }
};

int main() {
  int ts;
  scanf("%d",&ts);
  rrep(ti,ts) {
    Solver solver;
    solver.solve();
  }
  return 0;
}