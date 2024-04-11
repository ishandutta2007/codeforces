#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
typedef pair<int, int> ii;
vector<int> adjlist[200];
int bip[200];
bool dfs(int v, int p) {
	for (int i: adjlist[v]) {
		if (i == p) continue;
		if (bip[i] == -1) {
			bip[i] = 1 - bip[v];
			if (!dfs(i, v)) return false;
		} else if (bip[i] == bip[v]) return false;
	}
	return true;
}
struct UFDS {
	vector<ii> parent;
	vector<int> rankof;
	UFDS(int N) {
		for (int i = 0; i < N; ++i) parent.push_back(ii(i, 0)), rankof.push_back(0);
	}
	ii find_parent(int i) {
		if (parent[i].first == i) return parent[i];
		ii x = find_parent(parent[i].first);
		return ii(x.first, x.second + parent[i].second);
	}
	void union_set(int p, int q, int w) {
		ii pp = find_parent(p), qq = find_parent(q);
		if (pp.first == qq.first) return;
		if (rankof[pp.first] == rankof[qq.first]) ++rankof[pp.first];
		if (rankof[pp.first] > rankof[qq.first]) parent[qq.first] = ii(pp.first, w + pp.second - qq.second);
		else parent[pp.first] = ii(qq.first, qq.second - w - pp.second);
	}
};
int main() {
	int n, m, x, y, b;
	scanf("%d %d", &n, &m);
	vector<ii> zedge, oedge;
	fill_n(bip, n, -1);
	for (int i = 0; i < m; ++i) {
		scanf("%d %d %d", &x, &y, &b);
		--x, --y;
		if (b) oedge.push_back(ii(x, y));
		else zedge.push_back(ii(x, y));
		adjlist[x].push_back(y);
		adjlist[y].push_back(x);
	}
	bip[0] = 0;
	if (!dfs(0, -1)) {
		printf("NO");
		return 0;
	}
	UFDS sets(n);
	for (ii i: oedge) {
		ii pp = sets.find_parent(i.first), qq = sets.find_parent(i.second);
		if (pp.first == qq.first && pp.second - qq.second != 1) {
			printf("NO");
			return 0;
		} else if (pp.first != qq.first) sets.union_set(i.second, i.first, 1);
	}
	int adjmat[n][n];
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (i == j) adjmat[i][j] = 0;
			else adjmat[i][j] = 1000000000;
		}
	}
	for (int i = 0; i < n; ++i) {
		ii pp = sets.find_parent(i);
		adjmat[pp.first][i] = min(adjmat[pp.first][i], -pp.second);
		adjmat[i][pp.first] = min(adjmat[i][pp.first], pp.second);
	}
	for (ii i: zedge) {
		ii pp = sets.find_parent(i.first), qq = sets.find_parent(i.second);
		if (pp.first == qq.first && abs(pp.second - qq.second) != 1) {
			printf("NO");
			return 0;
		} else if (pp.first != qq.first) adjmat[i.first][i.second] = adjmat[i.second][i.first] = 1;
	}
	for (int k = 0; k < n; ++k) {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) adjmat[i][j] = min(adjmat[i][j], adjmat[i][k] + adjmat[k][j]);
		}
	}
	int ptr, mx = -1;
	for (int i = 0; i < n; ++i) {
		int tm = *max_element(adjmat[i], adjmat[i] + n);
		if (*min_element(adjmat[i], adjmat[i] + n) < 0) continue;
		if (tm > mx) mx = tm, ptr = i;
	}
	if (mx < 0) {
	    printf("NO\n");
	    return 0;
	}
	printf("YES\n");
	printf("%d\n", mx);
	for (int i = 0; i < n; ++i) printf("%d ", adjmat[ptr][i]);
}