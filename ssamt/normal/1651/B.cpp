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
		scanf("%d", &n);
		if(n <=19) {
			printf("YES\n");
			int num = 1;
			for(i=0; i<n; i++) {
				printf("%d ", num);
				num *= 3;
			}
			printf("\n");
		} else {
			printf("NO\n");
		}
	}
}