#include <bits/stdc++.h>

using namespace std;

int main() {
	int cl, ql;
	int i, j, k, l;
	int t, n, m, q;
	int u, v;
	int in;
	scanf("%d", &t);
	for(ql=0; ql<t; ql++) {
		scanf("%d", &n);
		int a[n];
		for(i=0; i<n; i++) {
			scanf("%d", &a[i]);
		}
		int ma = 0;
		int answer = 0;
		for(i=0; i<n; i++) {
			ma = max(ma, a[i]);
			if(ma == i+1) {
				answer++;
			}
		}
		printf("%d\n", answer);
	}
}