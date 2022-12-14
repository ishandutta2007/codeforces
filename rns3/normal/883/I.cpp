#include <bits/stdc++.h>
using namespace std;

#define N 300010

int a[N], n, m;

int tree[N];
void init() { memset(tree, 0, sizeof tree); }
void add(int k) { for (; k < N; k += k & -k) tree[k] ++; }
int query(int k) { int sum = 0; for (; k > 0; k -= k & -k) sum += tree[k]; return sum; }
bool OK(int l, int r) { if(l == 0) return true; return query(r) - query(l-1) > 0; }

bool can(int d) {
	init();
	for (int i = 1; i <= n; i ++) {
		int l = lower_bound(a + 1, a + n + 1, a[i] - d) - a - 1;
		if (l > i - m) continue;
		if (OK(l, i - m)) {
			add(i);
			if (i == n) return 1;
		}
	}
	return false;
}

int main() {
	///freopen("in.txt", "r", stdin);
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i ++) {
		scanf("%d", a + i);
	}
	sort(a + 1, a + n + 1);
	int st = -1, en = a[n];
	while ( st < en - 1) {
		int mid = (st + en) >> 1;
		if (can(mid)) en = mid;
		else st = mid;
	}
	printf("%d\n", en);
}