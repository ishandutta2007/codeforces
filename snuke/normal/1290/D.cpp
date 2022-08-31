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
inline int getInt() { int x; scanf("%d",&x); return x;}
template<typename T>inline istream& operator>>(istream&i,v(T)&v)
{rep(j,sz(v))i>>v[j];return i;}
template<typename T>string join(const v(T)&v)
{stringstream s;rep(i,sz(v))s<<','<<v[i];return s.str().substr(1);}
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
random_device _rd;
struct xrand {
  static const uint64_t _x = 88172645463325252ull;
  uint64_t x;
  xrand(): x(_x ^ (_rd()+time(0))) {}
  xrand(uint64_t seed): x(_x ^ seed) {}
  uint64_t get() {
    x = x ^ (x << 7);
    return x = x ^ (x >> 9);
  }
  int operator()(int n) { return get()%n;}
  int operator()(int l, int r) { return get()%(r-l+1) + l;}
} rnd;

int n, k, m;


//*
void init() {}
void reset() {
  cout<<"R"<<endl;
}
bool f(int x) {
  ++x;
  cout<<"?"<<" "<<x<<endl;
  char c;
  cin>>c;
  return c == 'Y';
}
void answer(int x) {
  cout<<"!"<<" "<<x<<endl;
}
/*/
vi A;
int counter;
void init() {
  rep(i,n) A.pb(rnd(n));
  cout<<A<<endl;
  A = {3,5,14,15,4,15,13,2,8,6,4,7,15,9,3,4};
}
deque<int> q;
void reset() {
  cerr<<"reset"<<endl;
  q = deque<int>();
}
bool f(int x) {
  cerr<<x<<endl;
  ++counter;
  bool res = false;
  rep(i,sz(q)) if (q[i] == A[x]) res = true;
  q.pb(A[x]);
  if (sz(q) > k) q.pop_front();
  return res;
}
void answer(int x) {
  cerr<<x<<endl;
  assert(counter < (n*3*n/k/2));
  sort(rng(A));
  uni(A);
  assert(sz(A) == x);
}
//*/

int main() {
  n = 16; k = 4;
  scanf("%d%d",&n,&k);
  m = n/k;
  init();
  vvi a(m);
  rep(i,m) {
    reset();
    vi x;
    rep(j,k) if (!f(i*k+j)) x.pb(i*k+j);
    a[i] = x;
    // cerr<<a[i]<<endl;
  }
  rep(li,m)srep(ri,li+1,m) {
    reset();
    int l = sz(a[li]);
    int r = sz(a[ri]);
    if (!l || !r) continue;
    vi& la = a[li];
    vi& ra = a[ri];
    rep(i,l) f(la[i]);
    vi lb, rb;
    rep(i,r) {
      if (!f(ra[i])) rb.pb(ra[i]);
    }
    if (l+r <= k+1) {
      lb = la;
    } else {
      rep(i,2*k-l-r+1) f(ra.back());
      int ls = l - (k-r+1);
      rep(i,ls) {
        if (!f(la[i])) lb.pb(la[i]);
      }
      srep(i,ls,l) lb.pb(la[i]);
    }
    // cerr<<la<<" -> "<<lb<<endl;
    // cerr<<ra<<" -> "<<rb<<endl;
    a[ri] = rb;
    a[li] = lb;
  }
  // cerr<<a<<endl;
  int ans = 0;
  rep(i,m) ans += sz(a[i]);
  answer(ans);
  return 0;
}