#include <bits/stdc++.h>
 
#pragma GCC optimize("O3")
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,n,N) for(ll i=n;i<=N;++i)
#define rap(i,n,N) for(ll i=n;i>=N;--i)
#define mp make_pair
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
#define fi first
#define se second
#define sf se.fi
#define ss se.se
#define lc (id<<1)
#define rc ((id<<1)|1)
#define db(x) cout << ">>>>>> " << #x << " -> " << x << endl;
#define all(x) x.begin(),x.end()
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl "\n"
const int MAX = 5e5+5;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 450;
 
ll n,sm,dp[4][1<<15],t[20],g[20],cek;
 
ll f(int ls,int mask){
	int hit = 0;
	rep(i,0,n)if(mask&(1<<i))hit+=t[i];
	if(hit==sm)return 1;
	if(hit>sm)return 0;
	if(dp[ls][mask]!=-1)return dp[ls][mask];
	ll ret = 0;
	rep(i,0,n){
		if(mask&(1<<i))continue;
		if(ls==g[i])continue;
		ret+=f(g[i],mask|(1<<i));
	}
	return dp[ls][mask] = ret%MOD;
}
 
int main(){
//	cout<<fixed<<setprecision(10);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>sm;
    n--;
    rep(i,0,n)cin>>t[i]>>g[i], cek+=t[i];
    if(cek<sm)return cout<<"0\n",0;
    memset(dp,-1,sizeof dp);
    cout<<f(0,0)<<endl;
	return 0;
}