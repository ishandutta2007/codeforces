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
		int one = 0;
		for(i=0; i<n; i++) {
			if(a[i] == 1) {
				one = 1;
			}
		}
		int answer;
		if(one) {
			sort(a, a+n);
			answer = 1;
			for(i=0; i<n-1; i++) {
				if(a[i+1]-a[i] == 1) {
					answer = 0;
				}
			}
		} else {
			answer = 1;
		}
		if(answer) {
			printf("YES\n");
		} else {
			printf("NO\n");
		}
	}
}