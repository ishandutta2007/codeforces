#include <bits/stdc++.h>
 
#pragma GCC optimize("O3")
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,n,N) for(int i=n;i<=N;++i)
#define rap(i,n,N) for(int i=n;i>=N;--i)
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
#define lc (id<<1)
#define rc ((id<<1)|1)
#define db(x) cout << ">>>>>> " << #x << " -> " << x << endl
#define all(x) x.begin(),x.end()
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define plll pair<ll,pll>
#define pllll pair<pll,pll>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl '\n'
const int MAX = 1e5+5;
const ll MAX2 = 11;
const ll MOD = 998244353;
const ll MOD2 = 1000000006;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 316;
 
int n,q,a,b,sp[17][MAX],dep[MAX],bt,ret;
vector<int> v[MAX];

void dfs(int nw,int par){
	for(int i:v[nw])if(i!=par){
		dep[i] = dep[nw]+1;
		sp[0][i] = nw;
		dfs(i,nw);
	}
	return;
}

inline int lca(int x,int y){
	if(dep[x]<dep[y])x^=y^=x^=y;
	rap(i,bt,0)if(dep[x]-(1<<i)>=dep[y])x = sp[i][x];
	if(x==y)return x;
	
	rap(i,bt,0){
		if(sp[i][x]!=sp[i][y]){
			x = sp[i][x];
			y = sp[i][y];
		}
	}
	return sp[0][x];
}

inline int ds(int x,int y){
	return dep[x] + dep[y] - (dep[lca(x,y)]<<1);
}

int main(){
//	cout<<fixed<<setprecision(2);
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
	dfs(1,0);
	rep(i,1,n)bt = max(bt,dep[i]);
	bt = log2(bt);
	rep(i,1,bt)rep(j,1,n)sp[i][j] = sp[i-1][sp[i-1][j]];
	
	int x,y,k;
	cin>>q;
	while(q--){
		cin>>x>>y>>a>>b>>k;
		//biasa
		ret = ds(a,b);
		if(ret<=k&&(ret&1)==(k&1)){cout<<"YES\n"; continue;}
		ret = ds(a,x) + 1 + ds(y,b);
		if(ret<=k&&(ret&1)==(k&1)){cout<<"YES\n"; continue;}
		ret = ds(a,y) + 1 + ds(x,b);
		if(ret<=k&&(ret&1)==(k&1)){cout<<"YES\n"; continue;}
		cout<<"NO\n";
	}
    return 0;
}