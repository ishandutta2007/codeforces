#include <bits/stdc++.h>

using namespace std;

int main() {
	int cl, ql;
	int i, j, k, l;
	int t, n, m, q;
	int u, v;
	int in;
	scanf("%d", &t);
	for(ql=0; ql<t; ql++) {
		scanf("%d", &n);
		int a[n];
		for(i=0; i<n; i++) {
			scanf("%d", &a[i]);
		}
		for(i=0; a[i]==i+1; i++);
		int find = i;
		int idx = -1;
		for(i=0; i<n; i++) {
			if(a[i] == find+1) {
				idx = i;
			}
		}
		if(idx != -1) {
			int b[n];
			for(i=find; i<=idx; i++) {
				b[i] = a[find+idx-i];
			}
			for(i=find; i<=idx; i++) {
				a[i] = b[i];
			}
		}
		for(i=0; i<n; i++) {
			printf("%d ", a[i]);
		}
		printf("\n");
	}
}