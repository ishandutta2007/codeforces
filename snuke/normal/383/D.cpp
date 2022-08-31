#include<cstdio>
#include<algorithm>
#include<stack>
#include<queue>
#include<vector>
#include<string>
#include<string.h>
#include<cstdlib>
#include<ctime>
#include<cmath>
#include<complex>
#include<map>
#include<set>
#include<bitset>
#include<iostream>
#include<sstream>
#define fi first
#define se second
#define rep(i,n) for(int i = 0; i < n; i++)
#define rrep(i,n) for(int i = 1; i <= n; i++)
#define drep(i,n) for(int i = n-1; i >= 0; i--)
#define gep(i,g,j) for(int i = g.head[j]; i != -1; i = g.e[i].next)
#define each(it,c) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define rng(a) a.begin(),a.end()
#define maxs(x,y) x = max(x,y);
#define mins(x,y) x = min(x,y);
#define adds(x,y) x = (x+(y))%mod;
#define dels(x,y) x = (x-(y)+mod)%mod;
#define muls(x,y) x = ((ll)x*(y))%mod;
#define pb push_back
#define sz(x) (int)(x).size()
#define snuke srand((unsigned)clock()+(unsigned)time(NULL))
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;
typedef vector<int> vi;

const int MX = 1005, INF = 1000000000;
const ll LINF = 1000000000000000000ll;
const double eps = 1e-10;
const int dx[] = {-1,0,1,0}, dy[] = {0,-1,0,1}; //<^>v

// Mod int
const int mod = 1000000007;
struct mint{
	ll x;
	mint():x(0){}
	mint(ll x):x(x){}
	mint operator+=(mint a){ if((x+=a.x)>=mod) x-=mod; return *this;}
	mint operator-=(mint a){ if((x+=mod-a.x)>=mod) x-=mod; return *this;}
	mint operator*=(mint a){ (x*=a.x)%=mod; return *this;}
	mint operator+(mint a){ return mint(*this) += a;}
	mint operator-(mint a){ return mint(*this) -= a;}
	mint operator*(mint a){ return mint(*this) *= a;}
};
mint ex(mint a, ll tms){
	if(!tms) return 1;
	mint res = ex(a,tms/2);
	res *= res;
	return (tms&1)?res*a:res;
}
struct invs:vector<mint>{
	invs(){}
	invs(int mx):vector<mint>(mx,0){
		(*this)[1] = 1;
		for(int i=2;i<=mx;i++) (*this)[i] = (*this)[mod%i]*(mod-mod/i);
	}
};
struct ex2:vector<mint>{
	ex2(){}
	ex2(int mx):vector<mint>(mx){
		(*this)[0] = 1;
		for(int i=1;i<=mx;i++) (*this)[i] = (*this)[i-1]*2;
	}
};
struct comb{
	vector<mint> f, g;
	comb(){}
	comb(int mx):f(mx+1),g(mx+1){
		f[0] = 1;
		rrep(i,mx) f[i] = f[i-1]*i;
		g[mx] = ex(f[mx],mod-2);
		for(int i=mx;i>0;i--) g[i-1] = g[i]*i;
	}
	mint c(int a, int b){ return f[a]*g[b]*g[a-b];}
};
//

mint ans;
int ax[MX], n;
const int ME = 10005, MD = ME*2;
mint lc[ME], rc[ME], dp[2][MD];

void sol(int l, int r){
	if(l+1>=r) return;
	int c = (l+r)>>1;
	
	rep(i,ME) lc[i] = rc[i] = 0;
	int a = 0, b = 1;
	rep(i,MD) dp[a][i] = 0;
	dp[a][ME] = 1;
	for(int i = c-1; i >= l; i--){
		rep(j,MD) dp[b][j] = 0;
		for(int j = ax[i]; j < MD; j++) dp[b][j-ax[i]] = dp[a][j];
		for(int j = ax[i]; j < MD; j++) dp[b][j] += dp[a][j-ax[i]];
		for(int j = ME; j < MD; j++) lc[j-ME] += dp[b][j];
		swap(a,b);
	}
	rep(i,MD) dp[a][i] = 0;
	dp[a][ME] = 1;
	for(int i = c; i < r; i++){
		rep(j,MD) dp[b][j] = 0;
		for(int j = ax[i]; j < MD; j++) dp[b][j-ax[i]] = dp[a][j];
		for(int j = ax[i]; j < MD; j++) dp[b][j] += dp[a][j-ax[i]];
		for(int j = ME; j < MD; j++) rc[j-ME] += dp[b][j];
		swap(a,b);
	}
	
	rep(i,ME) ans += lc[i]*rc[i]*(i?2:1);
	
	sol(l,c); sol(c,r);
}

int main(){
	scanf("%d",&n);
	rep(i,n) scanf("%d",&ax[i]);
	
	sol(0,n);
	
	cout << ans.x << endl;
	
	return 0;
}