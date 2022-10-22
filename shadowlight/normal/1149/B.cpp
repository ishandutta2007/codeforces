#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int Q = 31;
const int MAXN = 257;
const int INF = 1e9 + 7;

string a[3];

int dp[MAXN][MAXN][MAXN];

string s;
vector <vector <int> > pos(Q);

vector <vector <int> > nxt;

void recalc(int x, int y, int z) {
	if (x > a[0].size() || y > a[1].size() || z > a[2].size()) {
		dp[x][y][z] = INF;
		return;
	}
	if (!x && !y && !z) {
		dp[x][y][z] = -1;
		return;
	}
	dp[x][y][z] = INF;
	vector <int> cf = {x, y, z};
	for (int i = 0; i < 3; i++) {
		if (!cf[i]) continue;
		cf[i]--;
		int last = dp[cf[0]][cf[1]][cf[2]];
		int c = a[i][cf[i]] - 'a';
		if (last < (int) s.size() - 1) {
			dp[x][y][z] = min(dp[x][y][z], nxt[c][last + 1]);
		}
		cf[i]++;
	}
}

int main() {
	//freopen("B.in", "r", stdin);
	//freopen("B.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	for (int i = 0; i < MAXN; i++) {
		for (int j = 0; j < MAXN; j++) {
			for (int k = 0; k < MAXN; k++) {
				dp[i][j][k] = INF;
			}
		}
	}
	dp[0][0][0] = -1;
	int n, q;
	cin >> n >> q;
	nxt.resize(Q, vector <int> (n, 0));
	cin >> s;
	for (int i = 0; i < n; i++) {
		int k = s[i] - 'a';
		pos[k].push_back(i);
	}
	for (int i = 0; i < Q; i++) {
		int it = 0;
		for (int j = 0; j < n; j++) {
			nxt[i][j] = (it == pos[i].size() ? INF : pos[i][it]);
			if (it < pos[i].size() && j == pos[i][it]) it++;
		}
	}
	for (int i = 0; i < q; i++) {
		char op;
		int v;
		cin >> op >> v;
		v--;
		if (op == '+') {
			char c;
			cin >> c;
			a[v] += c;
			for (int i = 0; i < MAXN; i++) {
				for (int j = 0; j < MAXN; j++) {
					if (!v) {
						recalc(a[0].size(), i, j);
					} else if (v == 1) {
						recalc(i, a[1].size(), j);
					} else {
						recalc(i, j, a[2].size());
					}
				}
			}
		} else {
			for (int i = 0; i < MAXN; i++) {
				for (int j = 0; j < MAXN; j++) {
					if (!v) {
						recalc(a[0].size(), i, j);
					} else if (v == 1) {
						recalc(i, a[1].size(), j);
					} else {
						recalc(i, j, a[2].size());
					}
				}
			}
			a[v].pop_back();
		}
		int x = a[0].size(), y = a[1].size(), z = a[2].size();
		//cout << dp[x][y][z] << "\n";
		cout << (dp[x][y][z] == INF ? "NO" : "YES") << "\n";
	}
}