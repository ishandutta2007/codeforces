#include <bits/stdc++.h>

using namespace std;

int main() {
	int cl, ql;
	int i, j, k;
	int t, n, m, q;
	scanf("%d", &t);
	for(cl=0; cl<t; cl++) {
		scanf("%d", &n);
		int a[n];
		int answer = 0;
		for(i=0; i<n; i++) {
			scanf("%d", &a[i]);
			answer = max(answer, a[i]-i-1);
		}
		printf("%d\n", answer);
	}
}