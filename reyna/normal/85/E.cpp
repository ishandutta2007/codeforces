//In the name of God
// Break through! I screamed forth from my soul!

#include <bits/stdc++.h>
using namespace std;

const int N = 5000 + 49;
const int mod = 1e9 + 7;

int dis[N][N], cnt = 0, mat[N][N], mark[N], n;
pair<int, int> p[N];

int pw(int a, int b) {
	return b? pw((a * 1LL * a) % mod, b >> 1) * 1LL * (b & 1? a: 1) % mod: 1;	
}

int dfs(int v, int col = 1) {
	if (mark[v] && mark[v] != col)
		return 0;
	if (mark[v])
		return 1;
	mark[v] = col;
	for (int u = 0; u < n; u++)
		if (mat[v][u] && u != v)
			if (!dfs(u, 3 - col))
				return 0;
	return 1;
}

bool check(int x) {
	memset(mark, 0, sizeof mark);
	cnt = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (dis[i][j] > x)
				mat[i][j] = 1;
			else
				mat[i][j] = 0;
	int res = 1;
	for (int v = 0; v < n; v++)
		if (!mark[v]) {
			res &= dfs(v), cnt++;
			if (!res)
				return 0;
		}
	return 1;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> p[i].first >> p[i].second;
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			dis[i][j] = abs(p[i].first - p[j].first) + abs(p[i].second - p[j].second);
	int l = -1, r = 1e4 + 9;
	while (l < r - 1) {
		int mid = l + r >> 1;
		if (check(mid))
			r = mid;
		else
			l = mid;	
	}
	check(r);
	cout << r << endl;
	cout << pw(2, cnt) << endl;
}