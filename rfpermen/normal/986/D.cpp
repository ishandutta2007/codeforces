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
//FFT::init_fft();
//wajib di panggil init di awal
}

ll n,x,k;
string s;
double tiga = log(3.), res;
 
int cek(int k,int base){
	vector<int> ret = {base}, x = {3};
	while(k){
		if(k&1){
			ret = FFT::multiply(ret,x);
			For(i,0,ret.size()){
				if(ret[i]>=10){
					if(i==ret.size()-1)ret.pb(ret[i]/10);
					else ret[i+1]+= ret[i]/10;
					ret[i]%= 10;
				}
			}
			while(!ret.back())ret.pob();
		}
		x = FFT::multiply(x,x);
		For(i,0,x.size()){
			if(x[i]>=10){
				if(i==x.size()-1)x.pb(x[i]/10);
				else x[i+1]+= x[i]/10;
				x[i]%= 10;
			}
		}
		while(!x.back())x.pob();
		k>>= 1;
	}
	if(ret.size()!=s.size())return ret.size()<s.size();
	reverse(all(ret));
//	for(int i:ret)cout<<i; cout<<endl;
	For(i,0,s.size()){
		if(s[i]-'0'!=ret[i])return ret[i]<s[i]-'0';
	}
	return 0;
}
 
int main(){
	cout<<fixed<<setprecision(10);
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	FFT::init_fft();
	cin>>s;
	n = min(18,(int)s.size());
	For(i,0,n)x = x*10 + s[i]-'0';
	if(x<5)return cout<<x<<endl,0;
	double o = 36;
	res = log(x)+log(10.)*(s.size()-n);
	k = floor(res/tiga+EPS);
	res-= k*tiga;
	
//	db(res);
//	db(k);
	int ans;
	if(res<0.1)ans = cek(k-1,3) + k*3;
	else if(res<0.35)ans = cek(k-1,4) + k*3+1;
	else if(res<0.75)ans = cek(k,2) + k*3+2;
	else ans = cek(k,3) + k*3+3;
	cout<<ans<<endl;
	return 0;
}