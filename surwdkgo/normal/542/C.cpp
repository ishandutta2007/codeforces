#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cstring>
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
int inp[310];
int vis[310];
LL lcm;
LL mp;
LL gcd(LL a, LL b) {
	if (!b) return a;
	return gcd(b, a%b);
}
void dfs(int i, int c) {
	if (vis[i]) {
		mp = max(mp, (LL)vis[i]-1);
		lcm = lcm * (c-vis[i]) / gcd(lcm, c-vis[i]);
		return;
	}
	vis[i] = c;
	dfs(inp[i], c+1);
}
void lemon() {
	scanf("%d", &n);
	rep(i,1,n) scanf("%d", &inp[i]);
	lcm = 1;
	mp = 1;
	rep(i,1,n) {
		memset(vis,0,sizeof(vis));
		dfs(i, 1);
	}
	cout << lcm*((mp + lcm-1)/lcm) << endl;
}
int main() {
  ios::sync_with_stdio(true);
  #ifndef ONLINE_JUDGE
 //   freopen("","r",stdin);
  #endif
  lemon();
  return 0;
}