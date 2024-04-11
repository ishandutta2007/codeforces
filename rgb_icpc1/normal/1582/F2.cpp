#include <bits/stdc++.h>
using namespace std;
const int MX = 1000005;
const int MN = 8192;
const int inf = INT_MAX;
int a[MX];
int dp[2][MN];
int Tc;
vector<int> V[5005];
int res[MX], resn;
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
#endif

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	for(int i = 0 ; i < n ; i ++) {
		cin >> a[i];
		V[a[i]].push_back(i);
	}
	for(int i = 0 ; i < MN ; i ++) dp[0][i] = inf;
	dp[0][0] = -1;
	int k = 0;
	for(int i = 0 ; i <= 5000 ; i ++) {
		for(int j = 0 ; j < MN ; j ++) dp[1 - k][j] = dp[k][j];
		for(int j = 0 ; j < MN ; j ++) {
			if(dp[k][j ^ i] < inf) {
				int pos = lower_bound(V[i].begin() , V[i].end() , dp[k][j ^ i]) - V[i].begin();
				if(pos == V[i].size()) continue;
				//cerr << (j ^ i) << ' ' << j << ' ' << i << endl;
				dp[1 - k][j] = min(dp[1 - k][j], V[i][pos]);
			}
		}
		k = 1 - k;
	}
	resn = 0;
	for(int i = 0 ; i < MN ; i ++) if(dp[k][i] < inf) res[resn ++] = i;
	cout << resn << endl;
	for(int i = 0 ; i < resn ; i ++) cout << res[i] << " \n"[i == resn - 1];
	return 0;

}