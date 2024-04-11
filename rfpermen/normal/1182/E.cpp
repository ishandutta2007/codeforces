#include <bits/stdc++.h>
 
#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
 
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,n,N) for(int i=n;i<=N;++i)
#define asd(i,n,N) for(int i=n;i< N;++i)
#define rap(i,n,N) for(int i=n;i>=N;--i)
#define mp make_pair
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
#define fi first
#define se second
#define ff fi.fi
#define fs fi.se
#define sf se.fi
#define ss se.se
#define lc (id<<1)
#define rc ((id<<1)|1)
#define db(x) cout << ">>>> " << #x << " -> " << x << endl
#define mems(x,y) memset(x,y,sizeof x)
#define all(x) x.begin(),x.end()
#define rng() ((rand()<<16)|rand())
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define plll pair<ll,pll>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl '\n'
const int MAX = 1e5+5;
const ll MAX2 = 11;
const ll MOD = 1000000007;
//const ll MOD2 = 1000005329;
const ll MOD2 = MOD-1;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 555;

inline ll pw(ll x,ll y){
	ll ret = 1;
	while(y){
		if(y&1)ret = ret*x%MOD;
		x = x*x%MOD;
		y>>=1;
	}
	return ret;
}

ll n,ans,z[3],c;

inline void f(ll y){
	ll ret[3][3], tmp[3][3], x[3][3] = {{1,1,1},{1,0,0},{0,1,0}};
	mems(ret,0);
	rep(i,0,2)ret[i][i] = 1;
	while(y){
		if(y&1){
			mems(tmp,0);
			rep(i,0,2)rep(k,0,2)if(x[i][k])rep(j,0,2)tmp[i][j]+= x[i][k] * ret[k][j];
			rep(i,0,2)rep(j,0,2)ret[i][j] = tmp[i][j]%MOD2;
		}
		mems(tmp,0);
		rep(i,0,2)rep(k,0,2)if(x[i][k])rep(j,0,2)tmp[i][j]+= x[i][k] * x[k][j];
		rep(i,0,2)rep(j,0,2)x[i][j] = tmp[i][j]%MOD2;
		y>>=1;
	}
	rep(i,0,2)ans = ans * pw(z[i],ret[0][i])%MOD;
	return;
}

inline void g(ll y){
	ll ret[5][5], tmp[5][5], x[5][5] = {{1,1,1,1,0},{1,0,0,0,0},{0,1,0,0,0},{0,0,0,1,1},{0,0,0,0,1}};
	mems(ret,0);
	rep(i,0,4)ret[i][i] = 1;
	while(y){
		if(y&1){
			mems(tmp,0);
			rep(i,0,4)rep(k,0,4)if(x[i][k])rep(j,0,4)tmp[i][j]+= x[i][k] * ret[k][j];
			rep(i,0,4)rep(j,0,4)ret[i][j] = tmp[i][j]%MOD2;
		}
		mems(tmp,0);
		rep(i,0,4)rep(k,0,4)if(x[i][k])rep(j,0,4)tmp[i][j]+= x[i][k] * x[k][j];
		rep(i,0,4)rep(j,0,4)x[i][j] = tmp[i][j]%MOD2;
		y>>=1;
	}
	ans = ans * pw(c,ret[0][3]+ret[0][4])%MOD;
	return;
}

int main(){
// cout<<fixed<<setprecision(3);
// freopen("trip.in", "r", stdin);
// freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    rap(i,2,0)cin>>z[i];
    ans = 1;
    f(n-3);
    cin>>c;
    c = c*c%MOD;
    g(n-3);
    cout<<ans<<endl;
    return 0;
}