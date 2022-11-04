#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long LL;
typedef pair<int, int> pii;

const int MX = 1000005;
const int MOD = 1000000007;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif

	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int tc; cin >> tc;
	while (tc --) {
		int n; cin >> n;
		if (n == 3) cout << -1 << endl;
		else {
			cout << n << ' ' << n - 1 << ' ';
			n -= 2;
			for (int i = 1; i <= n; i ++) cout << i << ' ';
			cout << endl;
		}
	}

	return 0;
}