#include <bits/stdc++.h>
using namespace std;

#define N 300030

int n, q, type, x, from[N], id[N];
bool vis[N];

vector <int> v[N];

int main() {
	int e = 0, last = 0, ans = 0;
	scanf("%d %d", &n, &q);
	for (int i = 1; i <= q; i ++) {
		scanf("%d %d", &type, &x);
		if (type == 1) {
			vis[i] = 1;
			id[++e] = i;
			v[x].push_back(i);
			ans ++;
		}
		else if (type == 2) {
			for (int j = from[x], sz = v[x].size(); j < sz; j ++) ans -= vis[v[x][j]], vis[v[x][j]] = 0;
			from[x] = v[x].size();
		}
		else {
			for (int j = last + 1; j <= id[x]; j ++) if (vis[j]) vis[j] = 0, ans --;
			last = max(last, id[x]);
		}
		printf("%d\n", ans);
	}
	return 0;
}