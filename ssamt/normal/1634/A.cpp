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
		scanf("%d %d", &n, &k);
		char s[n+1];
		scanf("%s", s);
		int palin = 1;
		for(i=0; i<n; i++) {
			if(s[i] != s[n-1-i]) {
				palin = 0;
			}
		}
		if(palin || k == 0) {
			printf("1\n");
		} else {
			printf("2\n");
		}
	}
}