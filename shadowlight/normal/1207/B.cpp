#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

int main(){
#ifdef LOCAL
	freopen("B_input.txt", "r", stdin);
	//freopen("B_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector <vector <int> > a(n, vector <int> (m, 0));
	auto b = a;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}
	vector <pair <int, int> > res;
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < m - 1; j++) {
			if (a[i][j] && a[i + 1][j] && a[i][j + 1] && a[i + 1][j + 1]) {
				b[i][j] = 1;
				b[i + 1][j] = 1;
				b[i][j + 1] = 1;
				b[i + 1][j + 1] = 1;
				res.push_back({i, j});
			}
		}
	}
	if (a != b) {
		cout << "-1\n";
		return 0;
	}
	cout << res.size() << "\n";
	for (auto t : res) {
		cout << t.first + 1 << " " << t.second + 1 << "\n";
	}
}