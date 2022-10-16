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
const ll MAX=2e5+5;
const int MOD=1000000000 + 7;
const ll INF=1e18;
const int nr[]={0,-1,0,1,1,1,-1,-1,  2,2,-2,-2,1,1,-1,-1};
const int nc[]={1,0,-1,0,1,-1,1,-1,  1,-1,1,-1,2,-2,2,-2};

int n,x[MAX],y,cnt,res,sz,a,b,nw,nx,cur,par,lnw;
pii vis[MAX];
vector<int> v[MAX],lvl[MAX];
queue<int> q;

int main(){
//	cout<<fixed<<setprecision(3);
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    rep(i,2,n){
    	cin>>a>>b;
    	v[a].pb(b);
    	v[b].pb(a);
	}
	q.push(1);
	vis[1] = {1,0};
	while(!q.empty()){
		cur = q.front(); q.pop();
		for(auto i:v[cur]){
			if(vis[i].fi)continue;
			vis[i] = {vis[cur].fi+1,cur};
			q.push(i);
		}
	}
	nw = 0, lnw = 2;
	rep(i,1,n){
		cin>>a;
		if(vis[a].fi<nw || vis[a].fi>nw+1)return cout<<"No",0;
		nw = vis[a].fi;
		lvl[nw].pb(a);
		x[i] = a;
	}
	nw = 0;
	rep(i,2,n){
		par = vis[vis[x[i]].se].fi;
		if(lnw!=par)nw = 0,lnw = par;
		while(nw<lvl[par].size() && lvl[par][nw]!=vis[x[i]].se)nw++;
		if(nw==lvl[par].size())return cout<<"No",0;
	}
	cout<<"Yes";
    return 0;
}