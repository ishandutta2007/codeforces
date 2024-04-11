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
		vector<vector<int>> ad[n];
		int x[n-1], y[n-1], v[n-1];
		for(i=0; i<n-1; i++) {
			scanf("%d %d %d", &x[i], &y[i], &v[i]);
			x[i]--; y[i]--;
			int par;
			if(v[i] == -1) {
				par = -1;
			} else {
				par = 0;
				for(j=0; j<30; j++) {
					if(v[i]&(1<<j)) {
						par++;
					}
				}
				par %= 2;
			}
			ad[x[i]].push_back({y[i], par});
			ad[y[i]].push_back({x[i], par});
		}
		int a[m], b[m], p[m];
		for(i=0; i<m; i++) {
			scanf("%d %d %d", &a[i], &b[i], &p[i]);
			a[i]--; b[i]--;
			ad[a[i]].push_back({b[i], p[i]});
			ad[b[i]].push_back({a[i], p[i]});
		}
		int par[n] = {};
		int visited[n] = {1};
		int answer = 1;
		vector<vector<int>> edge;
		queue<int> dq;
		queue<vector<int>> em;
		dq.push(0);
		while(!dq.empty() || !em.empty()) {
			if(!dq.empty()) {
				int node = dq.front();
				dq.pop();
				for(vector<int> con:ad[node]) {
					if(con[1] == -1) {
						if(visited[con[0]]) {
							edge.push_back({node, con[0], par[node]^par[con[0]]});
						} else {
							em.push({node, con[0]});
						}
					} else {
						if(visited[con[0]]) {
							if(par[node]^par[con[0]] != con[1]) {
								answer = 0;
								goto OUT;
							}
						} else {
							par[con[0]] = par[node]^con[1];
							visited[con[0]] = 1;
							dq.push(con[0]);
						}
					}
				}
			} else {
				vector<int> ed = em.front();
				em.pop();
				if(visited[ed[1]]) {
					edge.push_back({ed[0], ed[1], par[ed[0]]^par[ed[1]]});
				} else {
					edge.push_back({ed[0], ed[1], 0});
					par[ed[1]] = par[ed[0]];
					visited[ed[1]] = 1;
					dq.push(ed[1]);
				}
			}
		}
OUT:;
		if(answer) {
			printf("YES\n");
			for(i=0; i<n-1; i++) {
				if(v[i] != -1) {
					printf("%d %d %d\n", x[i]+1, y[i]+1, v[i]);
				}
			}
			for(i=0; i<edge.size(); i++) {
				if(edge[i][0] < edge[i][1]) {
					printf("%d %d %d\n", edge[i][0]+1, edge[i][1]+1, edge[i][2]);
				}
			}
		} else {
			printf("NO\n");
		}
	}
}