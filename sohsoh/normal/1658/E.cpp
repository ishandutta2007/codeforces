#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pll;

#define all(x)			(x).begin(),(x).end()
#define X			first
#define Y			second
#define sep			' '
#define endl			'\n'
#define debug(x)		cerr << #x << ": " <<  x << endl;

const ll MAXN = 2e3 + 10;

inline int dist(pll a, pll b) {
	return abs(a.X - b.X) + abs(a.Y - b.Y);
}

pll E[4];
bool ans[MAXN][MAXN];
int n, k;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> k;

	vector<pair<int, pll>> vec;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int x;
			cin >> x;
			vec.push_back({x, {i, j}});
		}
	}	

	sort(all(vec), greater<pair<int, pll>>());
	for (int i = 0; i < 4; i++) 
		E[i] = vec[0].Y;

	ans[E[0].X][E[0].Y] = true;
	for (int i = 1; i < n * n; i++) {
		pll e = vec[i].Y;
		bool flag = true;

		for (int j = 0; j < 4; j++)
			if (dist(E[j], e) > k)
				flag = false;

		if (flag) {
			ans[e.X][e.Y] = true;
			for (int mask = 0; mask < 4; mask++) {
				int xs = (mask & 1 ? -1 : 1), ys = (mask & 2 ? -1 : 1);
				if (e.X * xs + e.Y * ys < E[mask].X * xs + E[mask].Y * ys)
					E[mask] = e;
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			cout << (ans[i][j] ? 'M' : 'G');
		cout << endl;
	}
	return 0;
}