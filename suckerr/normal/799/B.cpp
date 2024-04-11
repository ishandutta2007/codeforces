#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 7;

int n, visit[N], p[N];
set<pair<int, int> > ts[3];

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &p[i]);
	}
	for (int i = 0; i < n; i++) {
		int a; scanf("%d", &a);
		ts[--a].insert({p[i], i});
	}
	for (int i = 0; i < n; i++) {
		int b; scanf("%d", &b);
		ts[--b].insert({p[i], i});
	}
	int m;
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		int c, ans = -1;
		scanf("%d", &c); --c;
		while (true) {
			auto it = ts[c].begin();
			if (it == ts[c].end()) break;
			if (visit[it->second]) {
				ts[c].erase(it);
			} else {
				ans = it->first;
				visit[it->second] = true;
				ts[c].erase(it);
				break;
			}
		}
		printf("%d%c", ans, i + 1 == m ? '\n' : ' ');
	}
	return 0;
}