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

int n,a,b,c,cnt,p[MAX],vis[MAX];
pii x[MAX];
vector<int> v[MAX];

bool dfs(int z){
	vis[z] = 1;
	if(z==b)return 1;
	bool res = 0;
	for(auto i:v[z]){
		if(vis[i])continue;
		res|=dfs(i);
	}
	return res;
}

int main(){
	cout<<fixed<<setprecision(0);
    //freopen("input.txt", "r", stdin);
	//freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    rep(XXX,1,n){
    	cin>>c>>a>>b;
    	if(c==1){
    		x[++cnt] = {a,b};
    		p[cnt] = cnt;
    		rep(i,1,cnt-1){
    			if((x[i].fi<x[cnt].fi && x[cnt].fi<x[i].se )|| (x[i].fi<x[cnt].se && x[cnt].se<x[i].se)){
    				v[cnt].pb(i);
				}
				if((x[cnt].fi<x[i].fi && x[i].fi<x[cnt].se ) || (x[cnt].fi<x[i].se && x[i].se<x[cnt].se )){
					v[i].pb(cnt);
				}
			}
		}
		else {
			memset(vis,0,sizeof vis);
			if(dfs(a))cout<<"YES\n";
			else cout<<"NO\n";
		}
	}
    return 0;
}