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
		int last = 0;
		for(i=0; i<n-1; i++) {
			sort(a+last, a+n);
			for(j=n-1; j>=max(last, i+1); j--) {
				a[j] = a[j]-a[j-1];
			}
			a[i] = 0;
			while(a[last] == 0 && last < n) {
				last++;
			}
		}
		printf("%d\n", a[n-1]);
	}
}