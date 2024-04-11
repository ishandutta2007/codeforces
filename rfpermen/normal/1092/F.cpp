#include <bits/stdc++.h>

#pragma GCC optimize("O2")
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,n,N) for(int i=n;i<=N;i++)
#define rap(i,n,N) for(int i=(int)n;i>=(int)N;i--)
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
#define db(x) cout << ">>>>>>" << #x << " -> " << x << endl;
#define all(x) x.begin(),x.end()
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl "\n"
const int MAX=2e5+5;
const ll MAX2 = 11;
const int MOD=1000000000 + 7;
const ll INF=20000;
const int dr[]={1,0,-1,0,1,1,-1,-1};
const int dc[]={0,1,0,-1,1,-1,1,-1};
const double pi = acos(-1);
const double EPS = 1e-9;

int n,a,b,st;
vector<int> v[MAX];
ll ans,ttl,x[MAX],sum,sz[MAX];

void dfs(int nw,int dep,int par){
	ttl+=x[nw]*dep;
	sz[nw] = x[nw];
	for(auto i:v[nw]){
		if(i==par)continue;
		dfs(i,dep+1,nw);
		sz[nw]+=sz[i];
	}
	return;
}
void f(int nw,int par,ll res,ll le){
	ans = max(ans,res);
	for(auto i:v[nw]){
		if(i==par)continue;
		f(i,nw,res+le+sz[nw]-2*sz[i],le+sz[nw]-sz[i]);
	}
	return;
}

int main(){
//	cout<<fixed<<setprecision(1);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin>>n;
	rep(i,1,n)cin>>x[i], sum+=x[i];
	rep(i,2,n){
		cin>>a>>b;
		v[a].pb(b), v[b].pb(a);
	}
	rep(i,1,n)if(v[i].size()==1)st = i;
	dfs(st,0,0);
	f(st,0,ttl,0);
	cout<<ans<<endl;
    return 0;
}