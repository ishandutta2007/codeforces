#include <bits/stdc++.h>
 
#pragma GCC optimize("O2")
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,n,N) for(ll i=n;i<=N;++i)
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
#define db(x) cout << ">>>>>> " << #x << " -> " << x << endl
#define all(x) x.begin(),x.end()
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define plll pair<ll,pll>
#define pllll pair<pll,pll>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl '\n'
const int MAX = 2e5+5;
const ll MAX2 = 11;
const ll MOD = 998244353;
const ll MOD2 = 1000000006;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 316;

int n,a,b,dp[MAX][3],ans;
vector<int> v[MAX];

int f(int nw,int par,int st){
	if(dp[nw][st]!=-1)return dp[nw][st];
	int &ret = dp[nw][st];
	ret = 0;
	if(st==2){
		ret = MAX;
		if(v[nw].size()!=1){
			int tmp = 0;
			for(auto i:v[nw])if(i!=par)tmp+= f(i,nw,2);
			for(auto i:v[nw])if(i!=par)ret = min(ret,tmp-f(i,nw,2)+f(i,nw,0)+1);
		}
		ret = min(ret,f(nw,par,0)+1);
	}
	else if(st){
		for(auto i:v[nw])if(i!=par)ret+= f(i,nw,2);
		ret = min(ret,f(nw,par,0)+1);
	}
	else for(auto i:v[nw])if(i!=par)ret+= f(i,nw,1);
	return ret;
}

int main(){
//	cout<<fixed<<setprecision(10);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    rep(i,2,n){
    	cin>>a>>b;
    	v[a].pb(b);
    	v[b].pb(a);
	}
	memset(dp,-1,sizeof dp);
	for(auto i:v[1])ans+= f(i,1,0);
	cout<<ans<<endl;
    return 0;
}