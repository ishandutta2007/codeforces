#include <bits/stdc++.h>

using namespace std;

int main() {
	int cl, ql;
	int i, j, k, l;
	int t, n, m, q;
	int in;
	scanf("%d", &t);
	for(cl=0; cl<t; cl++) {
		scanf("%d %d", &n, &m);
		int x[n];
		for(i=0; i<n; i++) {
			scanf("%d", &x[i]);
		}
		char s[n][m+1];
		for(i=0; i<n; i++) {
			scanf("%s", s[i]);
		}
		int a[n][m];
		for(i=0; i<n; i++) {
			for(j=0; j<m; j++) {
				a[i][j] = s[i][j]-'0';
			}
		}
		int answer = -1;
		int answerp[m];
		for(int b=0; b<(1<<n); b++) {
			int sum[m] = {};
			for(i=0; i<n; i++) {
				if(b&(1<<i)) {
					for(j=0; j<m; j++) {
						sum[j] += a[i][j];
					}
				} else {
					for(j=0; j<m; j++) {
						sum[j] -= a[i][j];
					}
				}
			}
			vector<int> count[2*n+1];
			for(i=0; i<m; i++) {
				count[sum[i]+n].push_back(i);
			}
			int p[m];
			int idx = 1;
			for(i=0; i<=2*n; i++) {
				for(j=0; j<count[i].size(); j++) {
					p[count[i][j]] = idx;
					idx++;
				}
			}
			int val[n] = {};
			for(i=0; i<n; i++) {
				for(j=0; j<m; j++) {
					if(a[i][j]) {
						val[i] += p[j];
					}
				}
			}
			int sur = 0;
			for(i=0; i<n; i++) {
				sur += abs(x[i]-val[i]);
			}
			if(sur > answer) {
				answer = sur;
				for(i=0; i<m; i++) {
					answerp[i] = p[i];
				}
			}
		}
		for(i=0; i<m; i++) {
			printf("%d ", answerp[i]);
		}
		printf("\n");
	}
}