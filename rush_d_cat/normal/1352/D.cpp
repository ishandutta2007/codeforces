#include <bits/stdc++.h>
using namespace std;
const int N = 1002;
int t, n, a[N];
int main() {
	scanf("%d", &t);
	while (t --) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i ++) scanf("%d", &a[i]);
		int l = 1, r = n;
		int cnt = 0, A = 0, B = 0;
		int cA = 0, cB = 0;
		while (l <= r) {
			bool fg = 0; 
			int tmp = 0;
			while (l <= r) {
				if (tmp > cB) break;
				A += a[l]; tmp += a[l];
				l ++;  fg = 1;
			}
			cA = tmp;
			if (fg) cnt ++;
			//printf("# [%d, %d]\n", l, r);
			fg = 0;
			tmp = 0;
			while (r >= l) {
				if (tmp > cA) break;
				B += a[r]; tmp += a[r];
				r --; fg = 1;
			}
			cB = tmp;
			if (fg) cnt ++;
			//printf("[%d, %d]\n", l, r);
		}
		printf("%d %d %d\n", cnt, A, B);
	}
}