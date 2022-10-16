#include <bits/stdc++.h>
 
#pragma GCC optimize("O3")
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,n,N) for(ll i=n;i<=N;++i)
#define rap(i,n,N) for(ll i=n;i>=N;--i)
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
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl "\n"
const int MAX = 2e5+5;
const ll MAX2 = 11;
const ll MOD = 998244353;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 450;
 
ll n,m,k,a,b,c,p[MAX],bt,vis[404][404],hs[MAX],id;
vector<ll> sz[MAX],ans;
vector<pll> v[MAX];
vector<plll> ee[MAX];
plll e[MAX];

int par(int z){
	if(p[z]==z)return z;
	return p[z] = par(p[z]);
}

int main(){
//	cout<<fixed<<setprecision(10);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m>>k;
    rep(i,1,n)p[i] = i, sz[i].pb(i);
    rep(i,1,m){
    	cin>>a>>b>>c;
    	v[a].pb({b,c});
    	v[b].pb({a,c});
    	e[i] = {c,{a,b}};
	}
	sort(e+1,e+1+m);
	bt = min(m,k);
	rep(i,1,bt){
		a = par(e[i].sf), b = par(e[i].ss);
		if(a==b)ee[a].pb(e[i]);
		else {
			if(sz[a].size()<sz[b].size())swap(a,b);
			for(auto j:sz[b])sz[a].pb(j);
			for(auto j:ee[b])ee[a].pb(j);
			sz[b].clear();
			ee[b].clear();
			ee[a].pb(e[i]);
			p[b] = a;
		}
	}
	rep(i,1,n){
		if(sz[i].size()<2)continue;
		id = 0;
		for(auto j:sz[i])hs[j] = ++id;
		rep(j,1,id)rep(o,1,id){
			if(j!=o)vis[j][o] = INF;
		}
		for(auto j:ee[i]){
			vis[hs[j.sf]][hs[j.ss]] = min(vis[hs[j.sf]][hs[j.ss]],j.fi);
			vis[hs[j.ss]][hs[j.sf]] = min(vis[hs[j.ss]][hs[j.sf]],j.fi);
		}
		rep(c,1,id)rep(a,1,id)rep(b,1,id)vis[a][b] = min(vis[a][b],vis[a][c]+vis[c][b]);
//		rep(j,1,id){
//			rep(o,1,id)cout<<vis[j][o]<<' ';
//			cout<<endl;
//		}
		rep(j,1,id)rep(o,j+1,id)ans.pb({vis[j][o]});
	}
	sort(all(ans));
	cout<<ans[k-1]<<endl;
	return 0;
}