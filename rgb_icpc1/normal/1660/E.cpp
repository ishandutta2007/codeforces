#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long LL;
typedef pair<int, int> pii;

const int MX = 2005;
const int MOD = 1000000007;
char s[MX][MX];
int sum[MX * 2];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif

	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while (t --) {
		memset(sum, 0, sizeof sum);
		int n;
		cin >> n;
		for (int i = 0; i < n; i ++) {
			cin >> s[i];
		}
		int tot = 0;
		for (int i = 0; i < n; i ++) 
			for (int j = 0; j < n; j ++) {
				sum[(i - j + n) % n] += (s[i][j] == '1');
				tot += (s[i][j] == '1');
			}
		int rlt = INT_MAX;
		for (int i = 0; i < n; i ++)
			for (int j = 0; j < n; j ++) {
				rlt = min (rlt, n - sum[(i - j + n) % n] + tot - sum[(i - j + n) % n]);
			}
		cout << rlt << endl;
	}

	return 0;
}