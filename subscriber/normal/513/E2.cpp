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

int n, k;
int a[N];
long long s[N];
long long dp[205][33000][2];
long long le[N][3][3], be[N][3];

int ff(int x) {
	if (x == 2) return 0;


	if (x == 0) return -1; 

	return 1;
}

int inv(int x) {
	if (x == 2) return 2;
	return 1 - x;
}

int main(){
//	freopen(TASK".in","r",stdin);	
//	freopen(TASK".out","w",stdout);
	cin >> n >> k;
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);

	for (int i = 0; i < n; i++) s[i + 1] = s[i] + a[i];
	
	for (int i = 0; i <= k; i++) for (int j = 0; j < n; j++) for (int jj = 0; jj < 2; jj++) dp[i][j][jj] = -1e18;

	long long ans = -1e18;

	for (int g = 0; g < k; g++) {
		for (int i = 0; i < n; i++) for (int j = 0; j < 2; j++) be[i][j] = dp[g][i][j];

		for (int i = 1; i < n; i++) for (int j = 0; j < 2; j++) be[i][j] = max(be[i][j], be[i - 1][j]);

		for (int i = 0; i < n; i++) for (int j = 0; j < 3; j++) for (int jj = 0; jj < 3; jj++) le[i][j][jj] = -1e18;

		for (int i = 0; i < n; i++) for (int j = 0; j < 3; j++) for (int jj = 0; jj < 3; jj++) {
			long long ss = ff(inv(j)) * s[i] + ff(inv(jj)) * s[i];


			if (j != 2) {
				if (i == 0) ss = -1e18; else
				ss += be[i - 1][inv(j)];
			}				
			le[i][j][jj] = ss;	

		}
		for (int i = 1; i < n; i++) for (int j = 0; j < 3; j++) for (int jj = 0; jj < 3; jj++) le[i][j][jj] = max(le[i][j][jj], le[i - 1][j][jj]);

		for (int i = 0; i < n; i++) for (int j = 0; j < 3; j++) for (int jj = 0; jj < 3; jj++) {
			if (g == 0 && j != 2) continue;
			if (g == k - 1 && jj != 2) continue;
			if (g != 0 && j == 2) continue;
			if (g != k - 1 && jj == 2) continue;


			long long ss = ff(j) * s[i + 1] + ff(jj) * s[i + 1];

			ss += le[i][j][jj];

			if (g == k - 1) {
				ans = max(ans, ss);
			} else {
				dp[g + 1][i][jj] = max(dp[g + 1][i][jj], ss);
			}
		}
	}
	cout << ans << endl;
	return 0;
}