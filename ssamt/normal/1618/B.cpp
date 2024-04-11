#include <bits/stdc++.h>

using namespace std;

int main() {
	int cl, ql;
	int i, j, k, l;
	int t, n, m, q;
	int in;
	scanf("%d", &t);
	for(cl=0; cl<t; cl++) {
		scanf("%d", &n);
		n -= 2;
		char s[n][3];
		for(i=0; i<n; i++) {
			scanf("%s", s[i]);
		}
		int find = -1;
		for(i=0; i<n-1; i++) {
			if(s[i][1] != s[i+1][0]) {
				find = i;
			}
		}
		if(find == -1) {
			for(i=0; i<n; i++) {
				printf("%c", s[i][0]);
			}
			printf("%c", s[n-1][1]);
			printf("a\n");
		} else {
			for(i=0; i<n; i++) {
				printf("%c", s[i][0]);
				if(i == find) {
					printf("%c", s[i][1]);
				}
			}
			printf("%c\n", s[n-1][1]);
		}
	}
}