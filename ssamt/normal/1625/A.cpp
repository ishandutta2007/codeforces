#include <bits/stdc++.h>

using namespace std;

int main() {
	int cl, ql;
	int i, j, k, l;
	int t, n, m, q;
	int in;
	scanf("%d", &t);
	for(cl=0; cl<t; cl++) {
		scanf("%d %d", &n, &l);
		int x[n];
		for(i=0; i<n; i++) {
			scanf("%d", &x[i]);
		}
		int answer = 0;
		for(i=0; i<l; i++) {
			int count = 0;
			for(j=0; j<n; j++) {
				if(x[j]&(1<<i)) {
					count++;
				}
			}
			if(count > n/2) {
				answer += (1<<i);
			}
		}
		printf("%d\n", answer);
	}
}