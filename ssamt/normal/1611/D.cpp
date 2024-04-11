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
		int b[n], p[n];
		for(i=0; i<n; i++) {
			scanf("%d", &b[i]);
			b[i]--;
		}
		for(i=0; i<n; i++) {
			scanf("%d", &p[i]);
			p[i]--;
		}
		int pos = 1;
		int idx[n];
		for(i=0; i<n; i++) {
			idx[p[i]] = i;
		}
		for(i=0; i<n; i++) {
			if(b[i] != i) {
				if(idx[i] < idx[b[i]]) {
					pos = 0;
				}
			}
		}
		if(pos) {
			for(i=0; i<n; i++) {
				printf("%d ", idx[i]-idx[b[i]]);
			}
			printf("\n");
		} else {
			printf("-1\n");
		}
	}
}