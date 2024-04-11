#include <bits/stdc++.h>
using namespace std;

const int N = 2e5L + 11;

int p[N], a[N], b[N];

int main() {
	int n; cin >> n;
	for(int i = 0; i < n; i ++) scanf("%d", p + i);
	for(int i = 0; i < n; i ++) scanf("%d", a + i);
	for(int i = 0; i < n; i ++) scanf("%d", b + i);
	
	set <pair <int, int>> st[4];
	for(int i = 0; i < n; i ++) {
		st[a[i]].insert({p[i], i});
		st[b[i]].insert({p[i], i});
	}
	
	int m; cin >> m;
	while(m --) {
		int c; scanf("%d", &c);
		if(st[c].size()) {
			printf("%d\n", st[c].begin() -> first);
			int i = st[c].begin() -> second;
			st[a[i]].erase({p[i], i});
			st[b[i]].erase({p[i], i});
		} else
			puts("-1");
	}
}