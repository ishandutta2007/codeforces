#include <bits/stdc++.h>
 
#pragma GCC optimize("O3")
#pragma GCC target("tune=native")
#pragma GCC optimize("unroll-loops")
 
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,n,N) for(int i=(n);i<=(N);++i)
#define For(i,n,N) for(int i=(n);i< (N);++i)
#define rap(i,n,N) for(int i=(n);i>=(N);--i)
#define rip(i,n,N,V) for(int i=(n);i<=(N);i+=V)
#define mp make_pair
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
//#define le left
//#define ri right
#define fi first
#define se second
#define ff fi.fi
#define fs fi.se
#define sf se.fi
#define ss se.se
#define lc (id<<1)
#define rc ((id<<1)|1)
#define db(x) cout << ">>>> " << #x << " -> " << (x) << endl
#define out(x,y) cout << ">> " << (x) << " " << (y) << endl
#define ou3(x,y,z) cout << ">> " << (x) << " " << (y) << " " << (z) << endl
#define mems(x,y) memset(&x,y,sizeof x)
#define memsv(x,y) memset(&x[0], y, sizeof(x[0]) * x.size())
#define popcount __builtin_popcountll
#define all(x) x.begin(),x.end()
#define PQ(T) priority_queue<T>
#define PQr(T) priority_queue<T, vector<T>, greater<T>>
#define vi vector<int>
#define vii vector<pii>
#define vl vector<ll>
#define vll vector<pll>
#define ari(x) array<int,x>
#define arll(x) array<ll,x>
#define ard(x) array<double,x>
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define plll pair<ll,pll>
#define pllll pair<pll,pll>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl '\n'
const int MAX = 2e3+5;
const ll MOD = 1000000007;
const ll MOD2 = 2010405347;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 315;
inline ll pw(ll x,ll y,ll md=MOD){ll ret=1;x%=md;while(y){if(y&1)ret=ret*x%md;x=x*x%md,y>>=1;}return ret;}
inline void add(int &a,int b,int md=MOD){a=a+b>=md?a+b-md:a+b;}
 
namespace FFT {
/* ----- Adjust the constants here ----- */
const int LN = 24;
const int N = 1 << LN;
typedef long long LL;
// `MOD` must be of the form 2**`LN` * k + 1, where k odd.
const LL MOD = 9223372036737335297; // 2**24 * 54975513881 + 1.
const LL PRIMITIVE_ROOT = 3; // Primitive root modulo `MOD`.
/* ----- End of constants ----- */
LL root[N];
inline LL power(LL x, LL y) {
  LL ret = 1;
  for (; y; y >>= 1) {
    if (y & 1) ret = (__int128) ret * x % MOD;
    x = (__int128) x * x % MOD;
  }
  return ret;
}
inline void init_fft() {
  const LL UNITY = power(PRIMITIVE_ROOT, MOD-1 >> LN);
  root[0] = 1;
  for (int i=1; i<N; i++) {
    root[i] = (__int128) UNITY * root[i-1] % MOD;
  }return;
}
// n = 2^k is the length of polynom
inline void fft(int n, vector<LL> &a, bool invert) {
  for (int i=1, j=0; i<n; ++i) {
    int bit = n >> 1;
    for (; j>=bit; bit>>=1) j -= bit;
    j += bit;
    if (i < j) swap(a[i], a[j]);
  }
  for (int len=2; len<=n; len<<=1) {
    LL wlen = (invert ? root[N - N/len] : root[N/len]);
    for (int i=0; i<n; i+=len) {
      LL w = 1;
      for (int j=0; j<len>>1; j++) {
        LL u = a[i+j];
        LL v = (__int128) a[i+j + len/2] * w % MOD;
        a[i+j] = ((__int128) u + v) % MOD;
        a[i+j + len/2] = ((__int128) u - v + MOD) % MOD;
        w = (__int128) w * wlen % MOD;
      }
    }
  }
  if (invert) {
    LL inv = power(n, MOD-2);
    for (int i=0; i<n; i++) a[i] = (__int128) a[i] * inv % MOD;
  }return;
}
inline vector<LL> multiply(vector<LL> a, vector<LL> b) {
  vector<LL> c;
  int len = 1 << 32 - __builtin_clz(a.size() + b.size() - 2);
  a.resize(len, 0); b.resize(len, 0);
  fft(len, a, false); fft(len, b, false);
  c.resize(len);
  for (int i = 0; i < len; ++i)c[i] = (__int128) a[i]*b[i]%MOD; 
  fft(len, c, true);
  return c;
}
//FFT::init_fft();
//wajib di panggil init di awal
}
 
int n,k,x;
ll cnt,nw;
vector<ll> a,b;
 
int main(){
//	cout<<fixed<<setprecision(10);
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	FFT::init_fft();
	cin>>n>>k;
	a = {1};
	nw = cnt = 1;
	rep(i,1,n){
		cin>>x;
		if(x<k)a.pb(0), cnt = 1;
		else ++cnt;
		nw+= cnt;
		a[a.size()-1]++;
	}
	b = a;
	reverse(all(b));
	b = FFT::multiply(a,b);
//	out(a.size(),b.size());
//	db(nw);
	For(i,0,a.size())a[i] = b[a.size()-1+i];
	a[0]-= nw;
	while(a.size()<=n)a.pb(0);
	for(ll i:a)cout<<i<<" "; cout<<endl;
	return 0;
}