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
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl '\n'
const int MAX = 1e5+5;
const ll MAX2 = 11;
const ll MOD = 998244353;
const ll MOD2 = 1000005329;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const long double EPS = 1e-18;
const int block = 2000;

int n,m,p[MAX],a,b,id,ans[MAX],cnt;
piiii e[MAX];
vector<piii> z;
map<pii,int> hs;
set<int> sp;
vector<pii> v[MAX];

int dfs_num[MAX],dfs_low[MAX],dfs_parent[MAX];

int dfsNumberCounter=1, dfsRoot, rootChildren; 
void articulationPointAndBridge(int u){
  dfs_low[u] = dfs_num[u] = dfsNumberCounter++;
  for(auto i:v[u]){
    if (!dfs_num[i.fi]) {
      dfs_parent[i.fi] = u;
      if (u == dfsRoot) rootChildren++;
      articulationPointAndBridge(i.fi);
      if (dfs_low[i.fi] > dfs_num[u]){
      	if(!ans[i.se])ans[i.se] = 2;
	  }
      dfs_low[u] = min(dfs_low[u], dfs_low[i.fi]);
    }
    else if (i.fi != dfs_parent[u])
      dfs_low[u] = min(dfs_low[u], dfs_num[i.fi]);}}
      
int par(int z){
	if(p[z]==z)return z;
	return p[z] = par(p[z]);
}

inline void relax(){
	hs.clear();
	sp.clear();
	for(auto i:z){
		if(hs.count(i.se))ans[hs[i.se]] = ans[i.fi] = 1;
		else {
			a = par(i.ss), b = par(i.sf);
			if(a!=b)++cnt;
			p[a] = b;
			hs[i.se] = i.fi;
			v[i.sf].pb({i.ss,i.fi});
			v[i.ss].pb({i.sf,i.fi});
			sp.insert(i.ss), sp.insert(i.sf);
		}
	}
	for(auto i:sp){
		if(!dfs_num[i]){
			 dfsRoot = i, rootChildren = 0;
			 articulationPointAndBridge(i);
		}
	}
	for(auto i:sp)v[i].clear();
	z.clear();
	return;
}

int main(){
//	cout<<fixed<<setprecision(10);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    rep(i,1,n)p[i] = i;
    rep(i,1,m)cin>>e[i].sf>>e[i].ss>>e[i].ff, e[i].fs = i;
    sort(e+1,e+1+m);
    rep(i,1,m){
    	if(e[i].ff!=e[i-1].ff)relax();
    	a = par(e[i].sf), b = par(e[i].ss), id = e[i].fs;
    	if(a==b){ans[id] = -1; continue;}
    	dfs_num[a] = dfs_num[b] = 0;
    	if(a>b)swap(a,b);
    	z.pb({id,{a,b}});
	}
	if(!z.empty())relax();
	assert(cnt==n-1);
	rep(i,1,m){
		if(ans[i]==-1)cout<<"none\n";
		else if(ans[i]==2)cout<<"any\n";
		else cout<<"at least one\n";
	}
    return 0;
}