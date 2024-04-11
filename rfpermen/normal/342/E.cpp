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
#define db(x) cerr << ">>>>>> " << #x << " -> " << x << endl
#define nani(x) cerr <<  "Line " << __LINE__ << ": " << #x << " is " << x << endl
#define all(x) x.begin(),x.end()
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define plll pair<ll,pll>
#define pllll pair<pll,pll>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl '\n'
const int MAX = 2e5+5;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll MOD2 = 1000000006;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 2000;

int n,q,a,b,par_cen[MAX],sz[MAX],dep[MAX],sp[18][MAX],res[MAX],ans,bt;
bool rem[MAX];
vector<int> v[MAX];

void dfs(int nw,int par){
	for(auto i:v[nw]){
		if(i==par)continue;
		dep[i] = dep[nw]+1;
		sp[0][i] = nw;
		dfs(i,nw);
	}
	return;
}

void com_cen(int nw,int par){
	sz[nw] = 1;
	for(auto i:v[nw]){
		if(i==par || rem[i])continue;
		com_cen(i,nw);
		sz[nw]+= sz[i];
	}
	return;
}

int build_cen(int nw){
	com_cen(nw,0);
	int siz = sz[nw]>>1; bool found = false;
	while(!found){
		found = true;
		for(auto i:v[nw]){
			if(!rem[i] && sz[i]<sz[nw]){
				if(sz[i]>siz){
					nw = i;
					found = false;
					break;
				}
			}
		}
	}
	rem[nw] = true;
	for(auto i:v[nw])if(!rem[i])par_cen[build_cen(i)] = nw;
	return nw;
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

inline int dist(int x,int y){
	return dep[x] + dep[y] - (dep[lca(x,y)]<<1);
}

int ty;

int main(){
//	cout<<fixed<<setprecision(10);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>q;
    rep(i,2,n){
    	cin>>a>>b;
    	v[a].pb(b), v[b].pb(a);
	}
	dep[1] = 1;
	dfs(1,0);
	build_cen(1);
	rep(i,1,n)bt = max(bt,dep[i]);
	bt = log2(bt);
	rep(i,1,bt)rep(j,1,n)sp[i][j] = sp[i-1][sp[i-1][j]];
	rep(i,1,n)res[i] = MAX;
	a = b = 1;
	while(a){
		res[a] = min(res[a],dist(a,b));
		a = par_cen[a];
	}
	while(q--){
		cin>>ty>>a; b = a;
		if(ty==1){
			while(a){
				res[a] = min(res[a],dist(a,b));
				a = par_cen[a];
			}
		}
		else {
			ans = MAX;
			while(a){
				ans = min(ans,dist(a,b)+res[a]);
				a = par_cen[a];
			}
			cout<<ans<<endl;
		}
	}
    return 0;
}