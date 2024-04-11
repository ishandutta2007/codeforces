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
const int MAX = 2e5+5;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;

int n,x[MAX],z[MAX],k,m,a,b,ans,dp[2005];
pii y[MAX];

int f(int nw){
	if(!nw)return 0;
	if(dp[nw]!=-1)return dp[nw];
	int ret = x[nw];
	rep(i,1,nw)ret = min(ret,f(nw-i)+x[nw]-x[nw-i+z[i]]);
	return dp[nw] = ret;
}

int main(){
//	cout<<fixed<<setprecision(10);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m>>k;
    rep(i,1,n)cin>>x[i];
    sort(x+1,x+1+n);
    rep(i,1,n)x[i]+=x[i-1];
    rep(i,1,k)y[i] = {i,i};
    while(m--){
    	cin>>a>>b;
    	z[a] = max(z[a],b);
	}
	memset(dp,-1,sizeof dp);
	cout<<f(k)<<endl;
	return 0;
}