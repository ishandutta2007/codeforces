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
		long long n, s;
		scanf("%lld %lld", &n, &s);
		printf("%lld\n", s/(n*n));
	}
}