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

const int maxs = 100 * 1000;

int n, m;
int x[1111];
long double dp[107][maxs + 5555];

int main(){
//	freopen(TASK".in","r",stdin);	
//	freopen(TASK".out","w",stdout);
	cin >> n >> m;
	int my = 0;
	for (int i = 0; i < n; i++) {
		cin >> x[i];
		my += x[i];
	}		
	
	dp[0][0] += 1;
	dp[0][1] -= 1;

	for (int i = 0; i <= n; i++) {
		for (int j = 1; j <= maxs; j++) dp[i][j] += dp[i][j - 1];

		if (i == n) break;

		for (int j = 0; j <= maxs; j++) {
			if (x[i] != 1) {
				int d = x[i] - 1;
				dp[i + 1][j + 1] += dp[i][j] / (m - 1);
				dp[i + 1][j + 1 + d] -= dp[i][j] / (m - 1);
			}
			if (x[i] != m) {
				int d = m - x[i];
				dp[i + 1][j + x[i] + 1] += dp[i][j] / (m - 1);
				dp[i + 1][j + x[i] + 1 + d] -= dp[i][j] / (m - 1);
			}
		}
	}
	long double ans = 0;
	for (int i = 0; i < my; i++) ans += dp[n][i];
	ans *= (m - 1);
	ans += 1;
	printf("%.15lf\n", (double)ans);
	return 0;
}