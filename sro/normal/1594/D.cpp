#include <bits/stdc++.h>
using namespace std;
#define SZ(x) ((int)(x).size())
typedef long long ll;
const int Inf = 0x3f3f3f3f;

int N, M;
char tmp[11];
vector<pair<int, int> > nei[200005];
vector<int> nds;
int clr[200005];
int cc[2];

bool dfs(int now, int col) {
	clr[now] = col;
	++cc[col];
	nds.push_back(now);
	for (auto &it : nei[now]) {
		int to = it.first, nc = col ^ it.second;
		if (!~clr[to]) {
			if (!dfs(to, nc)) return 0;
		}
		else if (clr[to] != nc) return 0;
	}
	return 1;
}

void solve() {
	scanf("%d%d", &N, &M);
	for (int i = 1; i <= N; ++i) nei[i].clear();
	for (int i = 1; i <= M; ++i) {
		int x, y;
		scanf("%d%d %s", &x, &y, tmp);
		if (tmp[0] == 'i') nei[x].emplace_back(y, 1), nei[y].emplace_back(x, 1);
		else nei[x].emplace_back(y, 0), nei[y].emplace_back(x, 0);
	}
	for (int i = 1; i <= N; ++i) clr[i] = -1;
	int res = 0;
	for (int i = 1; i <= N; ++i) if (!~clr[i]) {
		int mx = -1;
		nds.clear();
		cc[0] = cc[1] = 0;
		if (dfs(i, 0)) mx = max(mx, cc[1]);
		for (int j : nds) clr[j] = -1;
		nds.clear();
		cc[0] = cc[1] = 0;
		if (dfs(i, 1)) mx = max(mx, cc[1]);
		if (!~mx) return puts("-1"), void();
		res += mx;
	}
	printf("%d\n", res);
}

int main() {
	int T; scanf("%d", &T);
	while (T--) solve();
	return 0;
}