#include <bits/stdc++.h>
using namespace std;

#define N 1010

int n;

vector <pair <int, int> > v[N];

int dfs(int x, int y) {
	int rlt = 0;
	for (int i = 0; i < v[x].size(); i ++) {
		int z = v[x][i].first;
		int w = v[x][i].second;
		if (z == y) continue;
		rlt = max(rlt, w + dfs(z, x));
	}
	return rlt;
}

int main() {
	//freopen("r.in", "r", stdin);
	scanf("%d", &n);
	for (int i = 1, x, y, z; i < n; i ++) {
		scanf("%d %d %d", &x, &y, &z);
		v[x].push_back(make_pair(y, z));
		v[y].push_back(make_pair(x, z));
	}
	printf("%d\n", dfs(0, -1));

	return 0;
}