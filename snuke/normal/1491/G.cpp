#include <bits/stdc++.h>
#define fi first
#define se second
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
#define srep(i,s,t) for (int i = s; i < t; ++i)
#define rng(a) a.begin(),a.end()
#define rrng(a) a.rbegin(),a.rend()
#define isin(x,l,r) ((l) <= (x) && (x) < (r))
#define pb push_back
#define eb emplace_back
#define sz(x) (int)(x).size()
#define pcnt __builtin_popcountll
#define uni(x) x.erase(unique(rng(x)),x.end())
#define snuke srand((unsigned)clock()+(unsigned)time(NULL));
#define show(x) cerr<<#x<<" = "<<x<<endl;
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
int getInt(){int x;scanf("%d",&x);return x;}
template<typename T>istream& operator>>(istream&i,v(T)&v){rep(j,sz(v))i>>v[j];return i;}
template<typename T>string join(const v(T)&v){stringstream s;rep(i,sz(v))s<<' '<<v[i];return s.str().substr(1);}
template<typename T>ostream& operator<<(ostream&o,const v(T)&v){if(sz(v))o<<join(v);return o;}
template<typename T1,typename T2>istream& operator>>(istream&i,pair<T1,T2>&v){return i>>v.fi>>v.se;}
template<typename T1,typename T2>ostream& operator<<(ostream&o,const pair<T1,T2>&v){return o<<v.fi<<","<<v.se;}
template<typename T>bool mins(T& x,const T&y){if(x>y){x=y;return true;}else return false;}
template<typename T>bool maxs(T& x,const T&y){if(x<y){x=y;return true;}else return false;}
template<typename T>ll suma(const v(T)&a){ll res(0);for(auto&&x:a)res+=x;return res;}
const double eps = 1e-10;
const ll LINF = 1001002003004005006ll;
const int INF = 1001001001;
#define dame { puts("0"); return;}
#define yn {puts("Yes");}else{puts("No");}
const int MX = 200005;

struct Solver {
  void solve() {
    int n;
    scanf("%d",&n);
    vi a(n);
    cin>>a;
    rep(i,n) --a[i];
    vvi c;
    vi used(n);
    int one = -1;
    rep(i,n) if (!used[i]) {
      int j = i;
      c.pb(vi());
      while (!used[j]) {
        c.back().pb(j);
        used[j] = 1;
        j = a[j];
      }
      if (sz(c.back()) == 1) {
        one = c.back()[0];
        c.pop_back();
      }
    }
    sort(rng(c), [&](const vi& a, const vi& b) { return sz(a) < sz(b);});
    vi o = a;
    vp ans;
    while (sz(c) >= 2) {
      vi a = c.back(); c.pop_back();
      vi b = c.back(); c.pop_back();
      ans.eb(a[0],b[0]);
      srep(i,1,sz(a)) ans.eb(a[i],b[0]);
      srep(i,1,sz(b)) ans.eb(b[i],a[0]);
      ans.eb(a[0],b[0]);
      one = a[0];
    }
    if (sz(c)) {
      vi a = c.back();
      c.pop_back();
      // if (sz(a) == 2) {
      //   if (one == -1) {
      //     vi b = c.back(); c.pop_back();
      //     ans.eb(a[0],b[0]);
      //     ans.eb(a[0],b[1]);
      //     ans.eb(a[1],b[0]);
      //     p = P(a[0],b[0]);
      //   } else {
      //     ans.eb(a[0],one);
      //     ans.eb(a[1],one);
      //     p = P(a[0],one);
      //   }
      // } else {
      //   ans.eb(a[0],a[1]);
      //   int r = sz(a)-1;
      //   srep(i,2,r) ans.eb(a[0],a[i]);
      //   ans.eb(a[1],a[r]);
      //   ans.eb(a[0],a[r]);
      //   p = P(a[0],a[1]);
      // }
      if (sz(a) == 2) {
        assert(one != -1);
        ans.eb(a[0],one);
        ans.eb(a[1],one);
        ans.eb(a[0],one);
      } else {
        ans.eb(a[0],a[1]);
        int r = sz(a)-1;
        srep(i,2,r) ans.eb(a[0],a[i]);
        ans.eb(a[1],a[r]);
        ans.eb(a[0],a[r]);
        ans.eb(a[0],a[1]);
      }
    }
    cout<<sz(ans)<<endl;
    for (P p : ans) cout<<p.fi+1<<" "<<p.se+1<<endl;
  }
};

int main() {
  int ts = 1;
  // scanf("%d",&ts);
  rrep(ti,ts) {
    Solver solver;
    solver.solve();
  }
  return 0;
}