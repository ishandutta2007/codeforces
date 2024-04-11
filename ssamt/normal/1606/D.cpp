#include <bits/stdc++.h>

using namespace std;

int main() {
	int cl, ql;
	int i, j, k;
	int t, n, m, q;
	int in;
	scanf("%d", &t);
	for(cl=0; cl<t; cl++) {
		scanf("%d %d", &n, &m);
		vector<vector<int>> a;
		for(i=0; i<n; i++) {
			a.push_back({});
			for(j=0; j<m; j++) {
				scanf("%d", &in);
				a[i].push_back(in);
			}
			a[i].push_back(i);
		}
		sort(a.begin(), a.end());
		int min_top[n][m];
		for(i=0; i<n; i++) {
			for(j=m-1; j>=0; j--){
				min_top[i][j] = a[i][j];
				if(i != 0) {
					min_top[i][j] = min(min_top[i][j], min_top[i-1][j]);
				}
				if(j != m-1) {
					min_top[i][j] = min(min_top[i][j], min_top[i][j+1]);
				}
			}
		}
		int min_bottom[n][m];
		for(i=n-1; i>=0; i--) {
			for(j=0; j<m; j++){
				min_bottom[i][j] = a[i][j];
				if(i != n-1) {
					min_bottom[i][j] = min(min_bottom[i][j], min_bottom[i+1][j]);
				}
				if(j != 0) {
					min_bottom[i][j] = min(min_bottom[i][j], min_bottom[i][j-1]);
				}
			}
		}
		int max_top[n][m];
		for(i=0; i<n; i++) {
			for(j=0; j<m; j++){
				max_top[i][j] = a[i][j];
				if(i != 0) {
					max_top[i][j] = max(max_top[i][j], max_top[i-1][j]);
				}
				if(j != 0) {
					max_top[i][j] = max(max_top[i][j], max_top[i][j-1]);
				}
			}
		}
		int max_bottom[n][m];
		for(i=n-1; i>=0; i--) {
			for(j=m-1; j>=0; j--){
				max_bottom[i][j] = a[i][j];
				if(i != n-1) {
					max_bottom[i][j] = max(max_bottom[i][j], max_bottom[i+1][j]);
				}
				if(j != m-1) {
					max_bottom[i][j] = max(max_bottom[i][j], max_bottom[i][j+1]);
				}
			}
		}
		/*for(i=0; i<n; i++) {
			for(j=0; j<m; j++) {
				printf("%d ", a[i][j]);
			}
			printf("\n");
		}
		for(i=0; i<n; i++) {
			for(j=0; j<m; j++) {
				printf("%d ", min_top[i][j]);
			}
			printf("\n");
		}
		for(i=0; i<n; i++) {
			for(j=0; j<m; j++) {
				printf("%d ", min_bottom[i][j]);
			}
			printf("\n");
		}
		for(i=0; i<n; i++) {
			for(j=0; j<m; j++) {
				printf("%d ", max_top[i][j]);
			}
			printf("\n");
		}
		for(i=0; i<n; i++) {
			for(j=0; j<m; j++) {
				printf("%d ", max_bottom[i][j]);
			}
			printf("\n");
		}*/
		int found = 0;
		for(i=0; i<n-1; i++) {
			for(j=0; j<m-1; j++) {
				if(max_top[i][j] < min_bottom[i+1][j] && min_top[i][j+1] > max_bottom[i+1][j+1]) {
					printf("YES\n");
					char s[n+1];
					for(k=0; k<n; k++) {
						if(k <= i) {
							s[a[k][m]] = 'B';
						} else {
							s[a[k][m]] = 'R';
						}
					}
					s[n] = '\0';
					printf("%s %d\n", s, j+1);
					found = 1;
					goto OUT;
				}
			}
		}
OUT:;
		if(!found) {
			printf("NO\n");
		}
	}
}