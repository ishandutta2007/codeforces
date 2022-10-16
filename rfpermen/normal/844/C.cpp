#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
#define ll long long
#define rep(i,n,N) for(int i=(int)n;i<=(int)N;i++)
#define rap(i,n,N) for(int i=(int)n;i>=(int)N;i--)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define mp make_pair
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
#define fi first
#define se second
const int MAX=100005;
const int MOD=1000000000 + 7;
int n,p[MAX],cnt,id,sz,vis[MAX];
pii x[MAX];
vector<int> v[MAX],ver[MAX];
void dfs(int nw){
	if(vis[nw])return;
	vis[nw]=cnt;
	rep(i,0,v[nw].size()-1)dfs(v[nw][i]);
}
int main(){
	cout<<fixed<<setprecision(25);
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin>>n;
	rep(i,1,n)cin>>x[i].fi, x[i].se=i ,p[i]=i;
	sort(x+1,x+1+n);
	rep(i,1,n){
		id=x[i].se;
		if(id!=i)v[i].pb(id), v[id].pb(i);
		else v[i].pb(i);
	}
	rep(i,1,n){
		if(vis[i])continue;
		cnt++;
		dfs(i);
	}
	rep(i,1,n){
		id=x[i].se;
		ver[vis[i]].pb(id);
	}
	cout<<cnt<<endl;
	rep(i,1,cnt){
		if(!v[i].empty()){
			sz=ver[i].size();
			cout<<sz;
			rep(j,0,sz-1)cout<<" "<<ver[i][j];
			cout<<endl;
		}
	}
	return 0;
}