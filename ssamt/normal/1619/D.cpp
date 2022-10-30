#include <bits/stdc++.h>

using namespace std;

int main() {
	int cl, ql;
	int i, j, k, l;
	int t, n, m, q;
	int in;
	scanf("%d", &t);
	for(cl=0; cl<t; cl++) {
		getchar();
		scanf("%d %d", &m, &n);
		int p[m][n];
		for(i=0; i<m; i++) {
			for(j=0; j<n; j++) {
				scanf("%d", &p[i][j]);
			}
		}
		if(n > m) {
			int alpha = INT_MAX;
			for(i=0; i<n; i++) {
				int val = 0;
				for(j=0; j<m; j++) {
					val = max(val, p[j][i]);
				}
				alpha = min(alpha, val);
			}
			printf("%d\n", alpha);
		} else {
			int answer = 0;
			for(i=0; i<n; i++) {
				for(j=i+1; j<n; j++) {
					int alpha = INT_MAX;
					for(k=0; k<n; k++) {
						if(k == i) {
							int val = 0;
							for(l=0; l<m; l++) {
								val = max(val, min(p[l][i], p[l][j]));
							}
							alpha = min(alpha, val);
						} else if(k != j) {
							int val = 0;
							for(l=0; l<m; l++) {
								val = max(val, p[l][k]);
							}
							alpha = min(alpha, val);
						}
					}
					answer = max(answer, alpha);
				}
			}
			printf("%d\n", answer);
		}
	}
}