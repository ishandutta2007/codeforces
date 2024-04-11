#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")

#define ll long long
#define rep(i,n,N) for(ll i=(ll)n;i<=(ll)N;i++)
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
const int MAX=300005;
const int MOD=1000000000 + 7;
ll n,m,vis[MAX],cnt,a,b,st,ans,pos,siz,SZ;
vector<ll> v[MAX],y[MAX];
void dfs(ll nw){
	vis[nw]=cnt;
	ll sz=v[nw].size();
	
	sz--;//, cout<<nw<<" "<<sz<<endl;
	rep(j,0,sz){
		//cout<<nw<<" lala "<<v[nw][j]<<endl;
		if(vis[v[nw][j]])continue;
		
		dfs(v[nw][j]);
	}
	return;
}
int main(){
	//cout<<fixed<<setprecision(25);
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin>>n>>m;
	rep(i,1,m)cin>>a>>b, v[a].pb(b), v[b].pb(a);
	/*rep(i,1,n){
		sz=v[i].size();sz--;
		cout<<i<<" ";
		rep(j,0,sz)cout<<v[i][j]<<" ";
		cout<<endl;
	}*/
	rep(i,1,n){
		if(vis[i])continue;
		cnt++;
		dfs(i);
		//rep(i,1,n)cout<<vis[i]<<" ";cout<<endl;
	}
	rep(i,1,n)y[vis[i]].pb(i);
	rep(i,1,cnt){
		SZ=y[i].size();SZ--;
		rep(j,0,SZ){
			pos=y[i][j];
			siz=v[pos].size();
			if(siz!=2)break;
			if(j==SZ)ans++;
		}
	}
	//cout<<cnt<<endl;
	cout<<ans<<endl;
	return 0;
}