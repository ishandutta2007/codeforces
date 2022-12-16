#include <bits/stdc++.h>

using namespace std;

typedef pair <int, int> pii;

bool check(int i, int j) {
	if (i >= 0 && i < 8 && j >= 0 && j < 8)
		return true;
	return false;
}

const int maxn = 1e2, maxm = 5e3;
bitset <maxn> mark[maxn], mark2[maxn];
pii p[maxm], par[maxn][maxn];
int n, h[maxn][maxn], answer;
pair <pii, pii> ans[maxm];
queue <pii> bfs;
char c1, c2;

void go(pii p1, pii p2) { 
	cout << char(p1.first + 'a') << char(p1.second + '1') << '-';
	cout << char(p2.first + 'a') << char(p2.second + '1') << '\n';
	return;
}

void rep(pii root, pii v) {
	if (v == root)
		return;
	pii u = par[v.first][v.second];
	if (mark2[u.first][u.second]) {
		rep(root, u);
		ans[answer++] = {v, u};
		return;
	}
	ans[answer++] = {v, u};
	rep(root, u);
	return;
}

int main(){
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> c1 >> c2;
		p[i] = {c1 - 'a', c2 - '1'};
		mark[p[i].first][p[i].second] = true;
	}
	for (int i = 0, num = 0; i < 8; ++i)
		for (int j = 0; j < 8 && num < n; ++j, ++num) {
			if (mark[j][i]) {
				mark[j][i] = false;
				mark2[j][i] = true;
				continue;
			}
			memset(h, 63, sizeof(h));
			bfs.push({j, i});
			h[j][i] = 0;
			while (!bfs.empty()) {
				pii pos = bfs.front();
				bfs.pop();
				int i = pos.first, j = pos.second;
				for (int d1 = -2; d1 <= 2; ++d1)
					for (int d2 = -2; d2 <= 2; ++d2)
						if (min(abs(d1), abs(d2)) == 1 && max(abs(d1), abs(d2)) == 2 && check(i + d1, j + d2) && h[i + d1][j + d2] > h[i][j] +1) {
							h[i + d1][j + d2] = h[i][j] + 1;
							par[i + d1][j + d2] = {i, j};
							bfs.push({i + d1, j + d2});
						}
			}
			pair <int, pii> mn = {100, {0, 0}};
			for (int d = 0; d < 8; ++d)
				for (int d2 = 0; d2 < 8; ++ d2)
					if (mark[d][d2])
						mn = min(mn, {h[d][d2], {d, d2}});
			int x = mn.second.first, y = mn.second.second;
			mark[x][y] = false;
			rep({j, i}, {x, y});
			mark2[j][i] = true;
		}
	cout << answer << '\n';
	for (int i = 0; i < answer; ++i)
		go(ans[i].first, ans[i].second);
	return 0;
}