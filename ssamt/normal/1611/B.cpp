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
		scanf("%d %d", &a, &b);
		if((long long)3*a < b || (long long)3*b < a) {
			printf("%d\n", min(a, b));
		} else {
			printf("%d\n", (a+b)/4);
		}
	}
}