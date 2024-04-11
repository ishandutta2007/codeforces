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

int main() {
	int h, i, j, l;
	int t, n, m, k;
	int u, v;
	scanf("%d", &t);
	for(h=0; h<t; h++) {
		scanf("%d %d", &n, &k);
		AdjGraph g(n);
		for(i=0; i<n-1; i++) {
			scanf("%d %d", &u, &v);
			g.add(u-1, v-1);
		}
		int visit[n] = {};
		int edge[n];
		int left = n;
		for(i=0; i<n; i++) {
			edge[i] = g.a[i].size();
		}
		vector<int> to;
		for(i=0; i<n; i++) {
			if(edge[i] <= 1) {
				to.push_back(i);
				visit[i] = 1;
			}
		}
		vector<int> next;
		for(i=0; i<k && left>0; i++) {
			for(int node:to) {
				for(int con:g.a[node]) {
					edge[con]--;
					if(!visit[con] && edge[con] <= 1) {
						next.push_back(con);
						visit[con] = 1;
					}
				}
				left--;
			}
			to.clear();
			for(int node:next) {
				to.push_back(node);
			}
			next.clear();
		}
		printf("%d\n", left);
	}
}