#include <stdio.h>
#include <limits.h>
#include <time.h>
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
		
		vector<vector<int> > components() {
			int i;
			int visited[n] = {};
			queue<int> to;
			vector<vector<int> > answer;
			for(i=0; i<n; i++) {
				if(!visited[i]) {
					vector<int> e;
					visited[i] = 1;
					to.push(i);
					e.push_back(i);
					while(!to.empty()) {
						int node = to.front();
						to.pop();
						for(int con:a[node]) {
							if(!visited[con]) {
								visited[con] = 1;
								to.push(con);
								e.push_back(con);
							}
						}
					}
					answer.push_back(e);
				}
			}
			return answer;
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
		
		vector<int> depth() {
			vector<int> d(n, 0);
			int visited[n] = {};
			queue<int> to;
			to.push(0);
			visited[0] = 1;
			while(!to.empty()) {
				int node = to.front();
				to.pop();
				for(int con:a[node]) {
					if(!visited[con]) {
						d[con] = d[node]+1;
						visited[con] = 1;
						to.push(con);
					}
				}
			}
			return d;
		}
};

int main() {
	int h, i, j;
	int t, n, m, q;
	scanf("%d", &n);
	AdjTree g(n);
	int e[n-1][2];
	for(i=0; i<n-1; i++) {
		scanf("%d %d", &e[i][0], &e[i][1]);
		e[i][0]--;
		e[i][1]--;
		g.add(e[i][0], e[i][1]);
	}
	vector<int> depth = g.depth();
	vector<vector<int>> edge;
	for(i=0; i<n-1; i++) {
		edge.push_back(vector<int>{min(depth[e[i][0]], depth[e[i][1]]), e[i][0], e[i][1]});
	}
	sort(edge.begin(), edge.end());
	printf("? %d ", n);
	for(i=0; i<n; i++) {
		printf("%d ", i+1);
	}
	printf("\n");
	fflush(stdout);
	int all;
	scanf("%d", &all);
	int start = 0;
	int end = n-1;
	while(start+1 < end) {
		int mid = (start+end)/2;
		int check[n] = {};
		for(i=start; i<mid; i++) {
			check[edge[i][1]] = 1;
			check[edge[i][2]] = 1;
		}
		printf("? ");
		int count = 0;
		for(i=0; i<n; i++) {
			if(check[i]) {
				count++;
			}
		}
		printf("%d ", count);
		for(i=0; i<n; i++) {
			if(check[i]) {
				printf("%d ", i+1);
			}
		}
		printf("\n");
		fflush(stdout);
		int gcd;
		scanf("%d", &gcd);
		if(gcd == all) {
			end = mid;
		} else {
			start = mid;
		}
	}
	printf("! %d %d\n", edge[start][1]+1, edge[start][2]+1);
	fflush(stdout);
}