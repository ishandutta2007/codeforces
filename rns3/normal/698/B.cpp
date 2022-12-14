#include <bits/stdc++.h>
using namespace std;

#define N 200002

int n, ans, l, rt, p[N], f[N];

void func(int x){
	f[x]= ++ l;
	while (!f[p[x]]) x = p[x], f[x] = l;
	if(f[p[x]] == l){
		if(!rt) rt = x;
		if(p[x] != rt) p[x] = rt, ans ++;
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++) scanf("%d", &p[i]);
	for (int i = 1; i <= n; i ++) if (i == p[i]) rt = i;
	for (int i = 1; i <= n; i ++) if (!f[i]) func(i);
	printf("%d\n", ans);
	for (int i = 1; i < n; i ++) printf("%d ", p[i]);
	printf("%d\n", p[n]);
	return 0;
}