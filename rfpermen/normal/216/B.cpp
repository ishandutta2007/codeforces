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
const ll MAX=1e2+5;
const ll MAX2 = 11;
const int MOD=1000000000 + 7;
const ll INF=20000;
const int nr[]={1,0,-1,0,1,1,-1,-1};
const int nc[]={0,1,0,-1,1,-1,1,-1};

int n,m,a,b,vis[MAX],ans;
vector<int> v[MAX];
pii cur;
pii dfs(int id){
	int sz = 1;
	int jlh = v[id].size();
	pii tmp;
	vis[id] = 1;
	for(auto i:v[id]){
		if(vis[i])continue;
		tmp = dfs(i);
		sz+=tmp.fi;
		jlh+=tmp.se;
	}
	return {sz,jlh};
}
int main(){
	cout<<fixed<<setprecision(10);
    //freopen("input.txt", "r", stdin);
	//freopen("output.txt","w",stdout);
    //ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    while(m--){
    	cin>>a>>b;
    	v[a].pb(b);
    	v[b].pb(a);
	}
	rep(i,1,n){
		if(vis[i])continue;
		cur = dfs(i);
		cur.se/=2;
		if(cur.fi==cur.se){
			ans+=(cur.fi&1);
		}
	}
	if((n-ans)&1)cout<<ans+1<<endl;
	else cout<<ans<<endl;
    return 0;
}