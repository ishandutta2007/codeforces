#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int INF = 1e9 + 7;
const int LOGN = 30;

int main() {
	//freopen("E.in", "r", stdin);
	//freopen("E.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	vector <pair <int, int> > a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i].first >> a[i].second;
	}
	int mx = 0;
	sort(a.begin(), a.end());
	vector <pair <int, int> > b;
	for (int i = 0; i < n; i++) {
		if (a[i].second <= mx) {
			continue;
		}
		while (b.size() && b.back().first == a[i].first) b.pop_back();
		mx = a[i].second;
		b.push_back(a[i]);
	}
	a = b;
	n = a.size();
	vector <int> nxt(n, -1);
	for (int i = 0; i < n; i++) {
		int pos = upper_bound(a.begin(), a.end(), make_pair(a[i].second, INF)) - a.begin();
		nxt[i] = pos - 1;
	}
	vector <vector <int> > binup(n, vector <int> (LOGN, -1));
	for (int i = n - 1; i >= 0; i--) {
		binup[i][0] = nxt[i];
		for (int j = 1; j < LOGN; j++) {
			binup[i][j] = binup[binup[i][j - 1]][j - 1];
		}
	}
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		int pos = upper_bound(a.begin(), a.end(), make_pair(x, INF)) - a.begin() - 1;
		if (pos == -1) {
			cout << "-1\n";
			continue;
		}
		if (a[pos].second >= y) {
			cout << "1\n";
			continue;
		}
		if (a[binup[pos][LOGN - 1]].second < y) {
			cout << "-1\n";
			continue;
		}
		int res = 0, now = pos;
		for (int i = LOGN - 1; i >= 0; i--) {
			if (a[binup[now][i]].second < y) {
				res += (1 << i);
				now = binup[now][i];
			}
		}
		cout << res + 2 << "\n";
	}
}