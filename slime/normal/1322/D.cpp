#include <bits/stdc++.h>
#define ll long long
#define maxn 5005 /*rem*/
#define db double
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define pi pair<int, int>
#define fi first
#define se second
using namespace std;
int agr[maxn];
int co[maxn];
int pro[maxn];
int dp[3005][maxn];
int mx[maxn][maxn];
const int inf = 2e9;
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> agr[i];
	for (int i = 1; i <= n; i++) 
		cin >> co[i];
	for (int i = 1; i <= n + m; i++)
		cin >> pro[i];
	for (int i = 0; i < maxn; i++)
		for (int j = 0; j < maxn; j++)
			mx[i][j] = -inf; //   
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			dp[i][j] = -inf;
			int cur = j;
			ll sm = 0;
			for (int k = agr[i]; 1; k++) {
				ll nans = mx[k][cur + 1] + sm;
				if (nans > dp[i][j]) dp[i][j] = nans;
				if (!cur) {
					if (sm > dp[i][j]) dp[i][j] = sm;
					break;
				}
				sm += (cur / 2) * pro[k + 1];
				cur /= 2;
			}
			dp[i][j] -= co[i];
			dp[i][j] += pro[agr[i]];
			mx[agr[i]][j] = max(mx[agr[i]][j], dp[i][j]);
			if (j == 1)
				for (int s = 1; s < agr[i]; s++)
					mx[s][1] = max(mx[s][1], dp[i][j]);
		}
	int ans = 0;
	for (int i = 1; i <= n; i++) 
		ans = max(ans, dp[i][1]);
	cout << ans << endl;
	return 0;
}