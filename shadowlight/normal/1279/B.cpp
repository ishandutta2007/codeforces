#include <bits/stdc++.h>
#define int long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

void solve() {
	int n, s;
	cin >> n >> s;
	vector <int> a(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (i) {
			a[i] += a[i - 1];
		}
	}
	if (s >= a.back()) {
		cout << "0\n";
		return;
	}
	int res = 0, part = 1;
	for (int i = 0; i < n; i++) {
		int tm = (a[i] - (i ? a[i - 1] : 0));
		if (a[i] - tm > s) {
			break;
		}
		int pos = upper_bound(a.begin(), a.end(), s + tm) - a.begin() - 1;
		if (pos > res) {
			res = pos;
			part = i + 1;
		}
	}
	cout << part << "\n";
}

signed main(){
#ifdef LOCAL
	freopen("B_input.txt", "r", stdin);
	//freopen("B_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		solve();
	}

}