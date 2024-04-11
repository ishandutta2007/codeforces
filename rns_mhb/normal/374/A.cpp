#include <bits/stdc++.h>
using namespace std;

int c[10], d[10];

int func(int x){
	if(x < 0) return -x;
	else return x;
}

int main(){
	int a, b, x, y, i, j, n, m, ans = 1e9;
	scanf("%d %d %d %d %d %d", &n, &m, &x, &y, &a, &b);
	c[0] = 1; d[0] = 1;
	c[1] = 1; d[1] = m;
	c[2] = n; d[2] = 1;
	c[3] = n; d[3] = m;
	for(int u = 0; u < 4; u++){
		if(func(x - c[u]) % a == 0 && func(y - d[u]) % b == 0){
			i = func(x - c[u]) / a;
			j = func(y - d[u]) / b;
			if((i + j) % 2 == 0){
				if(i == 0 && j > 0 && a >= n) continue;
				if(j == 0 && i > 0 && b >= m) continue;
				ans = min(ans, max(i, j));
			}
		}
	}
	if(ans == 1000000000) puts("Poor Inna and pony!");
	else printf("%d\n", ans);
}