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
		bool answer;
		scanf("%d %d", &n, &k);
		int a[n];
		for(i=0; i<n; i++) {
			scanf("%d", &a[i]);
		}
		AdjGraph g(n);
		for(i=0; i<n-1; i++) {
			scanf("%d %d", &u, &v);
			g.add(u-1, v-1);
		}
		int p = 0;
		for(i=0; i<n; i++) {
			p ^= a[i];
		}
		if(p == 0) {
			answer = true;
		} else {
			int comp = 0;
			queue<int> q;
			bool checked[n];
			int count[n];
			for(i=0; i<n; i++) {
				if(g.a[i].size() == 1) {
					q.push(i);
				}
				checked[i] = false;
				count[i] = g.a[i].size();
			}
			while(!q.empty()) {
				int node = q.front();
				q.pop();
				for(i=0; i<g.a[node].size(); i++) {
					int con = g.a[node][i];
						//printf("%d %d ", node, con);
					if(!checked[con]) {
						count[con]--;
						if(count[con] == 1) {
							q.push(con);
						}
						if(a[node] != p) {
							a[con] ^= a[node];
						} else {
							comp++;
						}
					}
				}
				checked[node] = true;
			}
			//printf("\n");
			if(comp%2 == 0) {
				comp++;
			}
			answer = (3 <= comp && 3 <= k);
			//printf("comp: %d\n", comp);
		}
		if(answer) {
			printf("YES\n");
		} else {
			printf("NO\n");
		}
	}
}