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
		vector<vector<int>> answer;
		if(s[0][0] == '1') {
			printf("-1\n");
		} else {
			for(i=n-1; i>=0; i--) {
				for(j=m-1; j>=0; j--) {
					if(s[i][j] == '1') {
						if(j == 0) {
							answer.push_back({i-1, j, i, j});
						} else {
							answer.push_back({i, j-1, i, j});
						}
					}
				}
			}
			printf("%d\n", answer.size());
			for(i=0; i<answer.size(); i++) {
				for(j=0; j<answer[i].size(); j++) {
					printf("%d ", answer[i][j]+1);
				}
				printf("\n");
			}
		}
	}
}