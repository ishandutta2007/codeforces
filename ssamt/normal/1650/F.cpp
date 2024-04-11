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
		vector<vector<int>> f;
		for(i=0; i<n; i++) {
			scanf("%d", &in);
			f.push_back({in, i});
		}
		sort(f.begin(), f.end());
		vector<vector<int>> a[n];
		for(i=0; i<m; i++) {
			int e, time, p;
			scanf("%d %d %d", &e, &time, &p);
			e--;
			a[e].push_back({time, p, i});
		}
		vector<vector<int>> sh;
		int size = 100;
		for(i=0; i<n; i++) {
			int d[a[i].size()+1][size+1];
			int p[a[i].size()+1][size+1];
			d[0][0] = 0;
			p[0][0] = -1;
			for(j=1; j<=size; j++) {
				d[0][j] = -1;
				p[0][j] = -1;
			}
			for(j=1; j<=a[i].size(); j++) {
				for(k=0; k<=size; k++) {
					d[j][k] = d[j-1][k];
					p[j][k] = -1;
				}
				for(k=size; k>=0; k--) {
					if(d[j][k] != -1) {
						int idx = min(100, k+a[i][j-1][1]);
						int val = d[j][k]+a[i][j-1][0];
						if(val <= 1e9 && (d[j][idx] == -1 || val < d[j][idx])) {
							d[j][idx] = val;
							p[j][idx] = k;
							//printf("%d %d %lld\n", j, idx, val);
						}
					}
				}
			}
			if(d[a[i].size()][100] == -1) {
				sh.push_back({-1});
			} else {
				sh.push_back({d[a[i].size()][100]});
				int left = 100;
				for(j=a[i].size(); j>0; j--) {
					if(p[j][left] != -1) {
						sh.back().push_back(a[i][j-1][2]);
						left = p[j][left];
					}
				}
			}
		}
		int check = 1;
		long long time = 0;
		for(i=0; i<n; i++) {
			time += sh[f[i][1]][0];
			if(sh[f[i][1]][0] == -1 || time > f[i][0]) {
				check = 0;
				break;
			}
		}
		if(check) {
			vector<int> answer;
			for(i=0; i<n; i++) {
				for(j=1; j<sh[i].size(); j++) {
					answer.push_back(sh[i][j]);
				}
			}
			printf("%d\n", answer.size());
			for(i=0; i<answer.size(); i++) {
				printf("%d ", answer[i]+1);
			}
			printf("\n");
		} else {
			printf("-1\n");
		}
	}
}