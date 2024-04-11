#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

struct Data {
	int turns;
	int i, j;
};

bool operator<(Data a, Data b) {
	return a.turns > b.turns;
}

const int INF = 1e9 + 7;

int main(){
#ifdef LOCAL
	freopen("D_input.txt", "r", stdin);
	//freopen("D_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	vector <int> a(n), b(n), c(m), d(m);
	for (int i = 0; i < n; ++i) {
		cin >> a[i] >> b[i];
	}
	for (int i = 0; i < m; ++i) {
		cin >> c[i] >> d[i];
	}

	vector <Data> bad;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (c[j] < a[i]) continue;
			bad.pb({c[j] - a[i], i, j});
		}
	}
	sort(all(bad));
	int mx = 0;
	if (!bad.size()) {
		cout << "0\n";
		return 0;
	}
	int res = INF;
	int it = 0;
	for (it = 0; it < bad.size(); ) {
		int now = bad[it].turns;
		res = min(res, mx + now + 1);
		while (it < (int) bad.size() && bad[it].turns == now) {
			mx = max(mx, d[bad[it].j] - b[bad[it].i] + 1);
			++it;
		}
	}
	res = min(res, mx);
	cout << res << "\n";
}