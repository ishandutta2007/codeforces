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

int n, s, l;
int a[N];
int gg[N], f1[22][N], f2[22][N];
int dp[N];
int q[N];

int dif(int x, int y) {
	int w = gg[y - x + 1];

	int q1 = min(f1[w][x], f1[w][y - pw(w) + 1]);
	int q2 = max(f2[w][x], f2[w][y - pw(w) + 1]);

	return q2 - q1;
}

int main(){
//	freopen(TASK".in","r",stdin);	
//	freopen(TASK".out","w",stdout);
	cin >> n >> s >> l;
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);

	gg[1] = 0;
	for (int i = 2; i <= n; i++) gg[i] = gg[i / 2] + 1;

	for (int i = 0; i < n; i++) f1[0][i] = f2[0][i] = a[i];

	for (int i = 1; i <= gg[n]; i++) for (int j = 0; j < n; j++) if (j + pw(i) <= n) {
		f1[i][j] = min(f1[i - 1][j], f1[i - 1][j + pw(i - 1)]);
		f2[i][j] = max(f2[i - 1][j], f2[i - 1][j + pw(i - 1)]);
	}
	for (int i = 0; i <= n; i++) dp[i] = 1e9;
	dp[0] = 0;

	int u = 0;

	int q1 = 0, q2 = 0;
	for (int i = 0; i < n; i++) {
		while (dif(u, i) > s) {
			if (q1 > q2 && q[q2] == u) {
				q2++;
			}
			u++;
		}

		int add = i + 1 - l;

		if (add >= u) {
			while (q1 > q2 && dp[q[q1 - 1]] >= dp[add]) q1--;
			q[q1++] = add;
		}

		if (q1 > q2) {
			dp[i + 1] = dp[q[q2]] + 1;
		} else dp[i + 1] = 1e9;
	}
//	for (int i = 0; i <= n; i++) cout << dp[i] << " ";
//	cout << endl;
	if (dp[n] > 1e8) puts("-1"); else cout << dp[n] << endl;



	return 0;
}