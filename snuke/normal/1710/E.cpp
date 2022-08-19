#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rep1(i,n) for(int i = 1; i <= (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
#define srep(i,s,t) for (int i = s; i < (t); ++i)
#define rng(a) a.begin(),a.end()
#define rrng(a) a.rbegin(),a.rend()
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define pob pop_back
#define sz(x) (int)(x).size()
#define pcnt __builtin_popcountll
#define snuke srand((unsigned)clock()+(unsigned)time(NULL));
#define newline puts("")
using namespace std;
template<typename T> using vc = vector<T>;
template<typename T> using vv = vc<vc<T>>;
template<typename T> using PQ = priority_queue<T,vc<T>,greater<T>>;
using uint = unsigned; using ull = unsigned long long;
using vi = vc<int>; using vvi = vv<int>; using vvvi = vv<vi>;
using ll = long long; using vl = vc<ll>; using vvl = vv<ll>; using vvvl = vv<vl>;
using P = pair<ll,int>; using vp = vc<P>; using vvp = vv<P>;
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
template<typename T>void prepend(vc<T>&a,const T&x){a.insert(a.begin(),x);}
const double eps = 1e-10;
const ll LINF = 1001002003004005006ll;
const int INF = 1001001001;
#define dame { puts("-1"); return;}
#define yes { puts("Yes"); return;}
#define no { puts("No"); return;}
#define ret(x) { cout<<(x)<<endl; return;}
#define yn {puts("Yes");}else{puts("No");}
const int MX = 200005;
#define bis(_ac,_wa,_f) [&]{ll ac=_ac,wa=_wa;while(abs(ac-wa)>1){ll wj=(ac+wa)/2;(_f(wj)?ac:wa)=wj;}return ac;}()

struct Solver {
  void solve() {
    int n,m;
    scanf("%d%d",&n,&m);
    vi a(n), b(m);
    cin>>a>>b;
    int ai = 0, bi = 0;
    {
      int na = a[0], nb = b[0];
      sort(rng(a));
      sort(rng(b));
      rep(i,n) if (a[i] == na) ai = i;
      rep(i,m) if (b[i] == nb) bi = i;
    }
    auto f = [&](int x) -> bool {
      if (a[ai]+b[bi] <= x) return true;
      vi l(n), bl(m);
      {
        int j = m;
        rep(i,n) {
          while (j && a[i]+b[j-1] > x) --j;
          l[i] = j;
        }
      }
      {
        int j = n;
        rep(i,m) {
          while (j && b[i]+a[j-1] > x) --j;
          bl[i] = j;
        }
      }
      P best;
      {
        ll s = 0;
        rep(i,n) s += m-l[i];
        int j = 0;
        auto g = [&](int j, int nl, int nn) {
          return min(j,nl) - min(nn-j,nn-nl);
        };
        auto h = [&](int i, int j) {
          return !(i<=ai&&j<=bi);
        };
        best = P(s,0);
        rep(i,n) {
          s += g(j,l[i],m);
          maxs(best, P(s,h(i+1,j)));
          while (j < m && g(i+1,bl[j],n) >= 0) {
            s += g(i+1,bl[j],n);
            j++;
            maxs(best, P(s,h(i+1,j)));
          }
        }
      }
      return best.se;
    };
    cout<<bis(INF,0,f)<<endl;
  }
};

int main() {
  int ts = 1;
  // scanf("%d",&ts);
  rep1(ti,ts) {
    Solver solver;
    solver.solve();
  }
  return 0;
}