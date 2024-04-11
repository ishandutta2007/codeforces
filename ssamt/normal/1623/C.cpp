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
		int start = 1, end = 1e9+1;
		while(start+1 < end) {
			int mid = (start+end)/2;
			int b[n] = {};
			int check = 1;
			for(i=n-1; i>=2; i--) {
				if(a[i]+b[i] >= mid) {
					int d = min(a[i]/3, (a[i]+b[i]-mid)/3);
					b[i-1] += d;
					b[i-2] += 2*d;
				} else {
					check = 0;
					break;
				}
			}
			if(a[0]+b[0] < mid || a[1]+b[1] < mid) {
				check = 0;
			}
			if(check) {
				start = mid;
			} else {
				end = mid;
			}
		}
		printf("%d\n", start);
	}
}