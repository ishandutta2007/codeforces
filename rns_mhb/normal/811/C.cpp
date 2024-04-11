#include <bits/stdc++.h>
using namespace std;
#define N 5005

int a[N], n, b[N], r[N], l[N], c[N], d[N], e[N][N], f[N];

int main(){
	int i, st, fs, j;
	scanf("%d", &n);
	for(i = 1; i <= n; i++) scanf("%d", a + i);
	for(i = 1; i <= n; i++){
		f[i] = c[a[i]]; c[a[i]] = i;
		if(b[a[i]]) l[i] = b[a[i]];
		else l[i] = b[a[i]] = i;
	}
	memset(c, 0, sizeof c);
	for(i = n; i > 0; i--){
		if(c[a[i]]) r[i] = c[a[i]];
		else r[i] = c[a[i]] = i;
	}
	for(i = 1; i <= n; i++) for(j = i; j <= n; j++){
		if(f[j] < i || f[j] == j) e[i][j] = e[i][j - 1] ^ a[j];
		else e[i][j] = e[i][j - 1];
	}
	for(i = 1; i <= n; i++){
		d[i] = d[i - 1];
		if(r[i] != i) continue;
		fs = i; st = l[i];
		while(fs > st){
			if(r[fs - 1] > i) break;
			st = min(st, l[fs - 1]);
			fs--;
		}
		if(fs > st) continue;
		d[i] = max(d[i], e[st][i] + d[st - 1]);
	}
	printf("%d", d[n]);
}