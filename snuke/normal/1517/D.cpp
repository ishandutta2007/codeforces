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
template<typename T>string join(const vc<T>&v,const string& d=""){stringstream s;rep(i,sz(v))(i?s<<d:s)<<v[i];return s.str();}
template<typename T>ostream& operator<<(ostream&o,const vc<T>&v){if(sz(v))o<<join(v," ");return o;}
template<typename T1,typename T2>istream& operator>>(istream&i,pair<T1,T2>&v){return i>>v.fi>>v.se;}
template<typename T1,typename T2>ostream& operator<<(ostream&o,const pair<T1,T2>&v){return o<<v.fi<<","<<v.se;}
vc<string> split(const string& s,char d=' '){vc<string> r(1);for(char c:s)if(c==d)r.pb("");else r.back()+=c;return r;}
string operator*(const string& s,int t){return join(vc<string>(t,s));}
template<typename T>bool mins(T& x,const T&y){if(x>y){x=y;return true;}else return false;}
template<typename T>bool maxs(T& x,const T&y){if(x<y){x=y;return true;}else return false;}
template<typename T>T dup(T x, T y){return (x+y-1)/y;}
template<typename T>ll suma(const vc<T>&a){ll res(0);for(auto&&x:a)res+=x;return res;}
template<typename T>void uni(vc<T>& a){sort(rng(a));a.erase(unique(rng(a)),a.end());}
const double eps = 1e-10;
const ll LINF = 1001002003004005006ll;
const int INF = 1001001001;
#define dame { puts("-1"); return;}
#define yn {puts("Yes");}else{puts("No");}
const int MX = 200005;
const int di[] = {-1,0,0,1}, dj[] = {0,1,-1,0}; //^<v>


struct Solver {
  void solve() {
    int h,w,n;
    scanf("%d%d%d",&h,&w,&n);
    vvi ans(h,vi(w,-1));
    if (n%2) {
      cout<<ans<<endl;
      return;
    }
    n /= 2;
    vvi cw(h,vi(w-1));
    cin>>cw;
    vvi ch(h-1,vi(w));
    cin>>ch;
    int h2 = h*2-1;
    int w2 = w*2-1;
    vvi co(h2,vi(w2));
    rep(i,h)rep(j,w-1) co[i*2][j*2+1] = cw[i][j];
    rep(i,h-1)rep(j,w) co[i*2+1][j*2] = ch[i][j];
    // rep(si,h)rep(sj,w) {
    //   vvi d(n+1,vi(n+1, INF));
    //   // rrep(k,n) {
    //   //   vvi p(k+1,vi(k+1,INF));
    //   //   swap(d,p);
    //   //   rep(i,k)rep(j,k) {
    //   //     int mi = si+(i+j)-k+1;
    //   //     int mj = sj+(j-i);
    //   //     mi *= 2;
    //   //     mj *= 2;
    //   //     rep(v,4) {
    //   //       int ni = mi+di[v], nj = mj+dj[v];
    //   //       if (ni<0||nj<0||ni>=h2||nj>=w2) continue;
    //   //       mins(d[i+(v/2)][j+(v%2)], p[i][j]+co[ni][nj]);
    //   //     }
    //   //   }
    //   // }
    //   PQ<P> q;
    //   int now = INF;
    //   // rep(i,n+1)rep(j,n+1) mins(now, d[i][j]);
    //   auto push = [&](int i, int j, int x) {
    //     if (d[i][j] <= x) continue;
    //     d[i][j] = x;
    //     q.emplace(x, i*w+j);
    //   };
    //   while (sz(q)) {
    //     auto [x,ij] = q.front(); q.pop();
    //     int i = ij/w, j = ij%w;

    //     int mi = si+(i+j)-n;
    //     int mj = sj+(j-i);
    //     mi *= 2;
    //     mj *= 2;
    //     rep(v,4) {
    //       int ni = mi+di[v], nj = mj+dj[v];
    //       if (ni<0||nj<0||ni>=h2||nj>=w2) continue;
    //       push(i+(v/2), j+(v%2), p[i][j]+co[ni][nj]);
    //     }
    //   }
    //   ans[si][sj] = now*2;
    // }

    rep(i,h)rep(j,w) ans[i][j] = 0;
    rep(k,n) {
      vvi p(h,vi(w, INF));
      swap(ans, p);
      rep(i,h)rep(j,w) {
        rep(v,4) {
          int ni = i+di[v], nj = j+dj[v];
          if (ni<0||nj<0||ni>=h||nj>=w) continue;
          int mi = i*2+di[v], mj = j*2+dj[v];
          int c = co[mi][mj]*2;
          mins(ans[i][j], p[ni][nj]+c);
        }
      }
    }
    cout<<ans<<endl;
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