#include <bits/stdc++.h>

#pragma GCC optimize("O3")
using namespace std;
#define ll long long
#define rep(i,n,N) for(ll i=n;i<=N;i++)
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
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define piii pair<int,pii>
#define piiii pair<piii,pii>
#define endl "\n"
const ll MAX=1e5+5;
const ll MAX2 = 11;
const int MOD=1000000000 + 7;
const ll INF=20000;
const int nr[]={1,0,-1,0,1,1,-1,-1};
const int nc[]={0,1,0,-1,1,-1,1,-1};

ll n,x[MAX],a,c,ans,sz[MAX];
vector<pll> v[MAX];

void dfs(int nw){
	sz[nw] = 1;
	for(auto i:v[nw]){
		dfs(i.fi);
		sz[nw]+=sz[i.fi];
	}
	return;
}

void f(int nw,ll ds){
	for(auto i:v[nw]){
		if(ds+i.se>x[i.fi])ans+=sz[i.fi];
		else if(ds+i.se>0)f(i.fi,ds+i.se);
		else f(i.fi,0);
	}
}

int main(){
//	cout<<fixed<<setprecision(0);
    //freopen("input.txt", "r", stdin);
	//freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    rep(i,1,n)cin>>x[i];
    rep(i,2,n){
    	cin>>a>>c;
    	v[a].pb({i,c});
	}
	dfs(1);
	f(1,0);
	cout<<ans<<endl;
    return 0;
}