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
		scanf("%d %d", &n, &m);
		char s[n][m+1];
		for(i=0; i<n; i++) {
			scanf("%s", s[i]);
		}
		int check = 1;
		for(i=1; i<n; i++) {
			for(j=1; j<m; j++) {
				int sum = 0;
				sum += s[i-1][j-1]-'0';
				sum += s[i][j-1]-'0';
				sum += s[i-1][j]-'0';
				sum += s[i][j]-'0';
				if(sum == 3) {
					check = 0;
				}
			}
		}
		printf(check?"YES\n":"NO\n");
	}
}