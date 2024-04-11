#include <bits/stdc++.h>

using namespace std;

int main() {
	int cl, ql;
	int i, j, k, l;
	int t, n, m, q;
	int in;
	scanf("%d", &t);
	for(cl=0; cl<t; cl++) {
		long long n;
		scanf("%lld", &n);
		for(i=0; i<64 && !(n&((long long)1<<i)); i++);
		int down = i;
		for(i=63; i>=0 && !(n&((long long)1<<i)); i--);
		int up = i;
		if(up == down) {
			printf("-1\n");
		} else if(up > 2*down) {
			printf("%lld\n", ((long long)1<<(down+1)));
		} else {
			printf("%lld\n", n>>down);
		}
	}
}