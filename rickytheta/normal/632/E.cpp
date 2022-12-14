#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)

typedef long long ll;

ll mul(ll a, ll b, ll M) { // a * b (mod M)
  ll r = a*b - (ll)((long double)(a)*b/M+.5)*M;
  return r < 0 ? r + M: r;
}
ll div(ll a, ll b, ll M) { // solve b x == a (mod M)
  ll u = 1, x = 0, s = b, t = M; 
  while (s) { // extgcd for b x + M s = t
    ll q = t / s;
    swap(x -= u * q, u);
    swap(t -= s * q, s);
  }
  if (a % t) return -1; // infeasible
  return mul(x < 0 ? x + M : x, a / t, M); // b (xa/t) == a (mod M)
}
ll pow(ll a, ll b, ll M) {
  ll x = 1;
  for (; b > 0; b >>= 1) {
    if (b & 1) x = (a * x) % M;
    a = (a * a) % M;
  }
  return x;
}

// assume: size of a/b is power of two, mod is predetermined
template <int mod, int sign>
void FMT(vector<ll>& x) {
  const int n = x.size();
  int h = pow(3, (mod-1)/n, mod);
  if (sign < 0) h = div(1, h, mod);
  for (int i = 0, j = 1; j < n-1; ++j) {
    for (int k = n >> 1; k > (i ^= k); k >>= 1);
    if (j < i) swap(x[i], x[j]);
  }
  for (int m = 1; m < n; m *= 2) {
    ll w = 1, wk = pow(h, n / (2*m), mod);
    for (int i = 0; i < m; ++i) {
      for (int s = i; s < n; s += 2*m) {
        ll u = x[s], d = x[s + m] * w % mod;
        if ((x[s] = u + d) >= mod) x[s] -= mod;
        if ((x[s + m] = u - d) < 0) x[s + m] += mod;
      }
      w = w * wk % mod;
    }
  }
  if (sign < 0) { 
    ll inv = div(1, n, mod);
    for (auto &a: x) 
      a = a * inv % mod;
  }
}

// assume: size of a/b is power of two, mod is predetermined
template <int mod>
vector<ll> conv(vector<ll> a, vector<ll> b){
  FMT<mod,+1>(a); FMT<mod,+1>(b);
  for (int i = 0; i < a.size(); ++i) 
    a[i] = a[i] * b[i] % mod;
  FMT<mod,-1>(a);
  return a;
}

// general convolution where mod < 2^31.
vector<ll> conv(vector<ll> a, vector<ll> b, ll mod){
  int n = a.size() + b.size() - 1;
  for (int k: {1,2,4,8,16}) n |= (n >> k); ++n;
  a.resize(n); b.resize(n);
  const int A = 167772161, B = 469762049, C = 1224736769, D = (ll)(A) * B % mod;
  vector<ll> x = conv<A>(a,b), y = conv<B>(a,b), z = conv<C>(a,b);
  for (int i = 0; i < x.size(); ++i) {
    ll X = (y[i] - x[i]) * 104391568;
    if ((X %= B) < 0) X += B;
    ll Y = (z[i] - (x[i] + A * X) % C) * 721017874;
    if ((Y %= C) < 0) Y += C;
    x[i] += A * X + D * Y;
    if ((x[i] %= mod) < 0) x[i] += mod;
  }
  x.resize(n);
  return x;
}

// const int N = 1<<20;

const int MOD = 998244353;

int main(){
  int n,k;
  scanf("%d%d",&n,&k);

  int N = 1<<10;

  vector<ll> a(N,0ll);
  REP(i,n){
    int x;
    scanf("%d",&x);
    a[x] = 1ll;
  }
    // REP(j,10)printf("(%.3f,%.3f) ",a[j].real(),a[j].imag());puts("");
  vector<ll> ans(N,0ll);
  ans[0] = 1ll;
  REP(i,10){
    N <<= 1;
    a.resize(N); ans.resize(N);
    FMT<MOD,+1>(a);
    if((k>>i)&1){
      // ans = ans * a
      FMT<MOD,+1>(ans);
      REP(j,N)ans[j] = ans[j] * a[j] % MOD;
      FMT<MOD,-1>(ans);
      REP(j,N)ans[j] = min(ans[j], 1ll);
    }
    // a = a * a
    REP(j,N)a[j] = a[j] * a[j] % MOD;
    FMT<MOD,-1>(a);
    REP(j,N)a[j] = min(a[j], 1ll);
  }
  REP(i,N)if(ans[i]){
    printf("%d ",i);
  }
  puts("");
  return 0;
}