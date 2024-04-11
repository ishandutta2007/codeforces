#include <bits/stdc++.h>
using namespace std;

#define N 200005

int n, w[N], h[N], b[N], mx1a, mx2a, totw;

int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++) {
		scanf("%d %d", &w[i], &h[i]);
		totw += w[i];
		if (h[mx2a] < h[i]) {
			mx2a = i;
			if (h[mx1a] < h[mx2a])	swap(mx1a, mx2a);
		}
	}
	for (int i = 1; i <= n; i ++) {
		b[i] = (totw - w[i]) * ((i == mx1a) ? h[mx2a] : h[mx1a]);
	}
	for (int i = 1; i <= n; i ++)	printf("%d ", b[i]);
}