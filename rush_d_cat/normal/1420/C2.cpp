#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL inf = 1e18;
const int N = 600000 + 10;
int t, n, q, a[N];
struct Nod {
	LL f[2][2];
	Nod operator + (const Nod & o) const {
		Nod ans;
		for (int i = 0; i < 2; i ++) for (int j = 0; j < 2; j ++)
			ans.f[i][j] = - inf;

		ans.f[0][0] = ans.f[1][1] = 0;

		for (int i = 0; i < 2; i ++) {
			for (int j = 0; j < 2; j ++) {
				for (int k = 0; k < 2; k ++) {
					ans.f[i][j] = max(ans.f[i][j], f[i][k] + o.f[k][j]);
				}
			}
		}
		return ans;
	}
} nod[N<<2];
Nod gen(int x) {
	Nod ans;
	for (int i = 0; i < 2; i ++) for (int j = 0; j < 2; j ++)
		ans.f[i][j] = - inf;
	ans.f[0][0] = 0; ans.f[1][1] = 0;
	ans.f[1][0] = x;
	ans.f[0][1] = - x;
	return ans;
}
void build(int l, int r, int rt) {
	//printf("build %d %d %d\n", l, r, rt);
	if (l == r) {
		nod[rt] = gen(a[l]); 
		//printf("rt = %d\n", rt);
		/*
		for (int i = 0; i < 2; i ++)
		{
			for (int j = 0; j < 2; j ++) {
				printf("%lld ", nod[rt].f[i][j]);
			} 
			printf("\n");
		}*/
	
		return;
	}
	int mid = (l + r)>>1;
	build(l, mid, rt<<1);
	build(mid+1, r, rt<<1|1);
	//printf("%d = (%d + %d)\n", rt, rt<<1, rt<<1|1);
	nod[rt] = nod[rt<<1] + nod[rt<<1|1];
	//printf("rt = %d\n", rt);
	/*
	for (int i = 0; i < 2; i ++)
	{
		for (int j = 0; j < 2; j ++) {
			printf("%lld ", nod[rt].f[i][j]);
		} 
		printf("\n");
	}
	*/
	
}
void update(int l, int r, int rt, int pos, int x){ 
	if (l == r) {
		nod[rt] = gen(x); return;
	}
	int mid = (l + r) >> 1;
	if (pos <= mid) 
		update(l, mid, rt<<1, pos, x);
	else
		update(mid + 1, r, rt<<1|1, pos, x);
	nod[rt] = nod[rt<<1] + nod[rt<<1|1];
}
Nod query(int l, int r, int rt, int L, int R) {
	if (L <= l && r <= R)
		return nod[rt];
	int mid = (l + r) >> 1;
	if (R <= mid) return query(l, mid, rt<<1, L, R);
	if (L  > mid) return query(mid + 1, r, rt<<1|1, L, R);
	return query(l, mid, rt<<1, L, R) + query(mid + 1, r, rt<<1|1, L, R);
}
int main() {
	scanf("%d", &t);
	while (t --) {
		scanf("%d%d", &n, &q);
		for (int i = 1; i <= n; i ++) {
			scanf("%d", &a[i]);
		}
		build(1, n, 1);
		//printf("!\n");
		printf("%lld\n", max(nod[1].f[1][0], nod[1].f[1][1]));
		//printf("@@\n");
		while (q --) {
			int l, r; scanf("%d%d", &l, &r);
			swap(a[l], a[r]);
			update(1, n, 1, l, a[l]);
			update(1, n, 1, r, a[r]);
			printf("%lld\n", max(nod[1].f[1][0], nod[1].f[1][1]));
		}
	}
}