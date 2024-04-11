#include <bits/stdc++.h>
 
#pragma GCC optimize("O2")
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
 
ll n,sz[MAX],ans[MAX],res,a,b;
vector<int> v[MAX],gs;
 
void dfs(int pos,int par){
	sz[pos] = ans[pos] = 1;
	for(auto i:v[pos]){
		if(i==par)continue;
		dfs(i,pos);
		sz[pos]+=sz[i];
		ans[pos]+=ans[i]+sz[i];
	}
	return;
}

void df(int pos,int par){
	ans[pos]+=ans[par]+n-(ans[pos]+sz[pos]+sz[pos]);
	for(auto i:v[pos]){
		if(i==par)continue;
		df(i,pos);
	}
	return;
}
 
int main(){
//	cout<<fixed<<setprecision(15);
//    freopen("class_treasurer.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    rep(i,2,n){
    	cin>>a>>b;
    	v[a].pb(b);
    	v[b].pb(a);
	}
	dfs(1,0);
	for(auto i:v[1])df(i,1);
	rep(i,1,n)res = max(res,ans[i]);
	cout<<res<<endl;
	return 0;
}