#include <bits/stdc++.h>

#pragma GCC optimize("O2")
using namespace std;
#define ll long long
#define rep(i,n,N) for(int i=n;i<=N;i++)
#define rap(i,n,N) for(int i=(int)n;i>=(int)N;i--)
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
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define endl "\n"
const int MAX=1e5+5;
const ll MAX2 = 11;
const int MOD=1000000000 + 7;
const ll INF=20000;
const int dr[]={1,0,-1,0,1,1,-1,-1};
const int dc[]={0,1,0,-1,1,-1,1,-1};
const double pi = acos(-1);


int n,m,cnt,a,b;
vector<int> v[MAX];
bool vis[MAX],x[MAX];

void dfs(int nw,int k){
	vis[nw] = 1;
	if(v[nw].size()==1&&nw!=1){
		cnt++; return;
	}
	for(auto i:v[nw]){
		if(x[i]&&k==m)continue;
		if(vis[i])continue;
		if(x[i])dfs(i,k+1);
		else dfs(i,0);
	}
}

int main(){
	cout<<fixed<<setprecision(10);
    //freopen("input.txt", "r", stdin);
	//freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    rep(i,1,n)cin>>x[i];
    rep(i,2,n){
    	cin>>a>>b;
    	v[a].pb(b), v[b].pb(a);
	}
    if(x[1])dfs(1,1);
    else dfs(1,0);
    cout<<cnt<<endl;
    return 0;
}