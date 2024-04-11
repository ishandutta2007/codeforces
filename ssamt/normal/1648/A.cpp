#include <bits/stdc++.h>

using namespace std;

int main() {
	int cl, ql;
	int i, j, k, l;
	int t, n, m, q;
	int u, v;
	int in;
	int size = 100000;
	vector<vector<vector<int>>> color(size, vector<vector<int>>{});
	scanf("%d %d", &n, &m);
	for(i=0; i<n; i++) {
		for(j=0; j<m; j++) {
			scanf("%d", &in);
			in--;
			color[in].push_back({i, j});
		}
	}
	long long answer = 0;
	for(i=0; i<size; i++) {
		vector<vector<int>> x(2, vector<int>{});
		for(j=0; j<color[i].size(); j++) {
			for(k=0; k<2; k++) {
				x[k].push_back(color[i][j][k]);
			}
		}
		for(j=0; j<2; j++) {
			sort(x[j].begin(), x[j].end());
			for(k=1; k<x[j].size(); k++) {
				if(x[j][k-1] != x[j][k]) {
					answer += (long long)k*(x[j].size()-k)*(x[j][k]-x[j][k-1]);
				}
			}
		}
	}
	printf("%lld\n", answer);
}