#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
#define srep(i,s,t) for (int i = s; i < (t); ++i)
#define rng(a) a.begin(),a.end()
#define rrng(a) a.rbegin(),a.rend()
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define sz(x) (int)(x).size()
#define pcnt __builtin_popcountll
#define snuke srand((unsigned)clock()+(unsigned)time(NULL));
#define newline puts("")
using namespace std;
template<typename T> using vc = vector<T>;
template<typename T> using vv = vc<vc<T>>;
template<typename T> using PQ = priority_queue<T,vc<T>,greater<T>>;
using uint = unsigned; using ull = unsigned long long;
using vi = vc<int>; using vvi = vv<int>;
using ll = long long; using vl = vc<ll>; using vvl = vv<ll>;
using P = pair<int,int>; using vp = vc<P>;
int getInt(){int x;scanf("%d",&x);return x;}
vi pm(int n, int s=0) { vi a(n); iota(rng(a),s); return a;}
template<typename T>istream& operator>>(istream&i,vc<T>&v){rep(j,sz(v))i>>v[j];return i;}
template<typename T>string join(const T&v,const string& d=""){stringstream s;rep(i,sz(v))(i?s<<d:s)<<v[i];return s.str();}
template<typename T>ostream& operator<<(ostream&o,const vc<T>&v){if(sz(v))o<<join(v," ");return o;}
template<typename T1,typename T2>istream& operator>>(istream&i,pair<T1,T2>&v){return i>>v.fi>>v.se;}
template<typename T1,typename T2>ostream& operator<<(ostream&o,const pair<T1,T2>&v){return o<<v.fi<<","<<v.se;}
template<typename T1,typename T2>bool mins(T1& x,const T2&y){if(x>y){x=y;return true;}else return false;}
template<typename T1,typename T2>bool maxs(T1& x,const T2&y){if(x<y){x=y;return true;}else return false;}
template<typename Tx, typename Ty>Tx dup(Tx x, Ty y){return (x+y-1)/y;}
template<typename T>ll suma(const vc<T>&a){ll res(0);for(auto&&x:a)res+=x;return res;}
template<typename T>ll suma(const vv<T>&a){ll res(0);for(auto&&x:a)res+=suma(x);return res;}
template<typename T>void uni(T& a){sort(rng(a));a.erase(unique(rng(a)),a.end());}
const double eps = 1e-10;
const ll LINF = 1001002003004005006ll;
const int INF = 1001001001;
#define dame { puts("-1"); return;}
#define yes { puts("Yes"); return;}
#define no { puts("No"); return;}
#define yn {puts("Yes");}else{puts("No");}
const int MX = 200005;
template<typename T> int lwb(const vector<T>& a, const T& x) { return lower_bound(rng(a), x) - a.begin();}
template<typename T> int upb(const vector<T>& a, const T& x) { return upper_bound(rng(a), x) - a.begin();}

struct Solver {
  void solve() {
    int n;
    scanf("%d",&n);
    vi a(n);
    cin>>a;
    sort(rng(a));
    int ans = 0;
    rep(si,n-1) {
      int s = a[si];
      int j = upb(a,s);
      int now = j-si;
      if (j != n) {
        ++now;
        while (1) {
          j = lower_bound(a.begin()+j+1, a.end(), a[j]*2-s) - a.begin();
          if (j == n) break;
          ++now;
        }
      }
      maxs(ans,now);
    }
    ans = n-ans;
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