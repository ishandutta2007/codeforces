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
			scanf("%d %d", &a[i], &b[i]);
		}
		int start = 0, end = n+1;
		while(start+1 < end) {
			int mid = (start+end)/2;
			int count = 0;
			for(i=0; i<n; i++) {
				if(a[i] >= mid-count-1 && b[i] >= count) {
					count++;
				}
			}
			if(count >= mid) {
				start = mid;
			} else {
				end = mid;
			}
		}
		printf("%d\n", start);
	}
}