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
		int z;
		scanf("%d %d", &n, &z);
		int a[n];
		for(i=0; i<n; i++) {
			scanf("%d", &a[i]);
		}
		int answer = 0;
		for(i=0; i<n; i++) {
			answer = max(answer, a[i]|z);
		}
		printf("%d\n", answer);
	}
}