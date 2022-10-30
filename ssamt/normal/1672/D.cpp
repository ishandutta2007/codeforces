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
		int a[n], b[n];
		for(i=0; i<n; i++) {
			scanf("%d", &a[i]);
		}
		for(i=0; i<n; i++) {
			scanf("%d", &b[i]);
		}
		int keep[n+1] = {};
		int answer = 1;
		i = n-1, j = n-1;
		while(i>=0 || j>=0) {
			if(a[i] != b[j]) {
				if(keep[a[i]] > 0) {
					keep[a[i]]--;
					i--;
				} else {
					answer = 0;
					break;
				}
			} else {
				keep[a[i]]++;
				j--;
			}
		}
		if(answer) {
			printf("YES\n");
		} else {
			printf("NO\n");
		}
	}
}