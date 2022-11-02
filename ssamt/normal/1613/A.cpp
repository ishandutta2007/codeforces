#include <bits/stdc++.h>

using namespace std;

int main() {
	int cl, ql;
	int i, j, k, l;
	int t, n, m, q;
	int in;
	scanf("%d", &t);
	for(cl=0; cl<t; cl++) {
		int x[2], p[2];
		for(i=0; i<2; i++) {
			scanf("%d %d", &x[i], &p[i]);
			while(x[i] < 1000000) {
				x[i] *= 10;
				p[i]--;
			}
		}
		if(p[0] < p[1]) {
			printf("<\n");
		} else if(p[0] > p[1]) {
			printf(">\n");
		} else {
			if(x[0] < x[1]) {
				printf("<\n");
			} else if(x[0] > x[1]) {
				printf(">\n");
			} else {
				printf("=\n");
			}
		}
	}
}