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
		int answer = n-1;
		for(i=0; i<n; i++) {
			for(j=i+1; j<n; j++) {
				int count = 0;
				for(k=0; k<n; k++) {
					if((k-i)*(a[k]-a[j]) == (k-j)*(a[k]-a[i])) {
						count++;
					}
				}
				answer = min(answer, n-count);
			}
		}
		printf("%d\n", answer);
	}
}