#include <bits/stdc++.h>

using namespace std;

int main() {
	int cl, ql;
	int i, j, k, l;
	int t, n, q;
	int in;
	scanf("%d", &t);
	for(cl=0; cl<t; cl++) {
		scanf("%d", &n);
		int a[n];
		for(i=0; i<n; i++) {
			scanf("%d", &a[i]);
		}
		int l=-1, r=-1;
		for(i=0; i<n-1; i++) {
			if(a[i] == a[i+1]) {
				r = i;
			}
		}
		for(i=n-2; i>=0; i--) {
			if(a[i] == a[i+1]) {
				l = i;
			}
		}
		if(l == r) {
			printf("0\n");
		} else {
			printf("%d\n", max(1, r-l-1));
		}
	}
}