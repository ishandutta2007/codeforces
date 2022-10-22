#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)
#define all(c) c.begin(),c.end()
#define pb push_back
#define fs first
#define sc second
#define show(x) cout << #x << " = " << x << endl
#define chmin(x,y) x=min(x,y)
#define chmax(x,y) x=max(x,y)
using namespace std;
template<class S,class T> ostream& operator<<(ostream& o,const pair<S,T> &p){return o<<"("<<p.fs<<","<<p.sc<<")";}
template<class T> ostream& operator<<(ostream& o,const vector<T> &vc){o<<"sz = "<<vc.size()<<endl<<"[";for(const T& v:vc) o<<v<<",";o<<"]";return o;}

template<unsigned int mod_>
struct ModInt{
	using uint = unsigned int;
	using ll = long long;
	using ull = unsigned long long;

	constexpr static uint mod = mod_;

	uint v;
	ModInt():v(0){}
	ModInt(ll v):v(normS(v%mod+mod)){}
	explicit operator bool() const {return v!=0;}
	static uint normS(const uint &x){return (x<mod)?x:x-mod;}		// [0 , 2*mod-1] -> [0 , mod-1]
	static ModInt make(const uint &x){ModInt m; m.v=x; return m;}
	ModInt operator+(const ModInt& b) const { return make(normS(v+b.v));}
	ModInt operator-(const ModInt& b) const { return make(normS(v+mod-b.v));}
	ModInt operator-() const { return make(normS(mod-v)); }
	ModInt operator*(const ModInt& b) const { return make((ull)v*b.v%mod);}
	ModInt operator/(const ModInt& b) const { return *this*b.inv();}
	ModInt& operator+=(const ModInt& b){ return *this=*this+b;}
	ModInt& operator-=(const ModInt& b){ return *this=*this-b;}
	ModInt& operator*=(const ModInt& b){ return *this=*this*b;}
	ModInt& operator/=(const ModInt& b){ return *this=*this/b;}
	ll extgcd(ll a,ll b,ll &x,ll &y) const{
		ll u[]={a,1,0},v[]={b,0,1};
		while(*v){
			ll t=*u/ *v;
			rep(i,3) swap(u[i]-=t*v[i],v[i]);
		}
		if(u[0]<0) rep(i,3) u[i]=-u[i];
		x=u[1],y=u[2];
		return u[0];
	}
	ModInt inv() const{
		ll x,y;
		extgcd(v,mod,x,y);
		return make(normS(x+mod));
	}
	bool operator==(const ModInt& b) const { return v==b.v;}
	bool operator!=(const ModInt& b) const { return v!=b.v;}
	friend istream& operator>>(istream &o,ModInt& x){
		ll tmp;
		o>>tmp;
		x=ModInt(tmp);
		return o;
	}
	friend ostream& operator<<(ostream &o,const ModInt& x){ return o<<x.v;}
};
using mint = ModInt<998244353>;

const int MX = 4100;

mint f[MX],g[MX];

void precalc(){
	f[0] = 1;
	rep1(i,MX-1) f[i] = f[i-1]*i;
	g[0] = 1;
	rep1(i,MX-1) g[i] = g[i-1]/i;
}

mint P(int x,int y){
	return f[x]*g[x-y];
}
mint C(int x,int y){
	return f[x]*g[x-y]*g[y];
}

mint solve(){
	int N;
	cin>>N;
	int e[11]={},o[11]={};

	int O = 0;

	rep(i,N){
		int x;
		cin>>x;
		string s = to_string(x);
		if(s.size()%2==0){
			e[x%11] += 1;
		}else{
			o[x%11] += 1, O++;
		}
	}

	int X = (O+1)/2;
	int Y = O/2;

	vector<vector<vector<mint>>> dpo(12,vector<vector<mint>>(X+1,vector<mint>(11,0)));
	dpo[0][0][0] = 1;

	int acc = 0;

	rep(d,11){
		int n = o[d];
		rep(x,min(X,acc)+1) rep(r,11) if(dpo[d][x][r]){
			int y = acc-x;
			int leftx = X-x;
			int lefty = Y-y;
			rep(nx,n+1){
				int ny = n-nx;
				if( !(nx<=leftx && ny<=lefty) ) continue;
				int nr = ((r+(nx-ny)*d)%11+11)%11;
				dpo[d+1][x+nx][nr] += dpo[d][x][r] * P(leftx,nx) * P(lefty,ny) * C(nx+ny,nx);
			}
		}
		acc += o[d];
	}

	// rep(r,11){
	// 	show(dpo[11][X][r]);
	// }

	vector<vector<mint>> dp(N+2,vector<mint>(11,0));
	rep(r,11) dp[O/2+1][r] = dpo[11][X][r];

	int S = O+1;

	rep(d,11){
		rep(tt,e[d]){
			vector<vector<mint>> ndp(N+2,vector<mint>(11,0));
			rep(plus,N+2) rep(r,11) if(dp[plus][r]){
				int minus = S - plus;
				if(plus)  ndp[plus+1][(r+d)%11] += dp[plus][r]*plus;
				if(minus) ndp[plus][(r+11-d)%11] += dp[plus][r]*minus;
			}
			dp = ndp;
			S++;
		}
	}
	mint res = 0;
	rep(i,N+2) res += dp[i][0];
	return res;
}

int main(){
	precalc();
	int T;
	cin>>T;
	rep(t,T) cout<<solve()<<endl;
}