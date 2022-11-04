#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long LL;
typedef pair<int, int> pii;

const int MX = 1000005;
const int MOD = 1000000007;
int a[MX];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif

	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while (t --) {
		int n;
		cin >> n;
		for (int i = 0; i < n; i ++) {
			cin >> a[i];
		}
		sort (a, a + n);
		int flg = 0;
		if (n == 1) {
			if (a[0] == 1) flg = 1;
			else flg = 0;
		}
		else {
			if (a[n - 1] <= a[n - 2] + 1) flg = 1;
			else flg = 0;
		}
		if (flg) cout << "YES" << endl;
		else cout << "NO" << endl;
	}

	return 0;
}