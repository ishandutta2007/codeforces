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
	vector <vector <int>> a(n, vector<int> (n, 0));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			char c;
			cin >> c;
			a[i][j] = (c == '1');
		}
	}

	vector <int> xs = {0, 1, n - 1, n - 2};
	vector <int> ys = {1, 0, n - 2, n - 1};

	int cnt = 0;
	for (int i = 0; i < 4; ++i) {
		cnt += (a[xs[i]][ys[i]] == (i >= 2));
	}
	bool inv = (cnt < 2);

	vector <pair <int, int>> res;

	for (int i = 0; i < 4; ++i) {
		if (inv == (a[xs[i]][ys[i]] == (i >= 2))) {
			res.pb({xs[i], ys[i]});
		}
	}

	cout << res.size() << "\n";
	for (auto t : res) {
		cout << t.x + 1 << " " << t.y + 1 << "\n";
	}

}

int main(){
#ifdef LOCAL
	freopen("B_input.txt", "r", stdin);
	//freopen("B_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		solve();
	}

}