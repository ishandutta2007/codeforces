#include <bits/stdc++.h>
using namespace std;

#define N 500100

int n, m, rt[N];
bool del[N];
const int mod = 1e9 + 7;

int find_rt(int u) {
	return rt[u] == u ? u : rt[u] = find_rt(rt[u]);
}

vector <int> vec[N];

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= m; i ++) rt[i] = i, del[i] = 0, vec[i].assign(1, i);
	vector <int> ans;
	for (int i = 1; i <= n; i ++) {
		int k, x, y;
		scanf("%d", &k);
		if (k == 1) scanf("%d", &x);
		else {
			scanf("%d %d", &x, &y);
			if (del[x]) k --, swap(x, y);
			else if (del[y]) k --;
		}
		if (k == 1) {
			if (!del[x]) {
				x = find_rt(x);
				for (auto y : vec[x]) del[y] = 1;
				ans.push_back(i);
			}
			continue;
		}
		x = find_rt(x), y = find_rt(y);
		if (x == y) continue;
		if (vec[x].size() < vec[y].size()) swap(x, y);
		for (auto z : vec[y]) vec[x].push_back(z); vec[y].clear();
		rt[y] = x;
		ans.push_back(i);
	}
	int sz = ans.size(), pw = 1;
	for (int i = 0; i < sz; i ++) pw = 2 * pw % mod;
	printf("%d %d\n", pw, sz);
	for (auto x : ans) printf("%d ", x); puts("");

    return 0;
}