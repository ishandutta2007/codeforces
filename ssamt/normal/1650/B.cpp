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
		int l, r, a;
		scanf("%d %d %d", &l, &r, &a);
		if(r%a == a-1) {
			printf("%d\n", r/a+r%a);
		} else if(l <= r/a*a-1) {
			printf("%d\n", r/a-1+a-1);
		} else {
			printf("%d\n", r/a+r%a);
		}
	}
}