#include <bits/stdc++.h>

using namespace std;

int main() {
	int cl, ql;
	int i, j, k;
	int t, n, m, q;
	scanf("%d", &t);
	for(cl=0; cl<t; cl++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		int sum = a+b+c;
		if(sum%3 == 0) {
			printf("0\n");
		} else {
			printf("1\n");
		}
	}
}