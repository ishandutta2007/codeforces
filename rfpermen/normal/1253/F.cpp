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
const int MAX = 3e5+5;
const ll MAX2 = 11;
const ll MOD = 998244353;
const ll MOD2 = 1000000006;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 316;

ll n,m,k,q,a,b,c,nx,nc,vis[MAX],ans[MAX],x[MAX],y[MAX];
int p[MAX],le[MAX],ri[MAX],que;
plll e[MAX];
vector<int> gs[MAX];
vector<pll> v[MAX];
priority_queue<pll, vector<pll>, greater<pll>> pq;

int par(int z){
	if(p[z]==z)return z;
	return p[z] = par(p[z]);
}

int main(){
//	cout<<fixed<<setprecision(10);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m>>k>>q;
    rep(i,1,m){
    	cin>>a>>b>>c;
    	v[a].pb({b,c}), v[b].pb({a,c});
    	e[i] = {c,{a,b}};
	}
	rep(i,k+1,n)vis[i] = INF;
	rep(i,1,k)pq.push({0,i});
	while(!pq.empty()){
		c = pq.top().fi, a = pq.top().se; pq.pop();
		if(vis[a]<c)continue;
		for(auto i:v[a]){
			nx = i.fi, nc = c+i.se;
			if(vis[nx]<=nc)continue;
			vis[nx] = nc;
			pq.push({nc,nx});
		}
	}
	rep(i,1,m)e[i].fi+= vis[e[i].sf] + vis[e[i].ss];
	sort(e+1,e+1+m);
	
	rep(i,1,q){
		cin>>x[i]>>y[i];
		le[i] = 1, ri[i] = m, gs[m+1>>1].pb(i);
	}
	
	que = q;
	while(que){
		rep(i,1,n)p[i] = i;
		
		rep(i,1,m){
			a = par(e[i].sf), b = par(e[i].ss);
			if(a!=b)p[a] = b;
			
			for(auto j:gs[i]){
				if(par(x[j])==par(y[j]))ri[j] = i-1, ans[j] = e[i].fi;
				else le[j] = i+1;
				if(le[j]<=ri[j])gs[le[j]+ri[j]>>1].pb(j);
				else --que;
			}
			gs[i].clear();
		}
	}
	rep(i,1,q)cout<<ans[i]<<endl;
    return 0;
}