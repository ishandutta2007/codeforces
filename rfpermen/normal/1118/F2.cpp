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
const int MAX = 3e5+5;
const ll MAX2 = 11;
const ll MOD = 998244353;
const ll MOD2 = 1000000006;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 316;
 
int n,k,x[MAX],ls[MAX],par[MAX],dep[MAX],z[MAX],a,b;
ll dp[MAX][2],ans;
bool vis[MAX];
vector<int> v[MAX],lis[MAX];
 
void deep(int nw){
	for(int i:v[nw])if(i!=par[nw]){
		par[i] = nw;
		dep[i] = dep[nw]+1;
		deep(i);
	}return;
}
 
inline void cek(int i,int j){
	if(z[j]){if(z[j]!=i){cout<<"0\n"; exit(0);}}
    else z[j] = i, vis[j] = 1; return;
}
 
void dfs(int nw,int par){
	vis[nw] = 1;
	for(int i:v[nw])if(i!=par){
		if(!z[i])dfs(i,nw);
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
 
ll f(int nw,int par,bool ty){
	if(z[nw])return 1;
	ll &ret = dp[nw][ty];
	if(ret!=-1)return ret;
	ll tmp = 1;
	ret = 0;
	if(ty){
		for(int i:v[nw])if(i!=par)tmp = tmp*f(i,nw,0)%MOD;
		for(int i:v[nw])if(i!=par){
			ret+= tmp*pw(f(i,nw,0),MOD-2)%MOD * f(i,nw,1)%MOD;
//			cout<<nw<<"->"<<i<<" = "<<f(i,nw,0)<<endl;
//			cout<<nw<<"->"<<i<<" = "<<f(i,nw,1)<<endl;
		}
	}
	else {
		ret = f(nw,par,1);
		for(int i:v[nw])if(i!=par)tmp = tmp*f(i,nw,0)%MOD;
		ret+= tmp;
	}
	ret%= MOD;
	return ret;
}
 
int main(){
//	cout<<fixed<<setprecision(10);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>k;
    rep(i,1,n){
    	cin>>x[i];
    	if(x[i])lis[x[i]].pb(i);
	}
	rep(i,2,n){
		cin>>a>>b;
		v[a].pb(b);
		v[b].pb(a);
	}
	deep(1);
    rep(i,1,k){
    	ls[i] = lis[i][0];
    	for(int j:lis[i]){
    		cek(i,j);
    		a = ls[i];
    		if(dep[a]<dep[j])swap(a,j);
    		while(dep[a]>dep[j]){
    			a = par[a];
    			if(z[a]==i)a = j;
				cek(i,a);
			}
    		while(a!=j)a = par[a], j = par[j], cek(i,a), cek(i,j);
    		ls[i] = a;
		}
	}
//	rep(i,1,n)cout<<vis[i]<<' ';
	memset(dp,-1,sizeof dp);
	ans = 1;
	rep(i,1,n)if(!vis[i]){
		dfs(i,0);
//		cout<<i<<" = "<<f(i,0,1)<<endl;
		ans = ans*f(i,0,1)%MOD;
	}
//	rep(i,1,n)cout<<st[i]<<' '; cout<<endl;
	cout<<ans<<endl;
    return 0;
}