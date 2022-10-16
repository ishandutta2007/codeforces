#include <bits/stdc++.h>
 
#pragma GCC optimize("O3")
#pragma GCC target("tune=native")
//#pragma GCC optimize("unroll-loops")
 
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
#define ff fi.fi
#define fs fi.se
#define sf se.fi
#define ss se.se
#define lc (id<<1)
#define rc ((id<<1)|1)
#define db(x) cout << ">>>> " << #x << " -> " << (x) << endl
#define out(x,y) cout << ">> " << (x) << " " << (y) << endl
//#define size(n) ((int)(n).size())
#define mems(x,y) memset(x,y,sizeof x)
#define all(x) x.begin(),x.end()
#define rng() ((rand()<<16)|rand())
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define plll pair<ll,pll>
#define pllll pair<pll,pll>
#define piii pair<ll,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl '\n'
const int MAX = 2e5+5;
const ll MOD = 1000000007;
const ll MOD2 = 2010405347;
const ll INF = 9e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 600;

#define N 1000020
vector<int> v[N];
bool vis[N], ins[N];
int disc[N], low[N], gr[N];
stack<int> st;
int id,grid;
void scc(int cur, int par){
  disc[cur]=low[cur]=++id;
  vis[cur]=ins[cur]=1;
  st.push(cur);
  for(int to : v[cur]){
//    if (to==par) continue; // ini untuk SO(scc undirected)
    if (!vis[to]) scc(to,cur);
    if (ins[to]) low[cur]=min(low[cur],low[to]);	
  }	
  if (low[cur]==disc[cur]){
    grid++; // group id		
    while(ins[cur]){ 		
      gr[st.top()]=grid; ins[st.top()]=0; st.pop();
    }	
  }
}
int n,m,a,b;
ll c,dp[N],ans,val[N],pre[N];
plll e[N];
vector<pair<int,ll>> u[N];

inline ll cp(ll x){
	ll y = sqrt(2*x);
	while(y*(y+1)/2>x)--y;
	return x*(y+1) - pre[y];
}

ll f(int nw){
	if(dp[nw]!=-1)return dp[nw];
	ll ret = 0;
	for(pair<int,ll> i:u[nw])ret = max(ret,f(i.fi) + i.se);
	return dp[nw] = ret + val[nw];
}

int main(){
//	cout<<fixed<<setprecision(10);
// freopen("trip.in", "r", stdin);
// freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    rep(i,1,1000000)pre[i] = pre[i-1] + ((ll)i*(i+1)>>1);
    cin>>n>>m;
    rep(i,1,m){
    	cin>>e[i].sf>>e[i].ss>>e[i].fi;
    	v[e[i].sf].pb(e[i].ss);
	}
	rep(i,1,n)if(!vis[i])scc(i,0);
	int nw;
	cin>>nw;
	rep(i,1,m){
		if(gr[e[i].sf]==gr[e[i].ss])val[gr[e[i].sf]]+= cp(e[i].fi);
		else u[gr[e[i].sf]].pb({gr[e[i].ss],e[i].fi});
	}
	mems(dp,-1);
	cout<<f(gr[nw])<<endl;
    return 0;
}