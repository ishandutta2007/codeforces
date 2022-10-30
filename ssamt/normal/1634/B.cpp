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
		long long x, y;
		scanf("%d %lld %lld", &n, &x, &y);
		x ^= y;
		for(i=0; i<n; i++) {
			scanf("%d", &in);
			x ^= in;
		}
		if(x%2 == 0) {
			printf("Alice\n");
		} else {
			printf("Bob\n");
		}
	}
}