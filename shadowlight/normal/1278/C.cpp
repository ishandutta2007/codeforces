#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

const int INF = 1e9 + 7;

void solve() {
	int n;
	cin >> n;
	vector <int> a(2 * n);
	for (int i = 0; i < 2 * n; i++) {
		cin >> a[i];
	}
	map <int, int> value;
	int red = 0, blue = 0;
	for (int i = n; i < 2 * n; i++) {
		if (a[i] == 1) {
			red++;
		} else {
			blue++;
		}
	}
	value[blue - red] = 0;
	for (int i = n; i < 2 * n; i++) {
		if (a[i] == 1) {
			red--;
		} else {
			blue--;
		}
		if (!value.count(blue - red)) {
			value[blue - red] = i - n + 1;
		}
	}
	for (int i = n - 1; i >= 0; i--) {
		if (a[i] == 1) {
			red++;
		} else {
			blue++;
		}
	}
	int res = (value.count(red - blue) ? value[red - blue] : INF);
	for (int i = n - 1; i >= 0; i--) {
		if (a[i] == 1) {
			red--;
		} else {
			blue--;
		}
		if (value.count(red - blue)) {
			res = min(res, (n - i) + value[red - blue]);
		}
	}
	cout << res << "\n";
}

int main(){
#ifdef LOCAL
	freopen("C_input.txt", "r", stdin);
	//freopen("C_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		solve();
	}

}