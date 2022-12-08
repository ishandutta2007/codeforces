#include<bits/stdc++.h>
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 1e6 + 5, S = 30;
int n, m, a[N], val[S + 5], tim[S + 5], ans[N];
struct Ask { int l, r, id; } q[N];

void insert(int x, int t) {
	for(int i = S; i >= 0; i--)
		if(x >> i & 1) {
			if(!val[i]) val[i] = x, tim[i] = t;
			if(val[i] && tim[i] < t) { swap(val[i], x), swap(tim[i], t); }
			x ^= val[i];
		}
}

int query(int x, int t) {
	int res = x;
	for(int i = S; i >= 0; i--) if(tim[i] >= t && (res ^ val[i]) > res) res ^= val[i];
	return res;
}

int main() {
	n = get();
	for(int i = 1; i <= n; i++) a[i] = get();
	m = get();
	for(int i = 1; i <= m; i++) q[i].l = get(), q[i].r = get(), q[i].id = i;
	sort(q + 1, q + 1 + m, [](Ask x, Ask y) { return x.r < y.r; });
	for(int i = 1, nowr = 0; i <= m; i++) {
		while(nowr < q[i].r) ++nowr, insert(a[nowr], nowr);
		ans[q[i].id] = query(0, q[i].l);
	}
	for(int i = 1; i <= m; i++) printf("%d\n", ans[i]);
	return 0;
}

/*
1
137250450
1
1 1 849780538
*/