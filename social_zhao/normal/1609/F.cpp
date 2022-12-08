#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e6 + 5;
int n, a[N], b[N], tmp, col[N], ans, ans2;
int mn[N], mx[N], bin[100], sum[N];

int popcount(int x) { int res = 0; while(x) ++res, x -= (x & (-x)); return res; }

void solve(int l, int r) {
	if(l == r) { ++ans2; return; }
	int mid = (l + r) >> 1, lb, rb;
	solve(l, mid), solve(mid + 1, r);
	
	mn[mid] = mx[mid] = a[mid];
	for(int i = mid - 1; i >= l; i--) mn[i] = min(a[i], mn[i + 1]), mx[i] = max(a[i], mx[i + 1]);
	mn[mid + 1] = mx[mid + 1] = a[mid + 1];
	for(int i = mid + 2; i <= r; i++) mn[i] = min(a[i], mn[i - 1]), mx[i] = max(a[i], mx[i - 1]);
	
	// mn -> left, mx -> left
	lb = mid, rb = mid;
	for(int i = l; i <= mid; i++) sum[i] = col[mn[i]] == col[mx[i]];
	for(int i = l + 1; i <= r; i++) sum[i] += sum[i - 1];
	for(int i = mid + 1; i <= r; i++) {
		while(lb >= l && mn[lb] > mn[i]) --lb;
		while(rb >= l && mx[rb] <= mx[i]) --rb;
		if(min(lb, rb) >= l) ans += sum[min(lb, rb)];
	}
	
	// mn -> left, mx -> right
	lb = l, rb = l - 1;
	for(int i = r; i >= mid + 1; i--) {
		while(lb <= mid && (mx[lb] > mx[i])) --bin[col[mn[lb]]], ++lb;
		while(rb < mid && (mn[rb + 1] <= mn[i])) ++bin[col[mn[rb + 1]]], ++rb;
		if(lb <= rb) ans += bin[col[mx[i]]];
	}
	for(int i = l; i <= mid; i++) bin[col[mn[i]]] = 0;
	
	// mn -> right, mx -> left
	lb = mid + 1, rb = mid;
	for(int i = mid + 1; i <= r; i++) {
		while(lb > l && (mn[lb - 1] > mn[i])) ++bin[col[mx[lb - 1]]], --lb;
		while(rb >= l && (mx[rb] <= mx[i])) --bin[col[mx[rb]]], --rb;
		if(lb <= rb) ans += bin[col[mn[i]]];
	}
	for(int i = l; i <= mid; i++) bin[col[mx[i]]] = 0;
	
	// mn -> right, mx -> right
	lb = l, rb = l;
	for(int i = r; i >= mid + 1; i--) {
		while(lb <= mid && mn[lb] <= mn[i]) ++lb;
		while(rb <= mid && mx[rb] > mx[i]) ++rb;
		if(max(lb, rb) <= mid) ans += (col[mn[i]] == col[mx[i]]) * (mid - max(lb, rb) + 1);
	}
}

main() {
	ios::sync_with_stdio(0);
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i], b[i] = a[i];
	sort(b + 1, b + 1 + n), tmp = unique(b + 1, b + 1 + n) - b - 1;
	for(int i = 1; i <= n; i++) {
		int cnt = popcount(a[i]);
		a[i] = lower_bound(b + 1, b + 1 + tmp, a[i]) - b;
		col[a[i]] = cnt;
	}
	solve(1, n);
	printf("%lld\n", ans + ans2);
	return 0;
}