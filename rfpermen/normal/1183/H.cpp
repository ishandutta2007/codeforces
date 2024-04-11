#include <bits/stdc++.h>
 
#pragma GCC optimize("O3")
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,n,N) for(ll i=n;i<=N;++i)
#define rap(i,n,N) for(ll i=n;i>=N;--i)
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
#define db(x) cout << ">>>>>> " << #x << " -> " << x << endl;
#define all(x) x.begin(),x.end()
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define piii pair<int,pii>
#define plll pair<ll,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl "\n"
const int MAX = 2e5+5;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll INF = 1e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 450;

ll n,k,dp[101][101],ans,x[101];
string s;

ll f(int pos,int rem){
	if(rem==0)return 1;
	if(pos>n)return 0;
	if(dp[pos][rem]!=-1)return dp[pos][rem];
	bool vis[26];
	memset(vis,0,sizeof vis);
	ll ret = 0;
	rep(i,pos,n){
		if(vis[x[i]])continue;
		vis[x[i]] = 1;
		ret = min(ret+f(i+1,rem-1),1000000000000000);
	}
	return dp[pos][rem] = ret;
}

int main(){
//	cout<<fixed<<setprecision(15);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>s>>k>>s;
    for(auto i:s)x[++n] = i-'a';
    memset(dp,-1,sizeof dp);
    rep(i,0,n){
    	ans+=i*min(k,f(1,n-i));
//    	cout<<k<<' '<<f(1,n-i)<<' '<<min(k,f(1,n-i))<<endl;
    	k-=min(k,f(1,n-i));
//    	cout<<k<<endl;
    	if(k==0)return cout<<ans<<endl,0;
	}
	cout<<"-1\n";
	return 0;
}