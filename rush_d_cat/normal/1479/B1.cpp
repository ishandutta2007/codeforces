#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
int a[N << 2], lz[N << 2];
void pushdown(int rt) {
	if (lz[rt]) {
		lz[rt<<1] += lz[rt];
		a[rt<<1] += lz[rt];
		lz[rt<<1|1] += lz[rt];
		a[rt<<1|1] += lz[rt];
		lz[rt] = 0;
	}
}
void update1(int l, int r, int rt, int L, int R) {
	if (L <= l && r <= R) {
		a[rt] ++, lz[rt] ++; return;
	}
	int mid = (l+r)>>1; pushdown(rt);
	if (L<=mid) update1(l,mid,rt<<1,L,R);
	if (R >mid) update1(mid+1,r,rt<<1|1,L,R);
	a[rt] = max(a[rt<<1], a[rt<<1|1]);
}

void update2(int l, int r, int rt, int pos, int x) {
	if (l == r) {
		a[rt] = max(a[rt], x); return;
	}
	int mid = (l+r)>>1; pushdown(rt);
	if (pos <= mid) update2(l, mid, rt<<1, pos, x);
	else update2(mid+1, r, rt<<1|1, pos, x);
	a[rt] = max(a[rt<<1], a[rt<<1|1]);
}
int query(int l, int r, int rt, int L, int R) {
	if (L <= l && r <= R) return a[rt];
	int mid = (l + r) >> 1; pushdown(rt);
	int ans = 0;
	if (L <= mid) ans = max(ans, query(l,mid,rt<<1,L,R));
	if (R  > mid) ans = max(ans, query(mid+1,r,rt<<1|1,L,R));
	return ans;
}
int main() {
	ios::sync_with_stdio(false);	
	int n;
	cin >> n;
	vector<int> a(n);
	
	for (int i = 0; i < n; i ++) {
		cin >> a[i];
		if (i == 0) {
			update2(0, n, 1, 0, 1);
		} else {
			int tmp = query(0, n, 1, 0, a[i]-1);
			if (a[i] + 1 <= n)
				tmp = max(tmp, query(0, n, 1, a[i]+1, n));
			++ tmp;
			tmp = max(tmp, query(0, n, 1, a[i], a[i]));
			
			if (a[i] != a[i-1])
				update1(0, n, 1, 0, n);
			update2(0, n, 1, a[i-1], tmp);
		}
	}
	int ans = 0;
	for (int i = 0; i <= n; i ++) ans = max(ans, query(0, n, 1, i, i));
	cout << ans << endl;
}