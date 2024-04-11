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
		char s[300000];
		scanf("%s", s);
		int zero = 0, one = 0;
		for(i=0; s[i]; i++) {
			if(s[i] == '0') {
				zero++;
			} else {
				one++;
			}
		}
		if(zero != one) {
			printf("%d\n", min(one, zero));
		} else {
			printf("%d\n", one-1);
		}
	}
}