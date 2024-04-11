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
const ll MOD2 = 1000005329;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 555;

ll n,a,b,dp[MAX][2];
bool x[MAX];
vector<int> v[MAX],u[MAX];

void dfs(int nw,int par){
	for(int i:u[nw])if(i!=par){
		v[nw].pb(i);
		dfs(i,nw);
	}
	return;
}

inline ll pw(ll x,ll y){
	ll ret = 1;
	while(y){
		if(y&1)ret = ret*x%MOD;
		x = x*x%MOD;
		y>>=1;
	}
	return ret;
}

ll f(int nw,bool st){
	st|= x[nw];
	if(v[nw].empty())return st;
	if(dp[nw][st]!=-1)return dp[nw][st];
	ll tmp = 1, ret = 0;
	//1 = udh ketemu node hitam
	//0 = masih nyari node hitam
	if(st){
		if(!x[nw])ret = f(nw,0); //artinya dipotong edge nya
		for(int i:v[nw])tmp = tmp*f(i,st)%MOD;
		ret+= tmp;
	}
	else {
		for(int i:v[nw])tmp = tmp*f(i,1)%MOD;//karena cukup 1 cabang aja yang connect sama hitam
		for(int i:v[nw])ret+= tmp*pw(f(i,1),MOD-2)%MOD * f(i,0) % MOD; 
	}
	return dp[nw][st] = ret % MOD;
}

int main(){
// cout<<fixed<<setprecision(3);
// freopen("trip.in", "r", stdin);
// freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    rep(i,2,n){
    	cin>>a;
    	a = a+1, b = i;
    	u[a].pb(b);
    	u[b].pb(a);
	}
	rep(i,1,n)cin>>x[i];
	dfs(1,0);
	
	mems(dp,-1);
	cout<<f(1,0)<<endl;
    return 0;
}