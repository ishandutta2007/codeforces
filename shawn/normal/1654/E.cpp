#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1e5 + 10;
const int sq = 100;

int a[N], ans, n;

int main() {
	cin.tie(0)->ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <= n; i ++) cin >> a[i];
	for (int i = -sq; i <= sq; i ++) {
		map<int, int> cnt;
		for (int j = 1; j <= n; j ++) {
			ans = max(ans, ++ cnt[a[j] - i * j]);
		}
	}
	for (int i = 1; i <= n; i ++) {
		map<int, int> cnt;
		for (int j = i + 1; j <= n && j <= i + 100000 / sq; j ++) {
			if ((a[j] - a[i]) % (j - i) == 0) {
				ans = max(ans, ++ cnt[(a[j] - a[i]) / (j - i)] + 1);
			} 
		}
	}
	cout << n - ans;
	return 0;	
}