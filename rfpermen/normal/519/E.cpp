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
#define pii pair<int,int> 
#define pdd pair<double,double> 
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

int n,a,b,c,sp[17][MAX],dep[MAX],bt,q,sz[MAX],c1,c2,tgt;
vector<int> v[MAX];

void dfs(int nw){
	sz[nw] = 1;
	for(auto i:v[nw]){
		if(dep[i])continue;
		dep[i] = dep[nw]+1;
		sp[0][i] = nw;
		dfs(i);
		sz[nw]+=sz[i];
	}
	return;
}
inline void init(){
	rep(j,1,bt)rep(i,1,n)if(sp[j-1][i])sp[j][i] = sp[j-1][sp[j-1][i]];
}

inline int lca(int x,int y){
	rap(i,bt,0)if(dep[sp[i][x]]>=dep[y])x = sp[i][x];
	if(x==y)return x;
	
	rap(i,bt,0){
		if(sp[i][x]==sp[i][y])continue;
		x = sp[i][x];
		y = sp[i][y];
	}
	c1 = x, c2 = y;
	return sp[0][x];
}

int main(){
//	cout<<fixed<<setprecision(10);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    rep(i,2,n){
    	cin>>a>>b;
    	v[a].pb(b);
    	v[b].pb(a);
	}
	dep[1] = 1;
	dfs(1);
	bt = log2(n);
	init();
	cin>>q;
	while(q--){
		cin>>a>>b;
		if(dep[a]<dep[b])a^=b^=a^=b;
		if(a==b)cout<<n<<endl;
		else if(dep[a]==dep[b]){
			c = lca(a,b);
//			cout<<c1<<" "<<c2<<" "<<c<<endl;
			cout<<n-sz[c1]-sz[c2]<<endl;
		}
		else if((dep[a]-dep[b])&1)cout<<0<<endl;
		else {
			c = lca(a,b);
			tgt = dep[a]-(dep[a]+dep[b]-dep[c]-dep[c])/2;
			rap(i,bt,0)if(dep[sp[i][a]]>tgt)a = sp[i][a];
			c = sp[0][a];
//			cout<<"ini "<<a<<" "<<c<<endl;
			cout<<sz[c]-sz[a]<<endl;
		}
	}
    return 0;
}