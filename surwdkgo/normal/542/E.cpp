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
int dis[1010][1010];
int n,m;
int vis[1010];
void lemon() {
	scanf("%d%d",&n,&m);
	rep(i,1,n) rep(j,i+1,n) {
		dis[j][i] = dis[i][j] = n+1;
	}  
	rep(i,0,m-1) {
		int u,v;
		scanf("%d%d",&u,&v);
		dis[u][v] = dis[v][u] = 1;
	}
	rep(k,1,n)
	rep(i,1,n)
	rep(j,i+1,n) {
		if (dis[i][j] > dis[i][k] + dis[k][j]) {
			dis[j][i] = dis[i][j] = dis[i][k]+dis[k][j];
		}
	} 
	int ans=0;
	rep(i,1,n) {
		if (!vis[i]) {
			vector<int> chk;
			rep(j,1,n) {
				if (dis[i][j] < n) chk.push_back(j);
			}
			int mxa=0;
			rept(it,chk) {
				rept(it2,chk) {
					if (dis[*it][*it2] > mxa) mxa =dis[*it][*it2];
					if ((dis[*it][*it2] + dis[*it][i] + dis[i][*it2]) %2 ) mxa = n+1;
				}
				vis[*it] = 1;
			}
			ans += mxa;
		}
	}
	if (ans > n) ans = -1;
	printf("%d\n", ans);

}
int main() {
  ios::sync_with_stdio(true);
  #ifndef ONLINE_JUDGE
 //   freopen("","r",stdin);
  #endif
  lemon();
  return 0;
}