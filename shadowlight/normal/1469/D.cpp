#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

void solve() {
	int n;
	cin >> n;

	vector <pair <int, int>> res;
	vector <int> vals(n - 1, 0);
	iota(all(vals), 1);

	int y = n;
	int pp = n;

	while (y > 2) {
		int x = sqrt(y);
		if (x * x < y) {
			++x;
		}
		while (vals.back() > x) {
			res.pb({vals.back(), pp});
			vals.pop_back();
		}
		res.pb({pp, x});
		res.pb({pp, x});
		vals.pop_back();
		pp = x;
		y = x;
	}
	assert(res.size() <= n + 5);
	cout << res.size() << "\n";
	for (auto [x, y] : res) {
		cout << x << " " << y << "\n";
	}
}

int main(){
#ifdef LOCAL
	freopen("D_input.txt", "r", stdin);
	//freopen("D_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	for (int i = 0; i < t; ++i) {
		solve();
	}

}