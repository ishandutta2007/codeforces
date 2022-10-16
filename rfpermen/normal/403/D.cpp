#include <bits/stdc++.h>
 
#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
 
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,n,N) for(ll i=n;i<=N;++i)
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
#define rng() (rand()<<16)|rand()
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define plll pair<ll,pll>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl '\n'
const int MAX = 1e3+5;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll MOD2 = 1000005329;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 555;

ll tc,n,k,f[MAX],pre[MAX],dp[MAX][MAX],ans;

inline ll pw(ll x,ll y){
	ll ret = 1;
	while(y){
		if(y&1)ret = ret*x%MOD;
		x = x*x%MOD;
		y>>=1;
	}
	return ret;
}

ll g(int nw,int rem){
	if(nw<1)return 0;
	ll &ret = dp[nw][rem];
	if(ret!=-1)return ret;
	if(rem==1)return dp[nw][rem] = 1;
	ret = 0;
	for(int i = rem; i<=nw; i+=rem)ret+= g(nw-i,rem-1);
	return ret%=MOD;
}

int main(){
// cout<<fixed<<setprecision(10);
// freopen("input.txt", "r", stdin);
// freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    f[0] = pre[0] = 1;
    rep(i,1,1000)f[i] = f[i-1]*i%MOD, pre[i] = pw(f[i],MOD-2);
    
    mems(dp,-1);
    rep(i,1,1000)rep(j,1,1000)g(i,j);
    cin>>tc;
    rep(ntc,1,tc){
    	cin>>n>>k;
    	ans = 0;
    	rep(i,k*(k+1)/2,n)ans = (ans + dp[i][k]*f[n-i+k]%MOD*pre[n-i])%MOD;
    	cout<<ans<<endl;
	}
    return 0;
}