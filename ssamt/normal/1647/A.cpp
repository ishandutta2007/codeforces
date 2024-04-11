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
		if(n%3) {
			printf("%d", n%3);
		}
		for(i=0; i<n/3; i++) {
			printf((n%3==2)?"12":"21");
		}
		printf("\n");
	}
}