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
const int MAX = 2e5+5;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll MOD2 = 2010405347;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 555;

int tc,a,b,c,d,p[MAX];
ll ans,n,cnt,y,sis;
vector<int> v[MAX];
bool vis[MAX];

int par(int z){
	if(p[z]==z)return z;
	return p[z] = par(p[z]);
}

bool dfs(int nw,int par){
	vis[nw] = 1;
	if(nw==d)return 1;
	for(int i:v[nw])if(i!=par){
		if(dfs(i,nw))return 1;
	}
	vis[nw] = 0;
	return 0;
}

int lol(int nw,int par){
	int ret = 1;
	for(int i:v[nw])if(i!=par &&!vis[i]){
		ret+= lol(i,nw);
	}
	return ret;
}

int main(){
// cout<<fixed<<setprecision(6);
// freopen("trip.in", "r", stdin);
// freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>tc;
    rep(ntc,1,tc){
    	cin>>n;
    	rep(i,1,n)p[i] = i, v[i].clear(), vis[i] = 0;
    	rep(i,1,n){
    		cin>>a>>b;
    		if(par(a)!=par(b))v[a].pb(b), v[b].pb(a);
    		else c = a, d = b;
    		p[par(a)] = par(b);
		}
		ans = n*(n-1)/2;
//		db(ans);
		cnt = 0;
		dfs(c,0);
//		rep(i,1,n)cout<<vis[i]; cout<<endl;
		rep(i,1,n)if(vis[i])++cnt;
		sis = n-cnt;
		rep(i,1,n)if(vis[i]){
			y = lol(i,0);
			--y;
			sis-= y;
			if(y)ans+= y*(cnt+sis-1);
		}
		ans+= cnt*(cnt-1)/2;
		cout<<ans<<endl;
	}
    return 0;
}