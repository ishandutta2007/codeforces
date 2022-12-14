#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,avx2,fma")
#include <bits/stdc++.h>
//#include <atcoder/convolution>
//using namespace atcoder;
//#include <bits/extc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//#include <ext/pb_ds/priority_queue.hpp>
#define fi first
#define se second
using namespace std;
//using namespace __gnu_pbds;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<db,db> pdb;
typedef tuple<int,int,int> tii;
typedef tuple<db,db,db> tdb;
typedef tuple<ll,ll,ll> tll;
typedef tuple<int,int,int,int> ti4;
typedef tuple<ll,ll,ll,ll> tl4;
typedef tuple<db,db,db,db> td4;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> oset;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count()); //shuffle(a+1,a+1+n,rng)
uniform_int_distribution<> gen(1,100); //gen(rng)
ll modinv(ll a,ll m){
	if(m==1) return 0;
	a%=m;
	if(a<0) a+=m;
	if(a==1) return 1;
	return m-modinv(m,a)*m/a;
}
template <int MOD_> struct modnum{
private:
	int v;
public:
	static const int MOD = MOD_;
 
	modnum() : v(0) {}
	modnum(ll v_) : v(int(v_ % MOD)) { if (v < 0) v += MOD; }
	explicit operator int () const { return v; }
	friend bool operator == (const modnum& a, const modnum& b) { return a.v == b.v; }
	friend bool operator != (const modnum& a, const modnum& b) { return a.v != b.v; }
	friend bool operator < (const modnum& a, const modnum& b) { return a.v < b.v; }
	friend bool operator <= (const modnum& a, const modnum& b) { return a.v <= b.v; }
	friend bool operator > (const modnum& a, const modnum& b) { return a.v > b.v; }
	friend bool operator >= (const modnum& a, const modnum& b) { return a.v >= b.v; }
 
	modnum operator ~ () const {
		modnum res;
		res.v = modinv(v, MOD);
		return res;
	}
 
	modnum& operator += (const modnum& o) {
		v += o.v;
		if (v >= MOD) v -= MOD;
		return *this;
	}
	modnum& operator -= (const modnum& o) {
		v -= o.v;
		if (v < 0) v += MOD;
		return *this;
	}
	modnum& operator *= (const modnum& o) {
		v = int(ll(v) * ll(o.v) % MOD);
		return *this;
	}
	modnum& operator /= (const modnum& o) {
		return *this *= (~o);
	}
 
	modnum operator-() const { return modnum(-v); }
	modnum& operator++() { return *this += 1; }
	modnum operator++(int){ modnum tmp=*this; ++*this; return tmp; }
	modnum& operator--() { return *this -= 1; }
	modnum operator--(int){ modnum tmp=*this; --*this; return tmp; }
 
	friend modnum operator + (const modnum& a, const modnum& b) { return modnum(a) += b; }
	friend modnum operator - (const modnum& a, const modnum& b) { return modnum(a) -= b; }
	friend modnum operator * (const modnum& a, const modnum& b) { return modnum(a) *= b; }
	friend modnum operator / (const modnum& a, const modnum& b) { return modnum(a) /= b; }
	friend modnum pow(modnum a, ll p) {
		modnum ans = 1;
		for (; p; p /= 2, a *= a) if (p&1) ans *= a;
		return ans;
	}
	friend ostream& operator<<(std::ostream& os, const modnum& o)
	{
		os << o.v;
		return os;
	}
	friend istream& operator>>(std::istream& is, modnum& o)
	{
		is >> o.v;
		return is;
	}
};
using mi=modnum<998244353>;
const int N=2e5+5,M=1005,Q=1e6+5;
const ll mod=998244353,inf=1e18;
int n,m,val1,val2,sumR,sumC,delR,delC,r1,r2,c1,c2,x;
// r1 + r2, c1 + c2, r2 - r1, c2 - c1
void solve(){
	cin>>n>>m;
	cout<<"SCAN 1 1"<<endl;
	cin>>x;
	// (r1 - 1) + (r2 - 1) + (c1 - 1) + (c2 - 1) = x
	val1=x+4;
	cout<<"SCAN "<<n<<" 1"<<endl;
	cin>>x;
	// (n - r1) + (n - r2) + (c1 - 1) + (c2 - 1) = x
	val2=x+2-2*n;
	sumR=(val1-val2)/2;
	sumC=(val1+val2)/2;
	cout<<"SCAN "<<sumR/2<<" 1"<<endl;
	cin>>x;
	// (p - r1) + (r2 - p) + (c1 - 1) + (c2 - 1) = x
	delR=x+2-sumC;
	cout<<"SCAN 1 "<<sumC/2<<endl;
	cin>>x;
	// (r1 - 1) + (r2 - 1) + (p - c1) + (c2 - p) = x
	delC=x+2-sumR;
	r1=(sumR-delR)/2;
	r2=(sumR+delR)/2;
	c1=(sumC-delC)/2;
	c2=(sumC+delC)/2;
	cout<<"DIG "<<r1<<" "<<c1<<endl;
	cin>>x;
	if(x){
		cout<<"DIG "<<r2<<" "<<c2<<endl;
		cin>>x;
	} else{
		cout<<"DIG "<<r1<<" "<<c2<<endl;
		cin>>x;
		cout<<"DIG "<<r2<<" "<<c1<<endl;
		cin>>x;
	}
}
int main(){
	ios::sync_with_stdio(false); cin.tie(0);
	int tc; cin>>tc;
	while(tc--) solve();
	return 0;
}