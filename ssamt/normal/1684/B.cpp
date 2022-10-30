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
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		long long last = (long long)b*1e8+a;
		printf("%lld %d %d\n", last, b, c);
	}
}