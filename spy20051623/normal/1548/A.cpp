#include <bits/stdc++.h>

using namespace std;

set<int> s[200005];
int fa[200005];

int main() {
//	freopen("in.txt", "r", stdin);
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i) {
		fa[i] = i;
		s[i].insert(i);
	}
	int ans = n;
	while (m--) {
		int a, b;
		scanf("%d%d", &a, &b);
		if (a > b)swap(a, b);
		s[a].insert(b);
		s[b].insert(a);
		if (fa[a] == a)--ans;
		fa[a] = b;
	}
	int q;
	scanf("%d", &q);
	while (q--) {
		int op, x, y;
		scanf("%d", &op);
		if (op == 1) {
			scanf("%d%d", &x, &y);
			if (x > y)swap(x, y);
			if (fa[x] == x)--ans;
			s[x].insert(y);
			s[y].insert(x);
			fa[x] = *s[x].rbegin();
		} else if (op == 2) {
			scanf("%d%d", &x, &y);
			if (x > y)swap(x, y);
			s[x].erase(y);
			s[y].erase(x);
			fa[x] = *s[x].rbegin();
			if (fa[x] == x)++ans;
		} else {
			printf("%d\n", ans);
		}
	}
	return 0;
}