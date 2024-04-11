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
		int check = 0;
		int all = 1;
		for(i=0; i<n && a[i]==0; i++);
		int left = i;
		for(i=n-1; i>=0 && a[i]==0; i--);
		int right = i;
		for(i=left; i<=right; i++) {
			if(a[i] == 0) {
				check = 1;
			} else {
				all = 0;
			}
		}
		if(all) {
			printf("0\n");
		} else if(check) {
			printf("2\n");
		} else {
			printf("1\n");
		}
	}
}