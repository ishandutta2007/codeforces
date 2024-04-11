#include <bits/stdc++.h>

using namespace std;

int main() {
	int cl, ql;
	int i, j, k, l;
	int t, n, m, q;
	int u, v;
	int in;
	scanf("%d", &t);
	for(cl=0; cl<t; cl++) {
		scanf("%d", &n);
		int a[n];
		for(i=0; i<n; i++) {
			scanf("%d", &a[i]);
		}
		int b[n];
		for(i=0; i<n; i++) {
			scanf("%d", &b[i]);
		}
		int maxa = 0, maxb = 0;
		for(i=0; i<n; i++) {
			maxa = max(maxa, min(a[i], b[i]));
			maxb = max(maxb, max(a[i], b[i]));
		}
		printf("%d\n", maxa*maxb);
	}
}