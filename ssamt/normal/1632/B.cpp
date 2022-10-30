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
		for(i=0; ((n-1)>>i)!=0; i++);
		int log = i-1;
		for(i=1; i<(1<<log); i++) {
			printf("%d ", i);
		}
		printf("0 ");
		for(i=(1<<log); i<n; i++) {
			printf("%d ", i);
		}
		printf("\n");
	}
}