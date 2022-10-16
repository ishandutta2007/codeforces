#include<bits/stdc++.h>
 
#pragma GCC optimize("O3")
#pragma GCC target("tune=native")
#pragma GCC optimize("unroll-loops")
 
using namespace std;
template<class A, class B>
ostream& operator<<(ostream& os, const pair<A, B> &p) {
  os << '(' << p.first << ',' << p.second << ')';
  return os;
}
template<class T>
ostream& operator<<(ostream& os, const vector<T> &v) {
  os << '{';
  bool osu = 1;
  for(auto &i : v) { if(!osu) os << ','; os << i; osu = 0; }
  os << '}';
  return os;
}
template<class T,long long unsigned int size>
ostream& operator<<(ostream& os, const array<T,size> &arr) {
  os << '{';
  bool osu = 1;
  for(auto &i : arr) { if(!osu) os << ','; os << i; osu = 0; }
  os << '}';
  return os;
}
 
#define ll long long
#define ull unsigned long long
#define lll __int128
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
#define clz(x) (1<<(31-__builtin_clz(x)))
#define clzll(x) (1LL<<(63-__builtin_clzll(x)))
#define all(x) x.begin(),x.end()
#define rsort(x) sort(x), reverse(x)
#define revsort(a,b) sort(a,b), reverse(a,b)
#define PQ(T) priority_queue<T>
#define PQr(T) priority_queue<T, vector<T>, greater<T>>
#define permute(x) while(next_permutation(all(x)))
#define vi vector<int>
#define vvi vector<vi>
#define vii vector<pii>
#define vll vector<ll>
#define vlll vector<pll>
#define vvll vector<vll>
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
const int MAX = 6e5+5;
const ll MOD = 998244353;
const ll MOD2 = 2010405347;
const ll INF = 2e18;
const int dr[]={1,0,0,-1};
const int dc[]={0,-1,1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 8;
inline ll pw(ll x,ll y,ll md=MOD){ll ret=1;x%=md;while(y){if(y&1)ret=ret*x%md;x=x*x%md,y>>=1;}return ret;}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

namespace FFT {
/* ----- Adjust the constants here ----- */
const int LN = 23;
const int N = 1 << LN;
// `MOD` must be of the form 2**`LN` * k + 1, where k odd.
const int MOD = 998244353; // 2**23 * 119 + 1.
const int PRIMITIVE_ROOT = 3; // Primitive root modulo `MOD`.
/* ----- End of constants ----- */
int root[N];
inline int power(int x, int y) {
  int ret = 1;
  for (; y; y >>= 1) {
    if (y & 1) ret = 1LL * ret * x % MOD;
    x = 1LL * x * x % MOD;
  }
  return ret;
}
inline void init_fft() {
  const int UNITY = power(PRIMITIVE_ROOT, MOD-1 >> LN);
  root[0] = 1;
  for (int i=1; i<N; i++) {
    root[i] = 1LL * UNITY * root[i-1] % MOD;
  }return;
}
// n = 2^k is the length of polynom
inline void fft(int n, vector<int> &a, bool invert) {
  for (int i=1, j=0; i<n; ++i) {
    int bit = n >> 1;
    for (; j>=bit; bit>>=1) j -= bit;
    j += bit;
    if (i < j) swap(a[i], a[j]);
  }
  for (int len=2; len<=n; len<<=1) {
    int wlen = (invert ? root[N - N/len] : root[N/len]);
    for (int i=0; i<n; i+=len) {
      int w = 1;
      for (int j=0; j<len>>1; j++) {
        int u = a[i+j];
        int v = 1LL * a[i+j + len/2] * w % MOD;
        a[i+j] = (u + v) % MOD;
        a[i+j + len/2] = (u - v + MOD) % MOD;
        w = 1LL * w * wlen % MOD;
      }
    }
  }
  if (invert) {
    int inv = power(n, MOD-2);
    for (int i=0; i<n; i++) a[i] = 1LL * a[i] * inv % MOD;
  }return;
}
inline vector<int> multiply(vector<int> a, vector<int> b) {
  vector<int> c;
  int len = 1 << 32 - __builtin_clz(a.size() + b.size() - 2);
  a.resize(len, 0); b.resize(len, 0);
  fft(len, a, false); fft(len, b, false);
  c.resize(len);
  for (int i = 0; i < len; ++i)c[i]=1LL*a[i]*b[i]%MOD; 
  fft(len, c, true);
  return c;
}
//FFT::init_fft(); wajib di panggil init di awal
}

ll fc[MAX],pre[MAX];
inline void combin(int n){
	fc[0] = 1;
	rep(i,1,n)fc[i] = fc[i-1]*i%MOD;
	pre[n] = pw(fc[n],MOD-2);
	rap(i,n-1,0)pre[i] = pre[i+1]*(i+1)%MOD;
}
inline ll cb(int n,int k){
	if(k>n || k<0)return 0;
	return fc[n] * pre[k] % MOD * pre[n-k] % MOD;
}

int n,q,k,z,x[MAX],y[MAX],pw2[MAX],a,b;
ll ans[MAX];
vi p1,p2,res;

int main(){
//	cout<<fixed<<setprecision(10);
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	FFT::init_fft();
	combin(MAX);
	pw2[0] = 1;
	rep(i,1,300000)pw2[i] = (pw2[i-1]<<1) % MOD;
	cin>>n>>k;
	rep(i,1,n)cin>>z, ++x[z];
	rep(i,1,k)cin>>z, ++y[z];
	rep(i,1,300000)if(y[i]){
		a = b = 0;
		For(j,1,i){
			if(x[j]==1)++a;
			else if(x[j]>1)++b;
		}
		b*= 2;
		p1.resize(a+1);
		p2.resize(b+1);
		rep(j,0,a)p1[j] = cb(a,j) * pw2[j] % MOD;
		rep(j,0,b)p2[j] = cb(b,j);
		res = FFT::multiply(p1, p2);
		For(j,0,res.size()){
			if(i+j>600000)break;
			ans[i+j+1] = (ans[i+j+1] + res[j]) % MOD;
		}
	}
	cin>>q;
	rep(i,1,q){
		cin>>a;
		cout<<ans[a/2]<<endl;
	}
	return 0;
}