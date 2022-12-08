#include <bits/stdc++.h>

using namespace std;

int con[200005];
int root[200005];
int k[200005];

vector<int> edge[200005];

void solve() {
	int n;
	scanf("%d", &n);
	memset(con, 0, sizeof con);
	memset(root, 0, sizeof root);
	memset(k, 0, sizeof k);
	int x, y;
	for (int i = 1; i <= n; ++i) {
		scanf("%d%d", &x, &y);
		edge[x].push_back(y);
		edge[y].push_back(x);
		++con[x];
		++con[y];
	}
	queue<int> q;
	int p;
	for (int i = 1; i <= n; ++i) {
		if (con[i] == 1)
			q.push(i);
	}
	while (!q.empty()) {
		p = q.front();
		q.pop();
		--con[p];
		for (int v : edge[p]) {
			if (con[v]) {
				--con[v];
				if (con[v] == 1)
					q.push(v);
			}
		}
	}
	for (int i = 1; i <= n; ++i) {
		if (con[i]) {
			q.push(i);
			while (!q.empty()) {
				p = q.front();
				q.pop();
				root[p] = i;
				++k[i];
				for (int v : edge[p]) {
					if (!root[v] && !con[v])
						q.push(v);
				}
			}
		}
	}
	long long sum = 0;
	for (int i = 1; i <= n; ++i) {
		sum += 2 * (n - k[root[i]]) + k[root[i]] - 1;
	}
	sum >>= 1;
	printf("%lld\n", sum);
	for (int i = 1; i <= n; ++i) {
		edge[i].clear();
	}
}

int main() {
//	freopen("in.txt", "r", stdin);
	int t;
	scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}