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
		int a[n];
		for(i=0; i<n; i++) {
			scanf("%d", &a[i]);
		}
		int x;
		scanf("%d", &x);
		int b[n] = {};
		for(i=0; i<n; i++) {
			int check = 1;
			if(i > 0 && b[i-1]) {
				if(a[i-1]+a[i] < 2*x) {
					check = 0;
				}
				if(i > 1 && b[i-2]) {
					if(a[i-2]+a[i-1]+a[i] < 3*x) {
						check = 0;
					}
				}
			}
			b[i] = check;
		}
		int answer = 0;
		for(i=0; i<n; i++) {
			answer += b[i];
		}
		printf("%d\n", answer);
	}
}