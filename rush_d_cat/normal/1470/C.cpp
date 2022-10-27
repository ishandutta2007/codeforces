#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 100000 + 10;
int f[N], n, k, root = 1;
int pos(int x) {
	while (x < 1) x += n;
	while (x > n) x -= n;
	return x;
}
int ask(int x) {
	while (x < 1) x += n;
	while (x > n) x -= n;
	printf("? %d\n", x); fflush(stdout);
	
	int y;
	//printf("pos %d, value %d\n", x, y);
	scanf("%d", &y); 
	return y;
	/*
	int g[N] = {0};
	for (int i = 1; i <= n; i ++) {
		if (i == root) {
			g[pos(i+1)] += f[i];
		} else {
			g[pos(i+1)] += (f[i] + 1) / 2;
			g[pos(i-1)] += f[i] / 2;
		}
	}
	for (int i = 1; i <= n; i ++) {
		f[i] = g[i];
		printf("%d%c", f[i]," \n"[i==n]);
	}
	return y;
	*/
}


int main() {	
	scanf("%d%d",&n,&k);
	for (int i = 1; i <= n; i ++) f[i] = k;



	int pos;
	for(int i=1;i<=317;i++) ask(1);
	for(int i=1;i<=n;i+=sqrt(n)/2) {
		if(ask(i) > k) {
			pos = i; break;
		}
	}

	//printf("## %d\n", pos);
	int r = pos, l = pos - n / 2 - 1;
	while (r - l > 1) {
		int mid = (l + r) >> 1;
		if (ask(mid) > k) r = mid; else l = mid;
	}
	r --;
	while (r < 1) r += n;
	while (r > n) r -= n; 
	printf("! %d\n", r); fflush(stdout);
}