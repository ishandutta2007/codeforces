#include <bits/stdc++.h>

using namespace std;

int a[200005];
int b[200005];
int d[200005];
int p[200005];
vector<int> g[200005];

void solve() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i <= n; ++i) g[i].clear(), a[i] = b[i] = d[i] = p[i] = 0;
	int root = -1;
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &b[i]);
		if (b[i] != i) g[b[i]].push_back(i);
		else root = i;
	}
	for (int i = 0; i < n; ++i) scanf("%d", &p[i]);
	set<int> s;
	s.insert(root);
	for (int i = 0; i < n; ++i) {
		if (s.find(p[i]) == s.end()) {
			puts("-1");
			return;
		}
		a[p[i]] = i - d[b[p[i]]];
		d[p[i]] = i;
		s.erase(p[i]);
		for (int j: g[p[i]]) s.insert(j);
	}
	for (int i = 1; i <= n; ++i) printf("%d ", a[i]);
	puts("");
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	int t;
	scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}