#include <bits/stdc++.h>

using namespace std;

int main() {
	int cl, ql;
	int i, j, k, l;
	int t, n, m, q;
	int in;
	scanf("%d", &t);
	for(cl=0; cl<t; cl++) {
		int x;
		scanf("%d %d", &n, &x);
		int a[n];
		for(i=0; i<n; i++) {
			scanf("%d", &a[i]);
		}
		sort(a, a+n);
		int pick[n] = {};
		for(i=0; i<n; i++) {
			if(!pick[i]) {
				long long aim = (long long)a[i]*x;
				if(aim <= 1000000000) {
					int g = aim;
					int low = lower_bound(a, a+n, g)-a;
					int upp = upper_bound(a, a+n, g)-a;
					int idx = upper_bound(pick+low, pick+upp, 0)-pick;
					if(idx != low) {
						pick[i] = 1;
						pick[idx-1] = 1;
					}
				}
			}
		}
		int count = 0;
		for(i=0; i<n; i++) {
			count += pick[i];
		}
		printf("%d\n", n-count);
	}
}