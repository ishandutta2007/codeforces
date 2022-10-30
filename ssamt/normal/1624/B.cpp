#include <bits/stdc++.h>

using namespace std;

int main() {
	int cl, ql;
	int i, j, k;
	int t, n, m, q;
	int in;
	scanf("%d", &t);
	for(cl=0; cl<t; cl++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		int check = 0;
		if((2*b-a)%c == 0 && 2*b-a > 0) {
			check = 1;
		}
		if((2*b-c)%a == 0 && 2*b-c > 0) {
			check = 1;
		}
		if((a+c)%(2*b) == 0) {
			check = 1;
		}
		if(check) {
			printf("YES\n");
		} else {
			printf("NO\n");
		}
	}
}