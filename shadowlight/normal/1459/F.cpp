#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

vector <pair <int, int>> counts;

vector <int> res;

void dfs(int v) {
	//cout << v << " " << counts[v].x << " " << counts[v].y << "\n";
	if (!counts[v].x && !counts[v].y) {
		res.pb(v);
		return;
	}
	while (counts[v].x + counts[v].y > 0) {
		if (counts[v].x) {
			--counts[v].x;
			--counts[v - 1].y;
			dfs(v - 1);
		} else {
			--counts[v].y;
			--counts[v + 1].x;
			dfs(v + 1);
		}
	}
	res.pb(v);
}

void solve() {
	string s;
	cin >> s;
	
	int n = s.size();
	int bal = n;

	counts.clear();
	counts.resize(2 * n + 1, {0, 0});
	for (int i = 0; i < n; ++i) {
		char c = s[i];
		if (c == '0') {
			++counts[bal].x;
			++counts[bal - 1].y;
			--bal;
		} else {
			++counts[bal].y;
			++counts[bal + 1].x;
			++bal;
		}
	}

	res.clear();
	dfs(n);

	reverse(all(res));
	for (int i = 1; i < (int) res.size(); ++i) {
		if (res[i] == res[i - 1] + 1) {
			cout << "1";
		} else {
			cout << "0";
		}
	}
	cout << "\n";
}

int main(){
#ifdef LOCAL
	freopen("D_input.txt", "r", stdin);
	//freopen("E_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	for (int i = 0; i < t; ++i) {
		solve();
	}

}