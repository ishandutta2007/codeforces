#include <bits/stdc++.h>
using namespace std;
const int N = 100000 + 10;
int T, n, a[N], c[N], ans[N];
bool ok(int d) {
	priority_queue< pair<int,int> > q;
	for (int i = 1; i <= n; i ++) c[i] = 0;
	for (int i = 1; i <= n; i ++) c[a[i]] ++;
	for (int i = 1; i <= n; i ++) if (c[i]) q.push(make_pair(c[i], i));
	for (int i = 1; i <= n; i ++) {
		if (q.size() == 0) return 0;
		pair<int, int> now = q.top(); q.pop();
		// printf("now = %d %d\n", now.first, now.second);
		if (c[now.second] == 0) return 0;
		ans[i] = now.second; c[now.second] --;
		if (i - d >= 1) {
			q.push(make_pair(c[ans[i-d]], ans[i-d]));
		}
	}
	return 1;
}
int main() {
	scanf("%d", &T);
	while (T --) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i ++) {
			scanf("%d", &a[i]); 
		}
		// ok(3); return 0;
		int lef = 0, rig = n;
		while (rig - lef > 1) {
			int mid = (lef + rig) >> 1;
			if (ok(mid)) lef = mid; else rig = mid;
		}
		printf("%d\n", lef);
	}
}