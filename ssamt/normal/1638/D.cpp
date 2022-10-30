#include <bits/stdc++.h>

using namespace std;

int main() {
	int cl, ql;
	int i, j, k, l;
	int t, n, m, q;
	int u, v;
	int in;
	scanf("%d %d", &n, &m);
	int a[n][m];
	int vis[n][m] = {};
	for(i=0; i<n; i++) {
		for(j=0; j<m; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	vector<vector<int>> answer;
	queue<vector<int>> pos;
	for(i=0; i<n-1; i++) {
		for(j=0; j<m-1; j++) {
			if(a[i][j] == a[i][j+1] && a[i][j] == a[i+1][j] && a[i][j] == a[i+1][j+1]) {
				answer.push_back({i+1, j+1, a[i][j]});
				pos.push({i, j});
				vis[i][j] = 1;
			}
		}
	}
	while(!pos.empty()) {
		vector<int> node = pos.front();
		pos.pop();
		for(i=0; i<2; i++) {
			for(j=0; j<2; j++) {
				a[node[0]+i][node[1]+j] = 0;
			}
		}
		vector<vector<int>> diff{{-1, -1}, {-1, 0}, {0, -1}, {0, 1}, {1, 0}, {1, 1}};
		for(i=0; i<diff.size(); i++) {
			int x = node[0]-diff[i][0];
			int y = node[1]-diff[i][1];
			if(x < n-1 && x >= 0 && y < m-1 && y >= 0) {
				vector<int> arr;
				if(a[x][y] != 0) {
					arr.push_back(a[x][y]);
				}
				if(a[x+1][y] != 0) {
					arr.push_back(a[x+1][y]);
				}
				if(a[x][y+1] != 0) {
					arr.push_back(a[x][y+1]);
				}
				if(a[x+1][y+1] != 0) {
					arr.push_back(a[x+1][y+1]);
				}
				int check = 1;
				for(k=0; k<arr.size(); k++) {
					for(l=k+1;l<arr.size(); l++) {
						if(arr[k] != arr[l]) {
							check = 0;
						}
					}
				}
				if(check) {
					if(!vis[x][y]) {
						vis[x][y] = 1;
						pos.push({x, y});
						if(arr.size()) {
							answer.push_back({x+1, y+1, arr[0]});
						}
					}
				}
			}
		}
	}
	int check = 1;
	for(i=0; i<n; i++) {
		for(j=0; j<m; j++) {
			if(a[i][j] != 0) {
				check = 0;
			}
		}
	}
	if(check) {
		printf("%d\n", answer.size());
		for(i=answer.size()-1; i>=0; i--) {
			for(j=0; j<answer[i].size(); j++) {
				printf("%d ", answer[i][j]);
			}
			printf("\n");
		}
	} else {
		printf("-1\n");
	}
}