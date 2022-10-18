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
int n, m;
int dp[1048580];
char inp[30][30];
int pri[30][30];
int cnt[300], cst[300], msk[300], mni[300];
void update(int ms, int v) {
	rep(i,0,(1<<n)-1) {
		//printf("%d ", dp[i]);
		dp[i|ms] = min(dp[i|ms], dp[i]+v);
	}
	//puts("");
}
void lemon() {  
	scanf("%d%d", &n, &m);
	rep(i,0,n-1) scanf("%s", inp[i]);
	rep(i,0,n-1) rep(j,0,m-1) scanf("%d", &pri[i][j]);
	memset(dp, 63, sizeof(dp));
	dp[0] = 0;
	rep(i,0,m-1) {
		memset(cnt, 0, sizeof(cnt));
		memset(msk, 0, sizeof(msk));
		memset(cst, 0, sizeof(cst));
		memset(mni, 0, sizeof(mni));
		rep(j,0,n-1) {
			cnt[inp[j][i]] ++;
			cst[inp[j][i]] += pri[j][i];
			mni[inp[j][i]] = max(mni[inp[j][i]], pri[j][i]);
			msk[inp[j][i]] |= 1<<j;
		}
		rep(j,0,n-1) {
			update(1<<j, pri[j][i]);
		}
		rep(j,0,270) {
			if (msk[j]) {
				update(msk[j], cst[j] - mni[j]);
			}
		}
	}
	printf("%d\n", dp[(1<<n)-1]);
}
int main() {
  ios::sync_with_stdio(true);
  #ifndef ONLINE_JUDGE
  //  freopen("","r",stdin);
  #endif
  lemon();
  return 0;
}