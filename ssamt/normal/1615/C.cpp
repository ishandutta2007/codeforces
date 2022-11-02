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
		char a[n+1], b[n+1];
		scanf("%s", a);
		scanf("%s", b);
		int ca = 0, cb = 0;
		for(i=0; i<n; i++) {
			a[i] -= '0';
			ca += a[i];
			b[i] -= '0';
			cb += b[i];
		}
		int answer = INT_MAX;
		if(ca == cb) {
			int diff = 0;
			for(i=0; i<n; i++) {
				if(a[i] && !b[i]) {
					diff++;
				}
			}
			answer = min(answer, 2*diff);
		}
		if(n-ca+1 == cb) {
			int diff = 0;
			for(i=0; i<n; i++) {
				if(!a[i] && !b[i]) {
					diff++;
				}
			}
			answer = min(answer, 2*diff+1);
		}
		if(answer == INT_MAX) {
			printf("-1\n");
		} else {
			printf("%d\n", answer);
		}
	}
}