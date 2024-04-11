#include <bits/stdc++.h>
using namespace std;
const int N = 502;
int t, n, a[N], b[N];
vector<int> ans;
void op(int i) {
	ans.push_back(i);
	int tmp = a[i + 2];
	a[i+2] = a[i+1], a[i+1] = a[i]; a[i] = tmp;
}
void solve(int l, int r) {
	int mn = 1000000;
	for (int i = l; i <= r; i ++) mn = min(mn, a[i]);
	if (a[l] == mn) return;
	int pos = 0;
	for (int i = l; i <= r; i ++) if (a[i] == mn) pos = i;

	if ((pos - l) % 2 == 1) {
		if (pos == r) op(pos - 2), pos = pos - 2;
		op(pos - 1); pos ++;
	} 	

	for (int i = pos - 2; i >= l; i -= 2) {
		op(i);
	}
}
int main() {
	scanf("%d", &t);
	while (t --) {
		scanf("%d", &n);
		ans.clear();
		for (int i = 1; i <= n; i ++) scanf("%d", &a[i]), b[i] = a[i],  a[i] *= 1000;
		int inv = 0;
		for (int i = 1; i <= n; i ++) for (int j = i + 1; j <= n; j ++) if (a[i] > a[j]) inv ++;
		for (int i = 1; i <= n; i ++) {
			int cnt = 0;
			for (int j = 1; j < i; j ++) if (b[i] == b[j]) a[i] ++;
		}

		if (inv % 2) {
			bool fg = 0;
			for (int i = 1; i <= n; i ++) { 
				if (fg) break;
				for (int j = i + 1; j <= n; j ++){
					if (fg) break;
					if (b[i] == b[j]) {
						swap(a[i], a[j]); fg = 1;
					}
				}
			}
			if (! fg) {
				printf("-1\n");
				continue;
			}
		}
		for (int i = 1; i <= n; i ++) {
			solve(i, n);
		}
		bool fg = 1;
		for (int i = 1; i < n; i ++) if (a[i] > a[i + 1]) fg = 0;
		if (! fg) {
			printf("-1\n"); continue;
		}
		printf("%d\n", ans.size());
		for (auto x: ans) printf("%d ", x); printf("\n");
		for (int i = 1; i < n; i ++) assert(a[i] <= a[i+1]);
	}
}
/*
1 2 3 x
1 3 2
2 1 3
2 3 1 x
3 1 2 x
3 2 1

5 2 1 6 3 4 7
1 5 2 6 3 4 7
1 5 3 2 6 4 7
1 2 5 3 6 4 7
1 2 6 5 3 4 7
1 2 3 6 5 4 7
1 2 3 4 6 5 7
1 2 3 4 7 6 5
1 2 3 4 5 7 6

inv parity not change
*/