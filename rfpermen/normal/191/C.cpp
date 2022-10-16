#include <bits/stdc++.h>
 
#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
 
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,n,N) for(int i=n;i<=N;++i)
#define asd(i,n,N) for(int i=n;i< N;++i)
#define rap(i,n,N) for(int i=n;i>=N;--i)
#define mp make_pair
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
#define fi first
#define se second
//#define ff fi.fi
//#define fs fi.se
#define sf se.fi
#define ss se.se
#define lc (id<<1)
#define rc ((id<<1)|1)
#define db(x) cout << ">>>> " << #x << " -> " << x << endl
#define mems(x,y) memset(x,y,sizeof x)
#define all(x) x.begin(),x.end()
#define rng() ((rand()<<16)|rand())
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define plll pair<ll,pll>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl '\n'
const int MAX = 1e5+5;
const ll MAX2 = 11;
const ll MOD = 420691273;
const ll MOD2 = 2010405347;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 555;

int n,a,b,q,sp[17][MAX],x[MAX],hs[MAX],ans[MAX];
pii dep[MAX];
vector<pii> v[MAX];

void dfs(int nw,int par){
	dep[nw].se = nw;
	for(pii i:v[nw])if(i.fi!=par){
		dep[i.fi].fi = dep[nw].fi+1;
		sp[0][i.fi] = nw;
		hs[i.fi] = i.se;
		dfs(i.fi,nw);
	}
	return;
}

inline int lca(int x,int y){
	if(dep[x].fi<dep[y].fi)swap(x,y);
	rap(i,16,0)if(dep[x].fi-(1<<i)>=dep[y].fi)x = sp[i][x];
	if(x==y)return x;
	rap(i,16,0)if(sp[i][x]!=sp[i][y]){
		x = sp[i][x];
		y = sp[i][y];
	}
	return sp[0][x];
}

inline void que(int a,int b){
	++x[a], ++x[b], x[lca(a,b)]-= 2;
	return;
}

int main(){
// cout<<fixed<<setprecision(10);
// freopen("trip.in", "r", stdin);
// freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    rep(i,2,n){
    	cin>>a>>b;
    	v[a].pb({b,i});
    	v[b].pb({a,i});
	}
	dep[1].fi = 1;
	dfs(1,0);
	rep(j,1,16)rep(i,1,n)sp[j][i] = sp[j-1][sp[j-1][i]];
	cin>>q;
	while(q--){
		cin>>a>>b;
		que(a,b);
	}
	sort(dep+1,dep+1+n);
	rap(i,n,2)ans[hs[dep[i].se]] = x[dep[i].se], x[sp[0][dep[i].se]]+= x[dep[i].se];
	rep(i,2,n)cout<<ans[i]<<' '; cout<<endl;
    return 0;
}