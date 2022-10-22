#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

int n;

void add(int &x, int t) {
	x += t;
	if (x == n) {
		x = 0;
	}
	if (x == -1) {
		x = n - 1;
	}
}

void solve() {
	vector <int> p = {0, 1, 2};
	vector <int> adds(3, 0);

	int R;
	cin >> n >> R;
	vector <vector <int>> a(n, vector<int>(n, 0));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> a[i][j];
			--a[i][j];
		}
	}

	string s;
	cin >> s;
	for (char c : s) {
		if (c == 'D') {
			add(adds[p[0]], 1);
		} else if (c == 'U') {
			add(adds[p[0]], -1);
		} else if (c == 'R') {
			add(adds[p[1]], 1);
		} else if (c == 'L') {
			add(adds[p[1]], -1);
		} else if (c == 'C') {
			swap(p[0], p[2]);
		} else if (c == 'I') {
			swap(p[1], p[2]);
		} else {
			assert(false);
		}
	}

	//cout << "P: " << p[0] << " " << p[1] << " " << p[2] << "\n";

	vector <vector <int>> res(n, vector<int>(n, -1));

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			vector <int> t = {i, j, a[i][j]};
			for (int d = 0; d < 3; ++d) {
				t[d] = (t[d] + adds[d]) % n;
			}
			vector <int> tt(3);
			for (int d = 0; d < 3; ++d) {
				tt[d] = t[p[d]];
			}

			res[tt[0]][tt[1]] = tt[2];
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			assert(res[i][j] != -1);
			cout << res[i][j] + 1 << " ";
		}
		cout << "\n";
	}
	cout << "\n";
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