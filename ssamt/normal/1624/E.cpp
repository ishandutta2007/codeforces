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
		char f[n][m+1];
		char s[m+1];
		for(i=0; i<n; i++) {
			scanf("%s", f[i]);
		}
		scanf("%s", s);
		vector<int> two[10][10];
		vector<int> three[10][10][10];
		for(i=0; i<n; i++) {
			for(j=0; j<m-1; j++) {
				two[f[i][j]-'0'][f[i][j+1]-'0'] = {i, j};
			}
			for(j=0; j<m-2; j++) {
				three[f[i][j]-'0'][f[i][j+1]-'0'][f[i][j+2]-'0'] = {i, j};
			}
		}
		vector<int> d[m+1];
		d[0] = {0, 0};
		for(i=1; i<=m; i++) {
			if(i >= 2 && !d[i-2].empty()) {
				vector<int> tar = two[s[i-2]-'0'][s[i-1]-'0'];
				if(!tar.empty()) {
					d[i] = tar;
					d[i].push_back(2);
				}
			}
			if(i >= 3 && !d[i-3].empty()) {
				vector<int> tar = three[s[i-3]-'0'][s[i-2]-'0'][s[i-1]-'0'];
				if(!tar.empty()) {
					d[i] = tar;
					d[i].push_back(3);
				}
			}
		}
		/*for(i=0; i<=m; i++) {
			printf("%d: ", i);
			for(j=0; j<d[i].size(); j++) {
				printf("%d ", d[i][j]);
			}
			printf("\n");
		}*/
		if(d[m].empty()) {
			printf("-1\n");
		} else {
			vector<vector<int>> answer;
			int idx = m;
			while(idx > 0) {
				answer.push_back({d[idx][1]+1, d[idx][1]+d[idx][2], d[idx][0]+1});
				idx -= d[idx][2];
			}
			printf("%d\n", answer.size());
			for(i=answer.size()-1; i>=0; i--) {
				for(j=0; j<3; j++) {
					printf("%d ", answer[i][j]);
				}
				printf("\n");
			}
		}
	}
}