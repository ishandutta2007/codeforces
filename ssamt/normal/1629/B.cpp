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
		int l, r;
		scanf("%d %d %d", &l, &r, &k);
		if((r+1)/2-l/2 <= k || (l == r && l != 1)) {
			printf("YES\n");
		} else {
			printf("NO\n");
		}
	}
}