#include <bits/stdc++.h>

using namespace std;

int main() {
	int cl, ql;
	int i, j, k;
	int t, n, m, q;
	int in;
	scanf("%d", &t);
	for(cl=0; cl<t; cl++) {
		scanf("%d %d", &n, &k);
		int a[n];
		int b[n];
		for(i=0; i<n; i++) {
			scanf("%d", &a[i]);
			b[i] = a[i];
		}
		sort(b, b+n);
		int pass = k+(n-k+1)/2;
		//printf("%d\n", pass);
		int min_val = 0;
		int minx = b[n-1]-b[0];
		for(i=0; i<=n-pass; i++) {
			if(b[i+pass-1]-b[i] < minx) {
				minx = b[i+pass-1]-b[i];
				min_val = i;
			}
		}
		//printf("%d\n", min_val);
		int x = b[min_val], y = b[min_val+pass-1];
		printf("%d %d\n", x, y);
		int count = 0;
		int last = 0;
		int print_count = 0;
		for(i=0; i<n; i++) {
			if(print_count == k-1) {
				printf("%d %d\n", i+1, n);
				break;
			}
			if(x <= a[i] && a[i] <= y) {
				count++;
			} else {
				count--;
			}
			if(count > 0) {
				printf("%d %d\n", last+1, i+1);
				print_count++;
				last = i+1;
				count = 0;
			}
		}
	}
}