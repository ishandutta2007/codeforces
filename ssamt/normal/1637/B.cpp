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
		long long answer = 0;
		for(i=0; i<n; i++) {
			int num = 1;
			if(a[i] == 0) {
				num = 2;
			}
			answer += (long long)(i+1)*(n-i)*num;
		}
		printf("%lld\n", answer);
	}
}