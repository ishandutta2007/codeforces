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
#define M 1000000007
#define N 211111
using namespace std;
typedef pair<int,int> pt;

int n, a[N], dp[N][2][2];

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);
	cin >> n;
	int ans = 0;
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	for (int i = 0; i < n - 1; i++) for (int r = 0; r < 2; r++) for (int c = 0; c < 2; c++) dp[i][r][c] = -1e9;

	for (int i = 0; i < n; i++) dp[i][0][0] = 1;
	for (int i = 0; i < n - 1; i++) for (int r = 0; r < 2; r++) for (int c = 0; c < 2; c++) {
		if (dp[i][r][c] < 0) continue;
		int z = a[i];
		if (r == 1) z = a[i - 1] + 1;
		if (a[i + 1] > z) {
			dp[i + 1][0][c] = max(dp[i + 1][0][c], dp[i][r][c] + 1);
		}
		if (c == 0) {
			dp[i + 1][1][1] = max(dp[i + 1][1][1], dp[i][r][c] + 1);
		}
	}
	for (int i = 0; i < n; i++) for (int r = 0; r < 2; r++) for (int c = 0; c < 2; c++) {
		ans = max(ans, dp[i][r][c]);
		if (dp[i][0][0] < n) ans = max(ans, dp[i][0][0] + 1);
	}
	cout << ans << endl;
	return 0;

}