#include <bits/stdc++.h>
 
#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
 
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,n,N) for(ll i=n;i<=N;++i)
#define asd(i,n,N) for(int i=n;i< N;++i)
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
const int MAX = 3e5+5;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll MOD2 = 1000005329;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 320;

int n,m,q,ty,a,b,x,y,p[MAX],len[MAX],vis[MAX],mx[MAX];
vector<int> v[MAX];

void dfs(int nw,int par){
	for(int i:v[nw])if(i!=par){
		vis[i] = vis[nw]+1;
		dfs(i,nw);
	}
	return;
}
int par(int z){
	if(p[z]==z)return z;
	return p[z] = par(p[z]);
}

int main(){
// cout<<fixed<<setprecision(6);
// freopen("trip.in", "r", stdin);
// freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m>>q;
    rep(i,1,n)p[i] = i;
    while(m--){
    	cin>>a>>b;
		v[a].pb(b), v[b].pb(a);
		p[par(a)] = par(b);
	}
    mems(vis,-1);
    rep(i,1,n)if(vis[i]==-1)vis[i] = 1, dfs(i,0);
    rep(i,1,n)if(vis[mx[par(i)]]<vis[i])mx[par(i)] = i;
    rep(i,1,n)if(mx[par(i)]==i)vis[i] = 1, dfs(i,0);
    rep(i,1,n)len[par(i)] = max(len[par(i)], vis[i]);
//    rep(i,1,n)cout<<i<<" = "<<len[i]<<endl;
	while(q--){
		cin>>ty>>a;
		if(ty==1)cout<<len[par(a)]-1<<endl;
		else {
			cin>>b;
			a = par(a), b = par(b);
			if(a!=b){
				p[a] = b;
				len[b] = max(max(len[a],len[b]), (len[a]/2+1)+(len[b]/2+1));
			}
		}
	}
    return 0;
}