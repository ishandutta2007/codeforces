#include <bits/stdc++.h>

using namespace std;

int main() {
	int cl, ql;
	int i, j, k, l;
	int t, n, m, q;
	int in;
	scanf("%d", &t);
	for(cl=0; cl<t; cl++) {
		scanf("%d %d", &n, &k);
		int a[n];
		for(i=0; i<n; i++) {
			scanf("%d", &a[i]);
		}
		sort(a, a+n);
		int found = 0;
		for(i=0; i<n; i++) {
			if(binary_search(a, a+n, k+a[i])) {
				found = 1;
			}
		}
		if(found) {
			printf("YES\n");
		} else {
			printf("NO\n");
		}
	}
}