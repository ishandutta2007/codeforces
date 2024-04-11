#include <stdio.h>
#include <algorithm>
#define lc 2*o
#define rc 2*o+1
using namespace std;
const int maxn = 4 * 100100;
int a[maxn], f[maxn], g[maxn], ql, qr, val[maxn];
void Update(int o, int l, int r){
	if(r - l == 1)
		val[o] = qr;
	else{
		int mid = (l + r) / 2;
		if(ql < mid) Update(lc, l, mid);
		else Update(rc, mid, r);
		val[o] = max(val[lc], val[rc]);
	}
}
int Query(int o, int l, int r){
	if(ql <= l && r <= qr)
		return val[o];
	else{
		int mid = (l + r) / 2, rnt = 0;
		if(ql < mid) rnt = max(Query(lc, l, mid), rnt);
		if(mid < qr) rnt = max(Query(rc, mid, r), rnt);
		return rnt;
	}
}
int main(){
	int n, m; scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++){
		int l, r; scanf("%d%d", &l, &r);
		a[l]++;
		a[r+1]--;
	}
	for(int i = 1; i <= m; i++)
		a[i] += a[i-1];
	for(int i = 1; i <= m; i++){
		ql = 0; qr = a[i] + 1;
		f[i] = Query(1, 0, n + 1) + 1;
		ql = a[i]; qr = f[i];
		Update(1, 0, n + 1);
	}
	for(int i = 0; i <= n; i++){
		ql = i; qr = 0;
		Update(1, 0, n + 1);
	}
	for(int i = m; i > 0; i--){
		ql = 0; qr = a[i] + 1;
		g[i] = Query(1, 0, n + 1) + 1;
		ql = a[i]; qr = g[i];
		Update(1, 0, n + 1);
	}
	/*
	for(int i = 1; i <= m; i++)
		printf("%d ", a[i]);
	printf("\n");
	for(int i = 1; i <= m; i++)
		printf("%d ", f[i]);
	printf("\n");
	for(int i = 1; i <= m; i++)
		printf("%d ", g[i]);
	printf("\n");
	*/
	int ans = 0;
	for(int i = 1; i <= m; i++)
		ans = max(f[i] + g[i] - 1, ans);
	printf("%d\n", ans);
	return 0;
}