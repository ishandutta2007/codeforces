#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <math.h>
#include <iomanip>
#include <limits>
#include <list>
#include <queue>
#include <tuple>
#include <map>
#include <stack>
#include <set>
#include <bitset>
#include <functional>
using namespace std;
#define fast_io ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
#define MOD (long long int)(1e9+7)
#define ll long long int
#define rep(i,n) for(int i=0; i<(int)(n); i++)
#define reps(i,n) for(int i=1; i<=(int)(n); i++)
#define REP(i,n) for(int i=n-1; i>=0; i--)
#define REPS(i,n) for(int i=n; i>0; i--)
#define INF (int)(1123456789)
#define LINF (long long int)(112345678901234567)
#define chmax(a, b) a = (((a)<(b)) ? (b) : (a))
#define chmin(a, b) a = (((a)>(b)) ? (b) : (a))
#define all(v) v.begin(), v.end()

typedef pair<int, int> Pii;
typedef pair<ll, ll> Pll;

ll mpow(ll a, ll b){
  if(b==0) return 1;
  else if(b%2==0){ll memo = mpow(a,b/2); return memo*memo%MOD;}
  else return mpow(a,b-1) * a % MOD;
}
ll lpow(ll a, ll b){
  if(b==0) return 1;
  else if(b%2==0){ll memo = lpow(a,b/2); return memo*memo;}
  else return lpow(a,b-1) * a;
}
ll gcd(ll a, ll b){
  if(b==0) return a;
  else return gcd(b, a%b);
}
vector<ll> kaijo_memo;
ll kaijo(ll n){
  if(kaijo_memo.size() > n) return kaijo_memo[n];
  if(kaijo_memo.size() == 0) kaijo_memo.push_back(1);
  while(kaijo_memo.size() <= n) kaijo_memo.push_back(kaijo_memo[kaijo_memo.size()-1] * kaijo_memo.size() % MOD);
  return kaijo_memo[n];
}
vector<ll> gyaku_kaijo_memo;
ll gyaku_kaijo(ll n){
  if(gyaku_kaijo_memo.size() > n) return gyaku_kaijo_memo[n];
  if(gyaku_kaijo_memo.size() == 0) gyaku_kaijo_memo.push_back(1);
  while(gyaku_kaijo_memo.size() <= n) gyaku_kaijo_memo.push_back(gyaku_kaijo_memo[gyaku_kaijo_memo.size()-1] * mpow(gyaku_kaijo_memo.size(), MOD-2) % MOD);
  return gyaku_kaijo_memo[n];
}

ll nCr(ll n, ll r){
  if(n == r) return 1;//0-1.
  if(n < r || r < 0) return 0;
  ll ret = 1;
  if(n <= 1e7){
    ret *= kaijo(n); ret %= MOD;
    ret *= gyaku_kaijo(r); ret %= MOD;
    ret *= gyaku_kaijo(n-r); ret %= MOD;
  }else{
    rep(i,r){
      ret *= n-i; ret %= MOD;
      ret *= mpow(r-i, MOD-2); ret %= MOD;
    }
  }
  return ret;
}

template< typename Monoid, typename OperatorMonoid = Monoid >
struct LazySegmentTree {
  using F = function< Monoid(Monoid, Monoid) >;
  //using F = (*Monoid)(Monoid, Monoid);
  using G = function< Monoid(Monoid, OperatorMonoid) >;
  using H = function< OperatorMonoid(OperatorMonoid, OperatorMonoid) >;

  int sz, height;
  vector< Monoid > data;
  vector< OperatorMonoid > lazy;
  const F f;
  const G g;
  const H h;
  const Monoid M1;
  const OperatorMonoid OM0;

  //, , , , , 
  LazySegmentTree(int n, const F f, const G g, const H h,
                  const Monoid &M1, const OperatorMonoid OM0)
      : f(f), g(g), h(h), M1(M1), OM0(OM0) {
    sz = 1;
    height = 0;
    while(sz < n) sz <<= 1, height++;
    data.assign(2 * sz, M1);
    lazy.assign(2 * sz, OM0);
  }

  void set(int k, const Monoid &x) {
    data[k + sz] = x;
  }

  void build() {
    for(int k = sz - 1; k > 0; k--) {
      data[k] = f(data[2 * k + 0], data[2 * k + 1]);
    }
  }

  inline void propagate(int k) {
    if(lazy[k] != OM0) {
      lazy[2 * k + 0] = h(lazy[2 * k + 0], lazy[k]);
      lazy[2 * k + 1] = h(lazy[2 * k + 1], lazy[k]);
      data[k] = reflect(k);
      lazy[k] = OM0;
    }
  }

  inline Monoid reflect(int k) {
    return lazy[k] == OM0 ? data[k] : g(data[k], lazy[k]);
  }

  inline void recalc(int k) {
    while(k >>= 1) data[k] = f(reflect(2 * k + 0), reflect(2 * k + 1));
  }

  inline void thrust(int k) {
    for(int i = height; i > 0; i--) propagate(k >> i);
  }

  void update(int a, int b, const OperatorMonoid &x) {
    thrust(a += sz);
    thrust(b += sz - 1);
    for(int l = a, r = b + 1; l < r; l >>= 1, r >>= 1) {
      if(l & 1) lazy[l] = h(lazy[l], x), ++l;
      if(r & 1) --r, lazy[r] = h(lazy[r], x);
    }
    recalc(a);
    recalc(b);
  }

  Monoid query(int a, int b) {
    thrust(a += sz);
    thrust(b += sz - 1);
    Monoid L = M1, R = M1;
    for(int l = a, r = b + 1; l < r; l >>= 1, r >>= 1) {
      if(l & 1) L = f(L, reflect(l++));
      if(r & 1) R = f(reflect(--r), R);
    }
    return f(L, R);
  }

  Monoid operator[](const int &k) {
    return query(k, k + 1);
  }

  template< typename C >
  int find_subtree(int a, const C &check, Monoid &M, bool type) {
    while(a < sz) {
      propagate(a);
      Monoid nxt = type ? f(reflect(2 * a + type), M) : f(M, reflect(2 * a + type));
      if(check(nxt)) a = 2 * a + type;
      else M = nxt, a = 2 * a + 1 - type;
    }
    return a - sz;
  }

  template< typename C >
  int find_first(int a, const C &check) {
    Monoid L = M1;
    if(a <= 0) {
      if(check(f(L, reflect(1)))) return find_subtree(1, check, L, false);
      return -1;
    }
    thrust(a + sz);
    int b = sz;
    for(a += sz, b += sz; a < b; a >>= 1, b >>= 1) {
      if(a & 1) {
        Monoid nxt = f(L, reflect(a));
        if(check(nxt)) return find_subtree(a, check, L, false);
        L = nxt;
        ++a;
      }
    }
    return -1;
  }


  template< typename C >
  int find_last(int b, const C &check) {
    Monoid R = M1;
    if(b >= sz) {
      if(check(f(reflect(1), R))) return find_subtree(1, check, R, true);
      return -1;
    }
    thrust(b + sz - 1);
    int a = sz;
    for(b += sz; a < b; a >>= 1, b >>= 1) {
      if(b & 1) {
        Monoid nxt = f(reflect(--b), R);
        if(check(nxt)) return find_subtree(b, check, R, true);
        R = nxt;
      }
    }
    return -1;
  }
};

struct monster{ll x,y,z;};
bool cmp(const monster &a, const monster &b){
  return a.y < b.y;
}
int main(void){
  fast_io
  cout<<fixed<<setprecision(15);

  ll n,m,p;
  cin>>n>>m>>p;

  auto fx = [](ll a, ll b){return max(a,b);};
  auto gx = [](ll a, ll b){return a + b;};
  auto hx = [](ll a, ll b){return a + b;};
  //, , , , , 
  LazySegmentTree<ll> segX = LazySegmentTree<ll>(1e6+5, fx, gx, hx, -LINF, 0);

  auto fy = [](ll a, ll b){return max(a,b);};
  auto gy = [](ll a, ll b){return a + b;};
  auto hy = [](ll a, ll b){return a + b;};
  //, , , , , 
  LazySegmentTree<ll> segY = LazySegmentTree<ll>(1e6+5, fy, gy, hy, -LINF, 0);

  vector<Pll> A(n),B(m);
  vector<monster> Mon(p);
  vector<ll> ruiseki(1e6+5, -LINF);
  rep(i,n){
    ll a,b;cin>>a>>b;a--;
    A[i] = {a,b};
    chmax(ruiseki[a], -b);
  }
  /*
  rep(i, 1e6+5 - 1){
    if(ruiseki[i+1] == -LINF){
      ruiseki[i+1] = ruiseki[i];
    }
  }*/
  REP(i,1e6+5 - 1){
    chmax(ruiseki[i], ruiseki[i+1]);
  }
  rep(i, 1e6+5 - 1){
    segX.set(i, ruiseki[i]);
  }
  segX.build();


  rep(i,m){
    ll a,b;cin>>a>>b;a--;
    B[i] = {a,b};
  }
  rep(i,p){
    ll a,b,c;cin>>a>>b>>c;a--;b--;
    Mon[i] = {a,b,c};
  }

  sort(all(Mon), cmp);

  segY.set(0, ruiseki[0]);
  rep(i, Mon.size()){
    ll x = Mon[i].x;
    ll y = Mon[i].y;
    ll z = Mon[i].z;
    segX.update(x+1, 1e6+4, z);
    ll max_val = segX.query(0, 1e6+4);
    segY.set(y+1, max(segY[y], max_val));
  }
  segY.build();

  ll ans = -LINF;
  //cerr<<endl;
  rep(i,m){
    ll y = B[i].first, c = B[i].second;
    //cout<<y+1<<" "<<c<<" "<<segY.query(0, y+1) - c<<endl;
    chmax(ans, segY.query(0, y+1) - c);
  }
  cout<<ans<<endl;

  return 0;
}