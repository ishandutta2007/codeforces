#include <bits/stdc++.h>

using namespace std;
const int N = 1005;
int fa[N], num[N];

int find(int x) {
	return fa[x] == x ? x : fa[x] = find(fa[x]);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i) {
		fa[i] = i;
		num[i] = 1;
	}
	int t = 1;
	while (m--) {
		int x, y;
		scanf("%d%d", &x, &y);
		if (find(x) == find(y)) ++t;
		else num[find(x)] += num[find(y)], fa[find(y)] = find(x);
		vector<int> v;
		for (int i = 1; i <= n; ++i) {
			if (fa[i] == i) v.push_back(num[i]);
		}
		sort(v.begin(), v.end(), greater<int>());
		int ans = 0;
		for (int i = 0; i < min(t, (int) v.size()); ++i) {
			ans += v[i];
		}
		printf("%d\n", ans - 1);
	}
	return 0;
}