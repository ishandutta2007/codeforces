#include<stdio.h>
#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<memory.h>
#include<map>
#include<set>
#include<queue>
#include<list>
#include<sstream>
#include<cstring>
#define mp make_pair
#define pb push_back      
#define F first
#define S second
#define SS stringstream
#define sqr(x) ((x)*(x))
#define m0(x) memset(x,0,sizeof(x))
#define m1(x) memset(x,63,sizeof(x))
#define CC(x) cout << (x) << endl
#define pw(x) (1ll<<(x))
#define buli(x) __builtin_popcountll(x)
#define M 1000000007
#define N 211111

#define TASK "1"

using namespace std;
typedef pair<int,int> pt;

int n;
int a[1111], b[1111];
int dp[1111][1111];

int main(){
//	freopen(TASK".in","r",stdin);	
//	freopen(TASK".out","w",stdout);
 	cin >> n;
 	for (int i = 0; i < n; i++) scanf("%d%d", &a[i], &b[i]);
 	for (int i = 0; i <= n; i++) for (int j = 0; j <= 1000; j++) dp[i][j] = 1e9 + 1;

 	dp[0][0] = 0;
 	for (int i = 0; i < n; i++) for (int j = 0; j <= 1000; j++) if (dp[i][j] < 1e9) {
 		dp[i + 1][max(j, a[i])] = min(dp[i + 1][max(j, a[i])], dp[i][j] + b[i]);


 		dp[i + 1][max(j, b[i])] = min(dp[i + 1][max(j, b[i])], dp[i][j] + a[i]);
 	}
 	long long ans = 1e18 + 1;
 	for (int j = 0; j <= 1000; j++) if (dp[n][j] < 1e9) ans = min(ans, dp[n][j] * 1ll * j);
 	cout << ans << endl;
	return 0;
}