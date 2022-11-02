#include <stdio.h>
#include <limits.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <set>
#include <queue>
#include <string>

using namespace std;

int main() {
	int h, i, j, l;
	int t, n, m, k;
	long long mod = 1000000007;
	scanf("%d", &t);
	for(h=0; h<t; h++) {
		scanf("%d %d", &n, &m);
		vector<pair<int, int> > g[n];
		for(i=0; i<m; i++) {
			int a, b;
			char s[10];
			scanf("%d %d %s", &a, &b, s);
			a--;
			b--;
			if(s[0] == 'c') {
				pair<int, int> e{b, 1};
				g[a].push_back(e);
			} else {
				pair<int, int> e{b, 0};
				g[a].push_back(e);
			}
			if(s[0] == 'c') {
				pair<int, int> e{a, 1};
				g[b].push_back(e);
			} else {
				pair<int, int> e{a, 0};
				g[b].push_back(e);
			}
		}
		vector<int> visit;
		int visited[n] = {};
		int color[n];
		int parent[n];
		bool cont = false;
		int answer = 0;
		for(i=0; i<n; i++) {
			if(!visited[i]) {
				int count[2] = {};
				visit.push_back(i);
				visited[i] = 1;
				color[i] = 0;
				count[0]++;
				while(!visit.empty()) {
					int node = visit.back();
					visit.pop_back();
					for(j=0; j<g[node].size(); j++) {
						int con = g[node][j].first;
						if(!visited[con]) {
							visit.push_back(con);
							visited[con] = 1;
							if(g[node][j].second) {
								color[con] = color[node];
							} else {
								color[con] = 1-color[node];
							}
							parent[con] = node;
							count[color[con]]++;
						} else {
							if(g[node][j].second) {
								if(color[con] != color[node]) {
									cont = true;
									goto OUT;
								}
							} else {
								if(color[con] == color[node]) {
									cont = true;
									goto OUT;
								}
							}
						}
					}
				}
				answer += max(count[0], count[1]);
				/*for(j=0; j<n; j++) {
					printf("%d ", color[j]);
				}
				printf("\n");*/
			}
		}
OUT:
		if(cont) {
			printf("-1\n");
		} else {
			printf("%d\n", answer);
		}
	}
}