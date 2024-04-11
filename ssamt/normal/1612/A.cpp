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
		if((a+b)%2 == 0) {
			if(a > b) {
				printf("%d %d\n", (a+b)/2, 0);
			} else {
				printf("%d %d\n", 0, (a+b)/2);
			}
		} else {
			printf("-1 -1\n");
		}
	}
}