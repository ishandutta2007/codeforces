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
		int r, c;
		scanf("%d %d %d %d", &n, &m, &r, &c);
		r--; c--;
		char s[n][m+1];
		for(i=0; i<n; i++) {
			scanf("%s", s[i]);
		}
		int all = 0;
		int same = 0;
		for(i=0; i<n; i++) {
			for(j=0; j<m; j++) {
				if(s[i][j] == 'B') {
					all = 1;
					if(i == r || j == c) {
						same = 1;
					}
				}
			}
		}
		if(s[r][c] == 'B') {
			printf("0\n");
		} else if(same) {
			printf("1\n");
		} else if(all) {
			printf("2\n");
		} else {
			printf("-1\n");
		}
	}
}