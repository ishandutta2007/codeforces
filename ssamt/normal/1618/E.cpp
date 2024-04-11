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
		long long a[n], b[n];
		for(i=0; i<n; i++) {
			scanf("%lld", &b[i]);
		}
		long long sum = 0;
		for(i=0; i<n; i++) {
			sum += b[i];
		}
		int answer = 1;
		if(sum%(n*(n+1)/2) == 0) {
			long long asum = sum/(n*(n+1)/2);
			for(i=0; i<n; i++) {
				if((asum-(b[i]-b[(i-1+n)%n]))%n == 0) {
					a[i] = (asum-(b[i]-b[(i-1+n)%n]))/n;
					if(a[i] <= 0) {
						answer = 0;
						break;
					}
				} else {
					answer = 0;
					break;
				}
			}
		} else {
			answer = 0;
		}
		if(answer) {
			printf("YES\n");
			for(i=0; i<n; i++) {
				printf("%lld ", a[i]);
			}
			printf("\n");
		} else {
			printf("NO\n");
		}
	}
}