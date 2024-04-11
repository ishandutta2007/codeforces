#include <bits/stdc++.h>
#define fi first
#define se second
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
#define gep(i,g,j) for(int i = g.head[j]; i != -1; i = g.e[i].next)
#define each(it,c) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define rng(a) a.begin(),a.end()
#define maxs(x,y) x = max(x,y)
#define mins(x,y) x = min(x,y)
#define pb push_back
#define sz(x) (int)(x).size()
#define pcnt __builtin_popcount
#define uni(x) x.erase(unique(rng(x)),x.end())
#define snuke srand((unsigned)clock()+(unsigned)time(NULL));
#define df(x) int x = in()
#define dame { puts("-1"); return 0;}
#define show(x) cout<<#x<<" = "<<x<<endl;
#define PQ(T) priority_queue<T,vector<T>,greater<T> >
#define bn(x) ((1<<x)-1)
#define newline puts("")
#define v(T) vector<T>
#define vv(T) vector<vector<T>>
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
inline void priv(vi a) { rep(i,sz(a)) printf("%d%c",a[i],i==sz(a)-1?'\n':' ');}
template<typename T>istream& operator>>(istream&i,vector<T>&v)
{rep(j,sz(v))i>>v[j];return i;}
template<typename T>string join(const vector<T>&v)
{stringstream s;rep(i,sz(v))s<<' '<<v[i];return s.str().substr(1);}
template<typename T>ostream& operator<<(ostream&o,const vector<T>&v)
{if(sz(v))o<<join(v);return o;}
template<typename T1,typename T2>istream& operator>>(istream&i,pair<T1,T2>&v)
{return i>>v.fi>>v.se;}
template<typename T1,typename T2>ostream& operator<<(ostream&o,const pair<T1,T2>&v)
{return o<<v.fi<<","<<v.se;}
const int MX = 100005, INF = 1001001001;
const ll LINF = 1e18;
const double eps = 1e-10;

// Suffix array
struct SA {
  string s;
  int n;
  vi id, rnk;
  
  void cons() {
    s += '$';
    n = sz(s);
    id = rnk = vi(n);
    vi tmp(n);
    rep(i,n) id[i] = i, rnk[i] = s[i];
    int k;
    auto comp = [&](int i, int j) {
      if(rnk[i] != rnk[j]) return rnk[i] < rnk[j];
      int ri = i + k < sz(rnk) ? rnk[i + k] : -1;
      int rj = j + k < sz(rnk) ? rnk[j + k] : -1;
      return ri < rj;
    };
    for (k = 1; k < n; k<<=1) {
      sort(rng(id),comp);
      tmp[id[0]] = 0;
      for (int i = 1; i < n; ++i) tmp[id[i]] = tmp[id[i-1]] + comp(id[i-1],id[i]);
      rnk = tmp;
    }
    cons_lcp();
  }

  //* lcp
  vi b;
  void cons_lcp() {
    vi& lcp = b;
    lcp = vi(n);
    int h = 0;
    rep(i,n-1){
      int j = id[rnk[i]-1];
      if(h > 0) h--;
      for(; i+h < n && j+h < n && s[i+h] == s[j+h]; h++);
      lcp[rnk[i]-1] = h;
    }
  }
  //*/

  void solve() {
    --n;
    vi a(n);
    rep(i,n) a[rnk[i]-1] = n-i;
    a.pb(0); ++n;
    // cerr<<a<<endl;
    // cerr<<b<<endl;

    ll ans = 0;
    vp s(1,P(0,0));
    rep(i,n) {
      int x = b[i];
      while (s.back().fi > x) {
        P p = s.back(); s.pop_back();
        ll h = p.fi-s.back().fi;
        ll w = i-p.se;
        if (s.back().fi <= x) {
          h = p.fi-x;
          if (x > s.back().fi) {
            s.pb(P(x,p.se));
          }
        }
        ans += w*w*h;
      }
      if (s.back().fi != a[i]) s.pb(P(a[i],i));
      // cerr<<i<<": "<<ans<<endl;
      // cerr<<s<<endl;
    }
    cout<<ans<<endl;
  }
};
//



int main() {
  int ts;
  scanf("%d",&ts);
  rep(ti,ts) {
    SA sa;
    cin>>sa.s;
    sa.cons();
    sa.solve();
  }
  return 0;
}