#include <bits/stdc++.h>

using namespace std;

int main() {
	int cl, ql;
	int i, j, k, l;
	int t, n, m, q;
	int in;
	scanf("%d", &t);
	for(cl=0; cl<t; cl++) {
		scanf("%d %d", &n, &m);
		if(n == 1 && m == 1) {
			printf("0\n");
		} else if(n == 1 || m == 1) {
			printf("1\n");
		} else {
			printf("2\n");
		}
	}
}