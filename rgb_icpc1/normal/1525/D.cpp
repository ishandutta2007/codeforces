#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = a; i < b; i ++)
using namespace std;
const int mx = 100005;
#define endl '\n'
typedef long long LL;
typedef pair<int, int> pii;

vector<int> V0;
vector<int> V1;
const int MX = 5005;
int a[MX];
const int INF = 1000000006;
int dp[MX][MX];

int main() {

#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
#endif

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] == 1) V1.push_back(i);
		else V0.push_back(i);
	}
//	if (V1.size() == 0) {
//		cout << 0 << endl;
//		return 0;
//	}
	fill(dp[0], dp[0] + MX * MX, INF);
	dp[0][0] = 0;
	for (int i = 0; i <= V1.size(); i++) {
		for (int j = 0; j < V0.size(); j++) {
			dp[i][j + 1] = min(dp[i][j + 1], dp[i][j]);
			if (i != V1.size()) dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j] + abs(V1[i] - V0[j]));
		}
	}
	int sz1 = V1.size(), sz0 = V0.size();
	cout << dp[sz1][sz0] << endl;
	
	return 0;
	
}