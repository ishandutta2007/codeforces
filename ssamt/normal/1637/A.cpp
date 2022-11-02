#include <bits/stdc++.h>

using namespace std;

int main() {
	int cl, ql;
	int i, j, k, l;
	int t, n, m, q;
	int in;
	scanf("%d", &t);
	for(cl=0; cl<t; cl++) {
		scanf("%d", &n);
		int a[n], b[n];
		for(i=0; i<n; i++) {
			scanf("%d", &a[i]);
			b[i] = a[i];
		}
		sort(b, b+n);
		int check = 1;
		for(i=0; i<n; i++) {
			if(a[i] != b[i]) {
				check = 0;
			}
		}
		if(check) {
			printf("NO\n");
		} else {
			printf("YES\n");
		}
	}
}