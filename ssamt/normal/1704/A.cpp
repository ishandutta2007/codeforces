#include <bits/stdc++.h>

using namespace std;

int main() {
	int cl, ql;
	int i, j, k, l;
	int t, n, m, q;
	int u, v;
	int in;
	scanf("%d", &t);
	for(cl=0; cl<t; cl++) {
		scanf("%d %d", &n, &m);
		char a[n+1], b[m+1];
		scanf("%s", a);
		scanf("%s", b);
		int check = 1;
		for(i=1; i<m; i++) {
			if(a[n-m+i] != b[i]) {
				check = 0;
			}
		}
		int find = 0;
		for(i=0; i<n-m+1; i++) {
			if(a[i] == b[0]) {
				find = 1;
			}
		}
		if(!find) {
			check = 0;
		}
		if(check) {
			printf("YES\n");
		} else {
			printf("NO\n");
		}
	}
}