#include <bits/stdc++.h>
#define fi first
#define se second
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
#define srep(i,s,t) for (int i = s; i < (t); ++i)
#define dsrep(i,t,s) for(int i = (t)-1; i >= (s); --i)
#define rng(a) a.begin(),a.end()
#define rrng(a) a.rbegin(),a.rend()
#define isin(x,l,r) ((l) <= (x) && (x) < (r))
#define pb push_back
#define eb emplace_back
#define sz(x) (int)(x).size()
#define pcnt __builtin_popcountll
#define snuke srand((unsigned)clock()+(unsigned)time(NULL));
#define show(x) cerr<<#x<<" = "<<x<<endl;
#define bn(x) ((1<<(x))-1)
#define newline puts("")
using namespace std;
template<typename T> using vc = vector<T>;
template<typename T> using vv = vc<vc<T>>;
template<typename T> using PQ = priority_queue<T,vc<T>,greater<T> >;
using ll = long long;
using uint = unsigned;
using ull = unsigned long long;
using P = pair<int,int>;
using T3 = tuple<int,int,int>;
using vi = vc<int>;
using vvi = vv<int>;
using vl = vc<ll>;
using vp = vc<P>;
using vt = vc<T3>;
int getInt(){int x;scanf("%d",&x);return x;}
vi pm(int n, int s=0) { vi a(n); iota(rng(a),s); return a;}
template<typename T>istream& operator>>(istream&i,vc<T>&v){rep(j,sz(v))i>>v[j];return i;}
template<typename T>string join(const T&v,const string& d=""){stringstream s;rep(i,sz(v))(i?s<<d:s)<<v[i];return s.str();}
template<typename T>ostream& operator<<(ostream&o,const vc<T>&v){if(sz(v))o<<join(v," ");return o;}
template<typename T1,typename T2>istream& operator>>(istream&i,pair<T1,T2>&v){return i>>v.fi>>v.se;}
template<typename T1,typename T2>ostream& operator<<(ostream&o,const pair<T1,T2>&v){return o<<v.fi<<","<<v.se;}
vc<string> split(const string& s,char d=' '){vc<string> r(1);for(char c:s)if(c==d)r.pb("");else r.back()+=c;return r;}
string operator*(const string& s,int t){return join(vc<string>(t,s));}
template<typename T1,typename T2>bool mins(T1& x,const T2&y){if(x>y){x=y;return true;}else return false;}
template<typename T1,typename T2>bool maxs(T1& x,const T2&y){if(x<y){x=y;return true;}else return false;}
template<typename Tx, typename Ty>Tx dup(Tx x, Ty y){return (x+y-1)/y;}
template<typename T>ll suma(const vc<T>&a){ll res(0);for(auto&&x:a)res+=x;return res;}
template<typename T>void uni(T& a){sort(rng(a));a.erase(unique(rng(a)),a.end());}
const double eps = 1e-10;
const ll LINF = 1001002003004005006ll;
const int INF = 1001001001;
#define dame { puts("-1"); return;}
#define yn {puts("Yes");}else{puts("No");}
const int MX = 200005;
using vvp = vc<vp>;

struct Solver {
  void solve() {
    int n,m;
    scanf("%d%d",&n,&m);
    vi a(n);
    cin>>a;
    sort(rng(a));
    vp pp(m);
    cin>>pp;
    rep(i,m) pp[i].se *= -1;
    sort(rng(pp));
    rep(i,m) pp[i].se *= -1;
    {
      vp p;
      for (auto [l,r] : pp) {
        while (sz(p) && p.back().se >= r) p.pop_back();
        p.eb(l,r);
      }
      swap(pp,p);
    }
    vvp ds(1);
    {
      int ai = 0;
      for (auto [l,r] : pp) {
        while (ai < n && a[ai] < l) {
          ds.back().eb(P(a[ai],a[ai]));
          ds.pb(vp(1,P(a[ai],a[ai])));
          ++ai;
        }
        if (ai < n && l <= a[ai] && a[ai] <= r) continue;
        ds.back().eb(l,r);
      }
      while (ai < n) {
        ds.back().eb(P(a[ai],a[ai]));
        ds.pb(vp(1,P(a[ai],a[ai])));
        ++ai;
      }
    }
    vl dp(2,LINF);
    {
      ll x = a[0]-ds[0][0].se;
      dp[0] = x*2;
      dp[1] = x;
    }
    srep(ai,1,n) {
      vp nd = ds[ai];
      int s = sz(nd);
      int la = a[ai-1];
      int ra = a[ai];
      vl p(2,LINF);
      swap(dp,p);
      rep(l,2)rep(r,2) {
        ll now = LINF;
        if (s == 0) now = 0;
        else {
          ll lx = l+1, rx = 2-r;
          rep(i,s-1) {
            ll cur = (nd[i].fi-la)*lx;
            cur += (ra-nd[i+1].se)*rx;
            mins(now, cur);
          }
        }
        mins(dp[r], p[l]+now);
      }
    }
    ll ans = LINF;
    {
      vp nd = ds.back();
      ll x = nd.back().fi-a.back();
      mins(ans, dp[0]+x);
      mins(ans, dp[1]+x*2);
    }
    cout<<ans<<endl;
  }
};

int main() {
  int ts = 1;
  scanf("%d",&ts);
  rrep(ti,ts) {
    Solver solver;
    solver.solve();
  }
  return 0;
}