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
const int MAX = 1e2+5;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll MOD2 = 2010405347;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 555;

int n,m,a,b,vis[MAX],nw,nx;
ll dp[MAX][3],mem[MAX],ttl,mx;
vector<int> v[MAX];
bool st[MAX][MAX];
queue<int> q;

ll dfs(int nw,int par){
	st[nw][par] = 1;
	if(mem[nw]!=-1)return mem[nw];
	if(nw==1)return mem[nw] = 1;
	ll ret = 0;
	for(int i:v[nw])if(vis[i]==vis[nw]-1)ret+= dfs(i,nw);
	return mem[nw] = ret;
}

ll f(int nw,int pt){
	if(nw==n)return pt;
	if(dp[nw][pt]!=-1)return dp[nw][pt];
	ll ret = 0;
	for(int i:v[nw])ret+= f(i,pt+(nw==a||i==a));
	return dp[nw][pt] = ret;
}

int main(){
 cout<<fixed<<setprecision(10);
// freopen("trip.in", "r", stdin);
// freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    rep(i,1,m){
    	cin>>a>>b;
    	v[a].pb(b);
    	v[b].pb(a);
	}
	q.push(1);
	vis[1] = 1;
	while(!q.empty()){
		nw = q.front(), q.pop();
		for(int i:v[nw])if(!vis[i]){
			vis[i] = vis[nw]+1;
			q.push(i);
		}
	}
	mems(mem,-1);
	ttl = dfs(n,0);
	rep(i,1,n){
		v[i].clear();
		rep(j,1,n)if(st[i][j])v[i].pb(j);
	}
	rep(i,1,n){
		a = i;
		mems(dp,-1);
//		cout<<i<<" = "<<f(1,0)<<endl;
		mx = max(mx,f(1,0));
	}
	cout<<(double)mx/ttl<<endl;
    return 0;
}