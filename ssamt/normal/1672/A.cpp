#include <bits/stdc++.h>

using namespace std;

int main() {
	int cl, ql;
	int i, j, k, l;
	int t, n, q;
	int in;
	scanf("%d", &t);
	for(cl=0; cl<t; cl++) {
		scanf("%d", &n);
		int a[n];
		for(i=0; i<n; i++) {
			scanf("%d", &a[i]);
		}
		int sum = 0;
		for(i=0; i<n; i++) {
			sum += a[i]-1;
		}
		if(sum%2 == 0) {
			printf("maomao90\n");
		} else {
			printf("errorgorn\n");
		}
	}
}