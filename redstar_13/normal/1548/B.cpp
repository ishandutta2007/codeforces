#include<bits/stdc++.h>

#define NN 222222
using namespace std;
using INT = long long;
using pii = pair<int, int>;

INT gcd[NN << 2], a[NN];

#define ls (u << 1)
#define rs (ls | 1)
#define mid (st + ed >> 1)

void push_up(int u) {
	gcd[u] = __gcd(gcd[ls], gcd[rs]);
}

inline void smin(int &u, int v) {
	if(u > v) u = v;
}

inline void smax(int &u, int v ) {
	if(u < v) u = v;	
}
void build(int u, int st, int ed) {
	if(ed == st + 1) {gcd[u] = abs(a[st] - a[st + 1]); return ;}
	build(ls, st, mid);
	build(rs, mid, ed);
	push_up(u);	
}

INT calc(int u, int st, int ed, int l, int r) {
	smax(l, st);
	smin(r, ed);
	if(l >= r) return 0;	
	if(l == st and r == ed) return gcd[u];
	return __gcd(calc(ls, st, mid, l, r), calc(rs, mid, ed, l, r));
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif
	int T;
	cin >> T;
	while(T--) {
		int n;
		scanf("%d", &n);
		for(int i = 1; i <= n; i ++) scanf("%I64d", a + i);
		if(n == 1) {
			puts("1");
			continue;
		}
		build(1, 1, n);
		int ans = 1;
		int j = 1;
		for(int i = 1, j = 1; i < n; i ++) {
			for(j = max(j, i); j < n; j ++) {
				INT c = calc(1, 1, n, i, j + 1);
				if(c <= 1) break;
			}
			smax(ans, j - i + 1);
		}
		
		printf("%d\n", ans);
	}
}