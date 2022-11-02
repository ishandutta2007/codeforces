#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <math.h>
#include <vector>

class DirGraph {
	public:
		int n;
		std::vector< std::vector<int> > a;

		DirGraph(int nodes) {
		    int i;
            n = nodes;
            for(i=0; i<n; i++) {
                std::vector<int> e;
                a.push_back(e);
            }
		}

		void add(int i, int j) {
			a[i].push_back(j);
		}
};

int main() {
	int h, i, j;
	int t, n, m;
	int u, v;
	scanf("%d", &t);
	for(h=0; h<t; h++) {
		fgetc(stdin);
		scanf("%d %d", &n, &m);
		DirGraph graph(n);
		for(i=0; i<m; i++) {
			scanf("%d %d", &u, &v);
			graph.add(u-1, v-1);
		}
		int state[n];
		memset(state, 0, sizeof(state));
		state[0] = 1;
		int last[n];
		std::vector<int> visit;
		visit.push_back(0);
		while(visit.size() > 0) {
			int node = visit[visit.size()-1];
			visit.pop_back();
			for(i=0; i<graph.a[node].size(); i++) {
				int to = graph.a[node][i];
				last[to] = node;
				int before = state[to];
				if(state[node] > 0 && state[to] > 0) {
					state[to] = 2;
					for(j=node; j!=0 && j!=to; j=last[j]);
					if(j == to) {
						for(j=node; j!=0 && j!=to; j=last[j]) {
							if(state[j] != -1) {
								state[j] = -1;
								visit.push_back(j);
							}
						}
						state[to] = -1;
					}
				} else {
					switch(state[node]) {
						case 1:
							switch(state[to]) {
								case 0:
									state[to] = 1;
									break;
							}
							break;
						case 2:
							switch(state[to]) {
								case 0:
									state[to] = 2;
									break;
							}
							break;
						case -1:
							state[to] = -1;
							break;
					}
				}
				if(before != state[to]) {
					visit.push_back(to);
				}
			}
		}
		for(i=0; i<n; i++) {
			printf("%d ", state[i]);
		}
		printf("\n");
	}
}