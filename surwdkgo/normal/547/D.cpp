#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cstring>
#include <cassert>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define SIZE(x) (int((x).size()))
#define rep(i,l,r) for (int i=(l); i<=(r); i++)
#define repd(i,r,l) for (int i=(r); i>=(l); i--)
#define rept(i,c) for (typeof((c).begin()) i=(c).begin(); i!=(c).end(); i++)
#ifndef ONLINE_JUDGE
#define debug(x) { cerr<<#x<<" = "<<(x)<<endl; }
#else
#define debug(x) {}
#endif
int n;
int inp[200010][2];
int vis[800010];
int m;
char ans[400010];
char cur;
struct E{
	int t, id;
	E(){}
	E(int _t, int _id) : t(_t),id(_id){}
};
vector<E> edg[400010];
int usd[400010];
const int MAXN = 200000;

void dfs(int v) {
	for(;usd[v] < edg[v].size(); usd[v]++) {
		E& e = edg[v][usd[v]];
		if (!vis[e.id]) {
			vis[e.id] = 1;
			ans[e.id] = cur;
			//printf("%d\n", e.id);
			cur = 'r'+'b'-cur;
			dfs(e.t);
		}
	}
}

void addE(int u,int v,int id) {
	edg[u].push_back(E(v,id));
	edg[v].push_back(E(u,id));
}
void lemon() {  
	scanf("%d",&n);
	rep(i,1,n) {
		scanf("%d%d",&inp[i][0],&inp[i][1]);
		assert(inp[i][0] <= MAXN && inp[i][0] >= 1);
		assert(inp[i][1] <= MAXN && inp[i][1] >= 1);
		addE(inp[i][0],inp[i][1]+MAXN,i);
	}
	m=n+1;
	rep(i,1,2*MAXN) {
		if (edg[i].size() % 2) addE(0,i,++m);
	}
	cur = 'r';
	rep(i,0,2*MAXN) {
		dfs(i);
	}
	rep(i,1,n) assert(vis[i]==1);
	puts(ans+1);
}
int main() {
  ios::sync_with_stdio(true);
  #ifndef ONLINE_JUDGE
    freopen("D.in","r",stdin);
  #endif
  lemon();
  return 0;
}