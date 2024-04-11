#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}
#define int ll

int get(int x){
	int ans = 0;
	while (x) {
		if (x % 10) return ans;
		ans ++;
		x /= 10;
	}
	return ans;
}

void solve() {
	int n, k;
	cin >> n >> k;
	int ans = n * pow(10, k);
	for (int i = 0; i <= k; i++) {
		for (int j = 0; j <= k; j++) {
			int fans = n * pow(2, i) * pow(5, j);
			//cout << fans << endl;
			if (get(fans) >= k) chkmin(ans, fans);
		}
	}
	cout << ans;
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	//cin >> t;
	t = 1;
	while (t--)
		solve();
	return 0;
}