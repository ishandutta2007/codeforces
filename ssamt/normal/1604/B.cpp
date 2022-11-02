#include <bits/stdc++.h>

using namespace std;

int main() {
	int cl, ql;
	int i, j, k;
	int t, n, m, q;
	scanf("%d", &t);
	for(cl=0; cl<t; cl++) {
		scanf("%d", &n);
		int a[n];
		int answer = 0;
		for(i=0; i<n; i++) {
			scanf("%d", &a[i]);
		}
		int inc = 1;
		for(i=0; i<n-1; i++) {
			if(a[i] >= a[i+1]) {
				inc = 0;
			}
		}
		if(n%2 == 1 && inc) {
			printf("NO\n");
		} else {
			printf("YES\n");
		}
	}
}