#include <bits/stdc++.h>

using namespace std;

int main() {
	int cl, ql;
	int i, j, k;
	int t, n, m, q;
	int in;
	scanf("%d", &t);
	for(cl=0; cl<t; cl++) {
		scanf("%d", &n);
		int a[n];
		for(i=0; i<n; i++) {
			scanf("%d", &a[i]);
		}
		sort(a, a+n);
		int answer = a[0];
		for(i=1; i<n; i++) {
			answer = max(answer, a[i]-a[i-1]);
		}
		printf("%d\n", answer);
	}
}