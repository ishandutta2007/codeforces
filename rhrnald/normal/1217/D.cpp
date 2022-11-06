#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define repp(i,a) for(int i=1;i<=a;i++)
#define eb emplace_back
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define Fi first
#define Se second
#define INF 987654321
#define IINF 987654321987654321
#define LINF 987654321987654321
//0x3F3F3F3F3F3F3F3Fll
#define sz(v) ((int)((v).size()))
#define all(v) v.begin(),v.end()
#define pq priority_queue
#define BIGMOD 9223372036854775783
#define PI 3.14159265358979
#define eps 1e-7
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<bool,bool> pbb;
typedef pair<ll,ll> pll;
typedef complex<double> base;
typedef pair<bool,int> pbi;
typedef pair<ll,int> pli;
typedef pair<pll,ll> plll;
typedef pair<double,double> pdd;
vector<int> adj[5002],badj[5002];
vector<int> v,inv;
int vis[5002];
void dfs(int a){
	vis[a]=1;
	for(auto &e  : adj[a]){
		if(vis[e]) continue;
		dfs(e);	
	}
	v.pb(a);
}
bool fdfs(int a){
	vis[a]=1;
	for(auto &e : badj[a]){
		if(!vis[e]) return true;
	}
	return false;
}
vector<pii> vv;
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	rep(i,0,m){
		int a,b;
		scanf("%d%d",&a,&b);
		adj[a].pb(b);
		badj[b].pb(a);
		vv.pb({a,b});
		
	}
	rep(i,1,n+1){
		if(!vis[i]) dfs(i);
	}
	memset(vis,0,sizeof(vis));
	bool exist=false;
	while(v.size()){
		int here=v.back();v.pop_back();
		if(vis[here]) continue;
		if(fdfs(here)){
			printf("2\n");
			rep(j,0,m){
				if(vv[j].Fi<vv[j].Se) printf("1 ");
				else printf("2 ");
			}
			printf("\n");
			return 0;
		}
	}
	
	printf("1\n");
	rep(j,0,m){
		printf("1 ");
	}
	printf("\n");
}