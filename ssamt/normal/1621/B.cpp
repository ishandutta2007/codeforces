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
		int l[n], r[n], c[n];
		int minl = INT_MAX, minl_idx;
		int maxr = INT_MIN, maxr_idx;
		int max_one = INT_MIN, max_one_idx;
		for(i=0; i<n; i++) {
			scanf("%d %d %d", &l[i], &r[i], &c[i]);
			if(l[i] < minl || (l[i] == minl && c[i] < c[minl_idx])) {
				minl = l[i];
				minl_idx = i;
			}
			if(r[i] > maxr || (r[i] == maxr && c[i] < c[maxr_idx])) {
				maxr = r[i];
				maxr_idx = i;
			}
			if(r[i]-l[i]+1 > max_one || (r[i]-l[i]+1 == max_one && c[i] < c[max_one_idx])) {
				max_one = r[i]-l[i]+1;
				max_one_idx = i;
			}
			if(max_one == maxr-minl+1 && c[max_one_idx] < c[minl_idx]+c[maxr_idx]) {
				printf("%d\n", c[max_one_idx]);
			} else {
				printf("%d\n", c[minl_idx]+c[maxr_idx]);
			}
		}
	}
}