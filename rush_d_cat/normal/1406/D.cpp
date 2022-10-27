#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 100000 + 10;
int n, a[N];
int q, l, r, x;
LL sum = 0;
LL s[N << 2];
void update(int l, int r, int rt, int L, int R, int x) {
	if (L <= l && r <= R) {
		s[rt] += x; return;
	}
	int mid = (l + r) >> 1;
	if (L <= mid) update(l, mid, rt<<1, L, R, x);
	if (R  > mid) update(mid + 1, r, rt<<1|1, L, R, x);
}
LL res = 0;
void query(int l, int r, int rt, int x) {
	res += s[rt];
	if (l == r) return;
	int mid = (l + r) >> 1;
	if (x <= mid) query(l, mid, rt<<1, x);
	else query(mid + 1, r, rt<<1|1, x);
}
LL query(int x) {
	res = 0;
	query(1, n, 1, x);
	return res;
}
void solve() {

}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++) {
		scanf("%d", &a[i]);	
		update(1, n, 1, i, i, a[i]);
	}

	for (int i = 1; i < n; i ++)
		if (a[i+1] > a[i]) sum += a[i+1] - a[i];
	
	scanf("%d", &q);
	//printf("sum = %lld\n", sum);
	LL tot = query(1);
	// max + min = tot
	// max - min >= sum
	LL res = (tot + sum) / 2;
	if (res * 2 < tot + sum) res ++;
	printf("%lld\n", res);
	while (q --) {
		int l, r, x;
		scanf("%d%d%d", &l, &r, &x);
		if (l > 1) sum -= max(query(l) - query(l-1), 0LL);
		if (r < n) sum -= max(query(r + 1) - query(r), 0LL);
		update(1, n, 1, l, r, x);
		if (l > 1) sum += max(query(l) - query(l-1), 0LL);
		if (r < n) sum += max(query(r + 1) - query(r), 0LL);
		//printf("sum = %lld\n", sum);
		LL tot = query(1);
		// max + min = tot
		// max - min >= sum
		LL res = (tot + sum) / 2;
		if (res * 2 < tot + sum) res ++;
		printf("%lld\n", res);

	}
}