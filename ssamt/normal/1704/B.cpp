#include <bits/stdc++.h>

using namespace std;

int main() {
	int cl, ql;
	int i, j, k, l;
	int t, n, m, q;
	int u, v;
	int in;
	scanf("%d", &t);
	for(cl=0; cl<t; cl++) {
		int x;
		scanf("%d %d", &n, &x);
		int a[n];
		for(i=0; i<n; i++) {
			scanf("%d", &a[i]);
		}
		int l, r;
		int answer = 0;
		for(i=0; i<n; i++) {
			l = a[i];
			r = a[i];
			for(j=i+1; j<n; j++) {
				l = min(l, a[j]);
				r = max(r, a[j]);
				if(r-l > 2*x) {
					answer++;
					break;
				}
			}
			i = j-1;
		}
		printf("%d\n", answer);
	}
}