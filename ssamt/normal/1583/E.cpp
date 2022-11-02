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
#include <map>
#include <functional>

using namespace std;

class AdjGraph {
	public:
		int n;
		std::vector< std::vector<int> > a;

		AdjGraph(int nodes) {
		    int i;
            n = nodes;
            for(i=0; i<n; i++) {
                std::vector<int> e;
                a.push_back(e);
            }
		}

		void add(int i, int j) {
			a[i].push_back(j);
			a[j].push_back(i);
		}
		
		vector<int> path(int u, int v) {
			int i;
			int pred[n] = {};
			int visited[n] = {};
			queue<int> to;
			to.push(u);
			visited[u] = 1;
			while(!to.empty()) {
				int node = to.front();
				to.pop();
				for(int con:a[node]) {
					if(!visited[con]) {
						pred[con] = node;
						if(con == v) {
							vector<int> rev;
							while(v != u) {
								rev.push_back(v);
								v = pred[v];
							}
							rev.push_back(u);
							vector<int> answer;
							for(i=rev.size()-1; i>=0; i--) {
								answer.push_back(rev[i]);
							}
							return answer;
						}
						visited[con] = 1;
						to.push(con);
					}
				}
			}
		}
		
		void print() {
			int i, j;
			for(i=0; i<a.size(); i++) {
				printf("%d: ", i);
				for(j=0; j<a[i].size(); j++) {
					printf("%d ", a[i][j]);
				}
				printf("\n");
			}
		}
};

class AdjTree : public AdjGraph {
	public:
		using AdjGraph::AdjGraph;
		
		void bfs_tree(AdjGraph& g, int r) {
			int visited[n] = {};
			queue<int> to;
			to.push(r);
			visited[r] = 1;
			while(!to.empty()) {
				int node = to.front();
				to.pop();
				for(int con:g.a[node]) {
					if(!visited[con]) {
						add(node, con);
						visited[con] = 1;
						to.push(con);
					}
				}
			}
		}
};

int main() {
	int h, i, j, l;
	int t, n, m, k, q;
	int u, v;
	scanf("%d %d", &n, &m);
	AdjGraph g(n);
	for(i=0; i<m; i++) {
		scanf("%d %d", &u, &v);
		g.add(u-1, v-1);
	}
	/*for(i=0; i<n; i++) {
		for(j=i+1; j<n; j++) {
			printf("%d %d\n", i+1, j+1);
			vector<int> p = g.path(i, j);
			for(k=0; k<p.size(); k++) {
				printf("%d ", p[k]+1);
			}
			printf("\n");
		}
	}*/
	scanf("%d", &q);
	int a[q][2];
	for(i=0; i<q; i++) {
		scanf("%d %d", &a[i][0], &a[i][1]);
		a[i][0]--;
		a[i][1]--;
	}
	int count[n] = {};
	for(i=0; i<q; i++) {
		for(j=0; j<2; j++) {
			count[a[i][j]]++;
		}
	}
	int odd = 0;
	for(i=0; i<n; i++) {
		if(count[i]%2 == 1) {
			odd++;
		}
	}
	if(odd == 0) {
		printf("YES\n");
		AdjTree tree(n);
		tree.bfs_tree(g, 0);
		for(i=0; i<q; i++) {
			vector<int> p = tree.path(a[i][0], a[i][1]);
			printf("%d\n", p.size());
			for(j=0; j<p.size(); j++) {
				printf("%d ", p[j]+1);
			}
			printf("\n");
		}
	} else {
		printf("NO\n");
		printf("%d\n", odd/2);
	}
	
}