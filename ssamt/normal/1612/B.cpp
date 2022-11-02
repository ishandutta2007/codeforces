#include <bits/stdc++.h>

using namespace std;

int main() {
	int cl, ql;
	int i, j, k, l;
	int t, n, m, q;
	int in;
	scanf("%d", &t);
	for(cl=0; cl<t; cl++) {
		int a, b;
		scanf("%d %d %d", &n, &a, &b);
		vector<int> per;
		for(i=1; i<=n; i++) {
			if(i != a && i != b) {
				per.push_back(i);
			}
		}
		if(n == 2 || (a < per[(n-2)/2] && b > per[(n-2)/2-1])) {
			printf("%d ", a);
			for(i=n/2-1; i<n-2; i++) {
				printf("%d ", per[i]);
			}
			printf("%d ", b);
			for(i=0; i<n/2-1; i++) {
				printf("%d ", per[i]);
			}
			printf("\n");
		} else {
			printf("-1\n");
		}
	}
}