#include <bits/stdc++.h>
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef double db; 
typedef string str; 
 
typedef pair<int,int> pi;
typedef pair<ll,ll> pl; 
typedef pair<db,db> pd; 
 
typedef vector<int> vi; 
typedef vector<ll> vl; 
typedef vector<db> vd; 
typedef vector<str> vs; 
typedef vector<pi> vpi;
typedef vector<pl> vpl; 
typedef vector<pd> vpd;
typedef vector<vi> vvi; 

typedef set<int> si;

#define vt vector
#define mp make_pair
#define f first
#define s second
#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend() 
#define rsz resize
#define ins insert 
#define ft front() 
#define bk back()
#define pf push_front 
#define pb push_back
#define eb emplace_back 
#define lb lower_bound 
#define ub upper_bound
#define ts to_string
#define EACH(x, a) for (auto& x: a)

template<class T> void read(T &x){ cin >> x; }
template<class A> void read(vt<A> &v){ EACH(x, v) read(x); }
template<class H, class... T> void read(H& h, T& ...t){ read(h); read(t...); }

str to_string(const char* c){ return (str)c; }
str to_string(char c){ return (str)""+c; }
str to_string(str s){ return s; }
str to_string(bool b){ return b?"True" : "False"; }
template<class A> str to_string(vt<A> v){ str s; EACH(x, v) s+= to_string(x) + " "; return s; }
template<class H, class... T> str to_string(H& h, T& ...t){ str s; s+=to_string(h); s+=" "; s+=to_string(t...); return s; }
void print(str s){ cout << s << "\n"; }
template<class... A> void print(A ...a){ print(to_string(a...)); }

// Mint

struct Mint{
	int MOD;
	int value;
	explicit operator int() const {return value;}
	explicit operator bool() const {return value;}
	Mint(int _value = 0, int _MOD = 998244353) : MOD(_MOD), value(((_value%MOD)+MOD)%MOD){}

	friend Mint pow(Mint a, Mint b){
		Mint ret(1,a.MOD);
		while(b.value){
			if(b.value&1){
				ret *= a;
			}
			a *= a;
			b.value /= 2;
		}
		return ret;
	}

	friend Mint inv(Mint b){
		return pow(b,Mint(b.MOD-2));
	}

	inline Mint operator + (const Mint &b) {return Mint(value+b.value,MOD);}
	inline Mint operator - () {return Mint(-value,MOD);}
	inline Mint operator - (const Mint &b) {return Mint(value-b.value,MOD);}
	inline Mint operator * (const Mint &b) {return Mint(1ll*value*b.value%MOD,MOD);}
	inline Mint operator / (const Mint &b) {return Mint(*this*inv(b));}

	inline Mint operator & (const Mint &b) {return Mint(value&b.value,MOD);}
	inline Mint operator % (const Mint &b) {return Mint(value%b.value,MOD);}
	inline Mint operator << (const Mint &b) {return Mint((1ll*value<<b.value)%MOD,MOD);}
	inline Mint operator >> (const Mint &b) {return Mint(value>>b.value,MOD);}

	inline Mint& operator += (const Mint &b) {return *this = (*this)+b;}
	inline Mint& operator -= (const Mint &b) {return *this = (*this)-b;}
	inline Mint& operator *= (const Mint &b) {return *this = (*this)*b;}
	inline Mint& operator /= (const Mint &b) {return *this = (*this)/b;}
	inline Mint& operator <<= (const Mint &b) {return *this = (*this)<<b;}
	inline Mint& operator >>= (const Mint &b) {return *this = (*this)>>b;}

	friend bool operator == (const Mint &a, const Mint &b){return a.value == b.value;}
	friend bool operator != (const Mint &a, const Mint &b){return a.value != b.value;}

	friend istream& operator >> (istream &s, Mint &a){s >> a.value;return s;}
	friend ostream& operator << (ostream &o, Mint a){o << a.value;return o;}

};

// Matrix

struct Matrix{
	int n, m;
	vector<vector<Mint>> a;
	Matrix(){}
	Matrix(int _n, int _m){n = _n, m = _m; a.assign(n,vector<Mint>(m,0)); }
	Matrix(Mint _n, Mint _m){n = int(_n), m = int(_m); a.assign(n,vector<Mint>(m,0)); }
	Matrix(vector<vector<Mint>> _a){n = _a.size(); m = n ? _a[0].size() : 0; a = _a;}
	inline void make_unit(){
		assert(n == m);
		for(int i = 0; i < n; ++i)
			for(int j = 0; j < m; ++j)
				a[i][j] = i == j;
	}

	inline Matrix pow(Mint k){
		assert(n == m);
		Matrix t = a, ans = Matrix(n,m); ans.make_unit();
		while(k){
			if(k&1)ans *= t;
			t*=t;
			k>>=1;
		}
		return ans;
	}

	inline Matrix operator + (const Matrix &b){
		assert(n == b.n && m == b.m);
		Matrix ans = Matrix(n,m);
		for(int i = 0; i < n; ++i)
			for(int j = 0; j < m; ++j)
				ans.a[i][j]+=b.a[i][j];
		return ans;
	}
	inline Matrix operator - (const Matrix &b){
		assert(n == b.n && m == b.m);
		Matrix ans = Matrix(n,m);
		for(int i = 0; i < n; ++i)
			for(int j = 0; j < m; ++j)
				ans.a[i][j]-=b.a[i][j];
		return ans;
	}
	inline Matrix operator * (const Matrix &b){
		assert(m == b.n);
		Matrix ans = Matrix(n,b.m);
		for(int i = 0; i < n; ++i)
			for(int j = 0; j < b.m; ++j)
				for(int k = 0; k < m; ++k)
					ans.a[i][j]+=a[i][k]*b.a[k][j];
		return ans;
	}

	inline Matrix& operator += (const Matrix &b){return *this = (*this)+b;}
	inline Matrix& operator -= (const Matrix &b){return *this = (*this)-b;}
	inline Matrix& operator *= (const Matrix &b){return *this = (*this)*b;}

	friend bool operator == (Matrix &a, Matrix &b){return a.a == b.a;}
	friend bool operator != (Matrix &a, Matrix &b){return a.a != b.a;}
};

// FFT

const int fftmod = 998244353;
const Mint root(15311432,fftmod);
const Mint root_1(469870224,fftmod);
const int root_pw = 1<<23;

void FFT(vector<Mint> &a, bool invert){
	int n = a.size();

	for(int i = 1, j = 0; i < n; ++i){
		int bit = n>>1;
		for(; j&bit; bit >>= 1){
			j^=bit;
		}
		j^=bit;
		if(i < j){
			swap(a[i],a[j]);
		}
	}

	for(int len = 2; len <= n; len<<=1){
		Mint wlen(invert ? root_1 : root);
		for(int i = len; i < root_pw; i <<= 1){
			wlen *= wlen;
		}
		for(int i = 0; i < n; i+= len){
			Mint w(1,fftmod);
			for(int j = 0; j < len / 2; ++j){
				Mint u = a[i+j], v = a[i+j+len/2]*w;
				a[i+j] = u+v;
				a[i+j+len/2] = u-v;
				w*=wlen;
			}
		}
	}
	if(invert){
		Mint n_1(n,fftmod);
		n_1 = inv(n_1);
		for(auto &x : a){
			x*=n_1;
		}
	}
}


int cdiv(int a, int b) { return a/b+!(a<0||a%b == 0); }
str tb(int x) {str ans; int c = x; for(int i = log2(x); i >= 0; --i){if(pow(2,i) <= c){ ans += "1"; c-=pow(2,i); } else { ans += "0"; } } return ans;}
bool ispr(int x){if(x <= 1){return false;} for(int i = 2; i <= sqrt(x); ++i){ if(x%i == 0){ return false; } }return true; } 
			
const int dx[4] = {0,0,1,-1}, dy[4] = {1,-1,0,0};
// const int dx[8] = {0,1,1,1,0,-1,-1,-1}, dy[8] = {1,1,0,-1,-1,-1,0,1};
const int MOD = 1e9+7; // 998244353;
const int MX = 2e5+5; 
const ll INF = 1e18;

//tree<int,null_type,less<int>, rb_tree_tag, tree_order_statistics_node_update> T;

void solve(){
	int x; cin >> x;
	if(x >= 20){
		cout << "NO\n";
		return;
	}
	cout << "YES\n";
	ll st = 1;
	for(int i = 0; i < x; ++i){
		cout << st << ' ';
		st*=3;
	}
	cout << '\n';
}

int main(){
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	
	bool isT = 1;
	if(isT){
		int t; cin >> t; while(t--){
			solve();
		}
		return 0;
	}
	solve();		
	return 0;
}