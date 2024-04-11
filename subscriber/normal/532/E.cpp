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
char a[N], b[N];

int dp[N][2][2];

int main(){
//	freopen(TASK".in","r",stdin);	
//	freopen(TASK".out","w",stdout);
	scanf("%d\n", &n);
	gets(a);
	gets(b);

	int eq = 1;
	for (int i = 0; i < n; i++) if (a[i] != b[i]) eq = 0;

	if (eq) {
		int ans = 0;
		for (char c = 'a'; c <= 'z'; c++) {
			for (int i = 0; i <= n; i++) if (i == n || a[i] != c) ans++;
		}
		cout << ans << endl;
		return 0;		
	}

	dp[0][0][0] = 1;
	int len = n + 1;
	for (int i = 0; i < len; i++) for (int x = 0; x < 2; x++) for (int y = 0; y < 2; y++) if (dp[i][x][y] != 0) {
		if (a[i - x] == b[i - y]) {
			dp[i + 1][x][y] += dp[i][x][y];
		}
		if (x == 0 && (i == len - 1 || a[i] != b[i - y])) {
			dp[i + 1][1][y] += dp[i][x][y];
		}
		if (y == 0 && (i == len - 1 || b[i] != a[i - x])) {
			dp[i + 1][x][1] += dp[i][x][y];
		}
	}
	cout << dp[len][1][1] << endl;
	return 0;
}