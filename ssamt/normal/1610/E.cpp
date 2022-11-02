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
		int a[n];
		for(i=0; i<n; i++) {
			scanf("%d", &a[i]);
		}
		int answer = 0;
		for(i=0; i<n; i++) {
			if(i == 0 || a[i-1] != a[i]) {
				int count = 1;
				int idx = i+1;
				while(idx < n && a[idx-1] == a[idx]) {
					idx++;
					count++;
				}
				while(idx < n) {
					idx = lower_bound(a, a+n, 2*a[idx]-a[i])-a;
					count++;
				}
				answer = max(answer, count);
			}
		}
		printf("%d\n", n-answer);
	}
}