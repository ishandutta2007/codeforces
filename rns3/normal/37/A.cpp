#include <bits/stdc++.h>
using namespace std;

#define M 2011
int sto[M], a[M], num[M];

int main() {
	///freopen("a.in", "r", stdin);
	int n;
	scanf("%d", &n);
	int cnt = 0;
	for(int i = 1; i <= n; i ++) scanf("%d", &a[i]), sto[cnt ++] =  a[i];
	sort(sto, sto + cnt);
	cnt = unique(sto, sto + cnt) - sto;
	for(int i = 1; i <= n; i ++) {
		int x = lower_bound(sto, sto + cnt, a[i]) - sto;
		num[x] ++;
	}
	int mx = 0;
	for(int i = 0; i < cnt; i ++) mx = max(mx, num[i]);
	printf("%d %d\n", mx, cnt);
}