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
		int l, r;
		for(l=0; l<n && a[l]; l++);
		for(r=n-1; r>=0 && a[r]; r--);
		printf("%d\n", (l==n)?0:r-l+2);
	}
}