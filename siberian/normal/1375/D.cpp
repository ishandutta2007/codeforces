#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}
const int MAXN = 1e3 + 10;
int n;
int a[MAXN];

int cnt[MAXN];

int calcMex() {
	for (int i = 0; i <= n; i++) {
		cnt[i] = 0;
	}
	for (int i = 0; i < n; i++) {
		cnt[a[i]]++;
	}
	for (int i = 0; i <= n; i++) {
		if (cnt[i] == 0) {
			return i;
		}
	}
	assert(false);
	return -1;
}

bool check() {
	for (int i = 1; i < n; i++) {
		if (a[i] < a[i - 1]) {
			return false;
		}
	}
	return true;
}

void solve() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	vector<int> ans;
	//for (int it = 0; it < 2; it++) {
		//for (int i = 0; i < n; i++) {
		//	ans.push_back(i);
		//	a[i] = calcMex();
		//}
		/*cout << "a = " << endl;
		for (int i = 0; i < n; i++) {
			cout << a[i] << " ";
		}
		cout << endl;*/
	//}
	for (int i = 0; i < 2 * n; i++) {
		if (check()) break;
		int now = calcMex();
		int pos = now;
		if (pos == n) {
			for (int j = 0; j < n; j++) {
				if (a[j] != j) {
					pos = j;
					break;
				}
			}
			for (int j = 0; j < n; j++) {
				if (a[j] == pos) {
					pos = j;
					break;
				}
			}
		}
		ans.push_back(pos);
		a[pos] = now;
		/*cout << "a = " << endl;
		for (int i = 0; i < n; i++) {
			cout << a[i] << " ";
		}
		cout << endl;*/
	}

	assert(check());
	assert(ans.size() <= 2 * n);
	cout << ans.size() << "\n";
	for (auto i : ans) {
		cout << i + 1 << " ";
	}
	cout << endl;
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}