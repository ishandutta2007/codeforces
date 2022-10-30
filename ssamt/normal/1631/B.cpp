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
		int count = 0;
		while(true) {
			for(j=n-1; j>=0 && a[j]==a[n-1]; j--);
			if(j == -1) {
				printf("%d\n", count);
				break;
			} else {
				for(i=max(0, 2*(j+1)-n); i<=j; i++) {
					a[i] = a[n-1];
				}
				count++;
			}
		}
	}
}