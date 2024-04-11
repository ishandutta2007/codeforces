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

int n, m, b, mod;
int a[555];
int dp[555][555], dp2[555][555];

int main(){
//	freopen(TASK".in","r",stdin);	
//	freopen(TASK".out","w",stdout);
	cin >> n >> m >> b >> mod;
	for (int i = 0; i < n; i++) cin >> a[i];
	dp[0][0] = 1 % mod;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= m; j++) for (int k = 0; k <= b; k++) dp2[j][k] = 0;

		for (int j = 0; j <= m; j++) for (int k = 0; k <= b; k++) if (dp[j][k]) {
			if (j < m && k + a[i] <= b) dp[j + 1][k + a[i]] = (dp[j + 1][k + a[i]] + dp[j][k]) % mod;

			dp2[j][k] = (dp2[j][k] + dp[j][k]) % mod;
		}
		for (int j = 0; j <= m; j++) for (int k = 0; k <= b; k++) dp[j][k] = dp2[j][k];
	}
	int ans = 0;
	for (int i = 0; i <= b; i++) ans = (ans + dp[m][i]) % mod;
	cout << ans << endl;

	return 0;
}