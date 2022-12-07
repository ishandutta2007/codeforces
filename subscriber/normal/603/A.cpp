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
#define forn(i, n) for(int i = 0 ; (i) < (n) ; ++i)
#define M 1000000007
#define N 211111

#define TASK "1"

using namespace std;
typedef pair<int,int> pt;

int n;
char s[N];

int dp[N][3][2];

int main(){
//	freopen(TASK".in","r",stdin);	
//	freopen(TASK".out","w",stdout);
	scanf("%d\n", &n);
	gets(s);
	for (int i = 0; i <= n; i++) for (int j = 0; j <= 2; j++) for (int k = 0; k < 2; k++) dp[i][j][k] = -1e9 -1;
	dp[0][0][0] = 0;
	dp[0][0][1] = 0;

	for (int i = 0; i < n; i++) for (int j = 0; j <= 2; j++) for (int k = 0; k < 2; k++) if (dp[i][j][k] >= 0) {

		int cur = s[i] - '0';
		if (j == 1) cur ^= 1;
		dp[i + 1][j][k] = max(dp[i + 1][j][k], dp[i][j][k]);

		if (cur == k) dp[i + 1][j][k ^ 1] = max(dp[i + 1][j][k ^ 1], dp[i][j][k] + 1);

		if (j <= 1) dp[i][j + 1][k] = max(dp[i][j + 1][k], dp[i][j][k]);
	}
	int ans = 0;
	for (int j = 0; j <= 2; j++) for (int k = 0; k < 2; k++) ans = max(ans, dp[n][j][k]);
	cout << ans << endl;
	return 0;
}