#include <bits/stdc++.h>

using namespace std;

int main() {
	int i, j, k, l;
	int t, n, m, q;
	scanf("%d", &t);
	for(int cl=0; cl<t; cl++) {
		int a, b;
		scanf("%d %d", &a, &b);
		if(a == 0) {
			printf("1\n");
		} else {
			printf("%d\n", a+2*b+1);
		}
	}
}