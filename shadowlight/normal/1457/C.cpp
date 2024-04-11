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
	int n, p, k;
	cin >> n >> p >> k;
	vector <int> a(n);

	for (int i = 0; i < n; ++i) {
		char c;
		cin >> c;
		a[i] = (c == '1');
	}

	int x, y;
	cin >> x >> y;

	vector <int> res(n, 0);
	for (int i = n - 1; i >= 0; --i) {
		if (i + k < n) {
			res[i] += res[i + k];
		}
		if (!a[i]) {
			res[i] += x;
		}
	}

	int ans = INF;

	for (int i = p - 1; i < n; ++i) {
		ans = min(ans, y * (i - p + 1) + res[i]);
	}
	cout << ans << "\n";
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
	for (int i = 0; i < t; ++i) {
		solve();
	}

}