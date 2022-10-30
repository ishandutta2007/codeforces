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
		scanf("%d", &n);
		if(n%7 == 0) {
			printf("%d\n", n);
		} else {
			int ten = n/10*10;
			printf("%d\n", ten+7-ten%7);
		}
	}
}