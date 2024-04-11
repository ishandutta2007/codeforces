#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(a) (a).begin(),(a).end()

template<typename T1, typename T2> inline void chkmin(T1 & x, const T2 & y) {if (y < x) x = y;}
template<typename T1, typename T2> inline void chkmax(T1 & x, const T2 & y) {if (x < y) x = y;}

void solve() {
	int n;
	string a, b;
	cin >> n;
	cin >> a >> b;
	vector<vector<int>> cnt(20, vector<int> (20, 0));
	for (int i = 0; i < n; i++) {
		if (a[i] > b[i]) {
			cout << -1 << "\n";
			return;
		} else if (a[i] == b[i]) {
			continue;
		} else {
			cnt[a[i] - 'a'][b[i] - 'a'] = 1;
		}
	}

	/*cout << "cnt = " << endl;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << cnt[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;*/
	int ans = 0;
	for (int a = 0; a < 20; a++) {
		int mnPos = 20;
		for (int b = a + 1; b < 20; b++) {
			if (cnt[a][b]) {
				mnPos = b;
				break;
			}
		}
		if (mnPos == 20) continue;
		ans++;
		//cout << mnPos << endl;
		for (int b = mnPos + 1; b < 20; b++) {
			cnt[mnPos][b] += cnt[a][b];
			cnt[a][b] = 0;
		}
	}
	cout << ans << "\n";
}

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(20), cout.setf(ios::fixed);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}