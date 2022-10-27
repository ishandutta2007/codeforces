#include <bits/stdc++.h>
using namespace std;
const int N = 1000000 + 10;
int n, q, sum[N<<2];
void update(int l, int r, int rt, int x, int val) {
	if (l == r) {
		sum[rt] += val; return;
	}
	int mid = (l + r) >> 1;
	if (x <= mid) update(l, mid, rt<<1, x, val);
	else update(mid + 1, r, rt<<1|1, x, val);
	sum[rt] = sum[rt<<1] + sum[rt<<1|1];
}
int query(int l, int r, int rt, int x) {
	if (l == r) {
		return l;
	}
	int mid=(l+r)>>1;
	int lef = sum[rt<<1];
	if (x<=lef) return query(l,mid,rt<<1,x);
	return query(mid+1,r,rt<<1|1,x-lef);
}
int main() {
	//memset(sum, -1, sizeof(sum));
	
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; i ++) {
		int x; scanf("%d", &x);
		update(1,n,1,x,1);
	}
	while (q --) {
		int x; scanf("%d", &x);
		if (x < 0) {
			int pos = -x;
			int val = query(1,n,1,pos);
			update(1,n,1,val,-1);
		} else {
			update(1,n,1,x,1);
		}
	}
	if (sum[1] == 0) printf("0\n");
	else printf("%d\n", query(1,n,1,1));
}