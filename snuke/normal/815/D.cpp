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
template<typename T>istream& operator>>(istream&i,vector<T>&v){rep(j,sz(v))i>>v[j];return i;}
template<typename T>string join(const vector<T>&v){stringstream s;rep(i,sz(v))s<<' '<<v[i];return s.str().substr(1);}
template<typename T>ostream& operator<<(ostream&o,const vector<T>&v){if(sz(v))o<<join(v);return o;}
template<typename T1,typename T2>istream& operator>>(istream&i,pair<T1,T2>&v){return i>>v.fi>>v.se;}
template<typename T1,typename T2>ostream& operator<<(ostream&o,const pair<T1,T2>&v){return o<<v.fi<<","<<v.se;}
const int MX = 500005, INF = 1001001001;
const ll LINF = 1e18;
const double eps = 1e-10;



typedef pair<int,int> pii;

struct cube {
  int p[3];
  cube(int x, int y, int z){
    p[0] = x;
    p[1] = y;
    p[2] = z;
  }
  bool operator<(const cube &c)const{ return p[2] > c.p[2];}
};

// int n;
// pii seq[MX];
vector<cube> cs;
set<pii> ps;

// void gen_cube() {
//   sort(seq, seq+n);
//   int l = 0, r = 0;
//   cube c(1,1,1);
//   while(r < n) {
//     c.p[seq[r].second]++;
//     while(l < r and seq[l].first*2 <= seq[r].first) c.p[seq[l++].second]--;
//     r++;
//     cs.push_back(c);
//   }
//   cs.push_back(cube(0,0,0));
//   sort(begin(cs),end(cs));
// }

long long solve() {
  // gen_cube();
  // for (cube a : cs) {
  //   cout<<a.p[0]<<" "<<a.p[1]<<" "<<a.p[2]<<endl;
  // }
  ps.insert(pii(0,1000000001));
  ps.insert(pii(1000000001,0));
  long long ans = 0, pz = 0, area = 0;
  for(auto &e: cs) {
    int x = e.p[0], y = e.p[1], z = e.p[2];
    ans += (pz-z)*area;
    pz = z;
    auto lb = ps.lower_bound(pii(x,y)), ub = lb;
    int py = lb->second, px = x;
    if(py >= y) continue;
    while(lb-- != begin(ps)) {
      int nx = lb->first, ny = lb->second;
      area += 1LL*(px-nx)*(y-py);
      if(ny > y) break;
      py = ny;
      px = nx;
    }
    ps.erase(++lb,ub);
    ps.insert(ub, pii(x,y));
  }

  // cerr<<ans<<endl;
  return ans;
}

// void input() {
//   cin >> n;
//   char c; int x, y;
//   for (int i = 0; i < n; i++) {
//     cin >> x >> c;
//     y = (c == 'R')? 0: (c == 'G')? 1: 2;
//     seq[i] = pii(x,y);
//   }
// }

int main() {
  int n;
  scanf("%d",&n);
  vi a(3);
  rep(i,3) scanf("%d",&a[i]);
  ll tot = 1;
  rep(i,3) tot *= a[i];
  rep(i,n) {
    vi b(3);
    rep(j,3) scanf("%d",&b[j]);
    rep(k,3) {
      vi c = b;
      c[k] = a[k];
      // cerr<<c<<endl;
      cs.push_back(cube(c[0],c[1],c[2]));
    }
  }
  cs.pb(cube(0,0,0));
  sort(rng(cs));
  ll ans = tot - solve();
  cout<<ans<<endl;
  return 0;
}