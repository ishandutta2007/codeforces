#include <bits/stdc++.h>

using namespace std;

int main() {
	int cl, ql;
	int i, j, k, l;
	int t, n, m, q;
	int in;
	scanf("%d", &t);
	for(cl=0; cl<t; cl++) {
		long long b[7];
		for(i=0; i<7; i++) {
			scanf("%lld", &b[i]);
		}
		if(b[2] == b[0]+b[1]) {
			if(b[6] == b[0]+b[1]+b[2]) {
				printf("%lld %lld %lld\n", b[0], b[1], b[2]);
			} else {
				printf("%lld %lld %lld\n", b[0], b[1], b[3]);
			}
		} else {
			printf("%lld %lld %lld\n", b[0], b[1], b[2]);
		}
	}
}