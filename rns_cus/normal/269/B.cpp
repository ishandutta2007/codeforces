#include <bits/stdc++.h>

using namespace std;

#define N 5050

int n, m;
int a[N], f[N];

int main() {
	double x;
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i ++) scanf("%d%lf", a + i, &x);
	int rt = 0;
	for(int i = 1; i <= n; i ++) {
		int mx = 0;
		for(int j = 1; j <= a[i]; j ++) if(mx < f[j]) mx = f[j];
		mx ++;
		f[a[i]] = max(mx, f[a[i]]);
		rt = max(rt, f[a[i]]);
	}
	printf("%d\n", n - rt);
}