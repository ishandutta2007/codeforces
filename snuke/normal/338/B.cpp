#include<cstdio>
#include<algorithm>
#include<stack>
#include<queue>
#include<vector>
#include<string>
#include<string.h>
#include<cstdlib>
#include<ctime>
#include<cmath>
#include<map>
#include<set>
#include<bitset>
#include<iostream>
#include<sstream>
#define fi first
#define se second
#define rep(i,n) for(int i = 0; i < n; i++)
#define rrep(i,n) for(int i = 1; i <= n; i++)
#define drep(i,n) for(int i = n-1; i >= 0; i--)
#define each(it,c) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define rng(a) a.begin(),a.end()
#define maxs(x,y) x = max(x,y);
#define mins(x,y) x = min(x,y);
#define pb push_back
#define snuke srand((unsigned)clock())
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;

const int MX = 100005, INF = 1000000000, mod = 1000000009;
const ll LINF = 1000000000000000000ll;
const double eps = 1e-9;
const int dx[4] = {-1,0,1,0}, dy[4] = {0,-1,0,1}; //<^>v

int d;
bool e[MX];
vector<int> to[MX], x[MX];
int ans;

int dfs(int v, int p=-1){
	int res = -INF;
	if(e[v]) res = 0;
	rep(i,to[v].size()){
		int u = to[v][i];
		if(u == p) continue;
		x[v][i] = dfs(u,v);
		res = max(res,x[v][i]);
	}
	return res+1;
}

void dfs2(int v, int dep, int p=-1){
	int a = dep, b = -INF;
	if(e[v]) b = 0;
	if(a < b) swap(a,b);
	rep(i,to[v].size()){
		int u = to[v][i];
		if(u == p) continue;
		//printf("%d %d %d %d\n",v,u,i,x[v][i]);
		if(b < x[v][i]) b = x[v][i];
		if(a < b) swap(a,b);
	}
	//printf("%d %d %d\n",v,a,b);
	if(a <= d) ans++;
	
	rep(i,to[v].size()){
		int u = to[v][i];
		if(u == p) continue;
		dfs2(u,(a == x[v][i]?b:a)+1,v);
	}
}


int main(){
	int n, m, a, b;
	scanf("%d%d%d",&n,&m,&d);
	rep(i,m){
		scanf("%d",&a);
		e[a-1] = true;
	}
	rep(i,n-1){
		scanf("%d%d",&a,&b);
		a--; b--;
		to[a].pb(b);
		to[b].pb(a);
		x[a].pb(-INF);
		x[b].pb(-INF);
	}
	
	dfs(0);
	dfs2(0,-INF);
	
	cout << ans << endl;
	
	return 0;
}