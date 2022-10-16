#include <bits/stdc++.h>

#pragma GCC optimize("O2")
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
#define endl "\n"
const ll MAX=1e5+5;
const int MOD=1000000000 + 7;
const ll INF=1e18;
const int nr[]={0,1,0,-1,1,1,-1,-1,  2,2,-2,-2,1,1,-1,-1};
const int nc[]={1,0,-1,0,1,-1,1,-1,  1,-1,1,-1,2,-2,2,-2};

int n,k,d,x[MAX],vis[MAX],vis2[MAX],ans,a,b,mx=-1,res;
vector<int> v[MAX];

void dfs(int id){
	for(auto i:v[id]){
		if(vis[i]!=-1)continue;
		vis[i] = vis[id]+1;
		dfs(i);
	}
	return;
}

void dfs2(int id){
	for(auto i:v[id]){
		if(vis2[i]!=-1)continue;
		vis2[i] = vis2[id]+1;
		dfs2(i);
	}
	return;
}

int main(){
    //cout<<fixed<<setprecision(9);
    //freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>k>>d;
    rep(i,1,k)cin>>x[i];
    rep(i,2,n){
    	cin>>a>>b;
    	v[a].pb(b);
    	v[b].pb(a);
	}
	memset(vis,-1,sizeof vis);
	vis[x[1]] = 0;
	dfs(x[1]);
	rep(i,1,k)if(vis[x[i]]>mx)mx = vis[x[i]], res = x[i];
	memset(vis,-1,sizeof vis);
	vis[res] = 0;
	dfs(res);
	mx = -1;
	rep(i,1,k)if(vis[x[i]]>mx)mx = vis[x[i]], res = x[i];
	memset(vis2,-1,sizeof vis2);
	vis2[res] = 0;
	dfs2(res);
	rep(i,1,n)if(max(vis[i],vis2[i])<=d)ans++;
	cout<<ans<<endl;
    return 0;
}