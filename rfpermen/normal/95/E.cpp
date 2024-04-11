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
//#define ff fi.fi
//#define fs fi.se
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
const ll MOD2 = 2010405347;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 555;

int n,m,a,b,k,p[MAX],sz[MAX],cnt[MAX],dp[450][MAX],ans;
pii x[MAX];
bool lis[MAX];

void dfs(int nw){
	if(nw>n)return;
	lis[nw] = 1;
	dfs(nw*10 + 4);
	dfs(nw*10 + 7);
	return;
}

int par(int z){
	if(p[z]==z)return z;
	return p[z] = par(p[z]);
}

int f(int nw,int rem){
	if(nw>k)return MAX;
	if(dp[nw][rem]!=-1)return dp[nw][rem];
	int bt = min(x[nw].se,rem/x[nw].fi);
	if(bt*x[nw].fi==rem)return dp[nw][rem] = bt;
	int ret = MAX;
	rep(i,max(0,bt-3),bt)ret = min(ret, f(nw+1,rem-i*x[nw].fi) + i);
	return dp[nw][rem] = ret;
}

int main(){
// cout<<fixed<<setprecision(10);
// freopen("trip.in", "r", stdin);
// freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    dfs(0);
    rep(i,1,n)p[i] = i, sz[i] = 1;
    while(m--){
    	cin>>a>>b;
    	a = par(a), b = par(b);
    	if(a!=b){
    		p[a] = b;
    		sz[b]+= sz[a];
		}
	}
	rep(i,1,n)if(par(i)==i)++cnt[sz[i]];
	rap(i,n,1)if(cnt[i]){
		if(lis[i])return cout<<"0\n",0;
		x[++k] = {i,cnt[i]};
	}
	mems(dp,-1);
	ans = MAX;
	rep(i,1,n)if(lis[i]){
		ans = min(ans,f(1,i)-1);
		if(ans==1)return cout<<"1\n",0;
	}
	if(ans>n)ans = -1;
	cout<<ans<<endl;
    return 0;
}