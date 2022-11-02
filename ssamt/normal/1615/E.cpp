#include <bits/stdc++.h>

using namespace std;

class Graph {
	public:
		int n;
		std::vector<vector<int> > a;

		Graph(int nodes) {
		    int i;
            n = nodes;
            for(i=0; i<n; i++) {
                vector<int> e;
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
			return vector<int>{};
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
				for(int con:a[i]) {
					printf("%d ", con);
				}
				printf("\n");
			}
		}
};

int main() {
	int cl, ql;
	int i, j, k, l;
	int t, n, m, q;
	int in;
	scanf("%d %d", &n, &k);
	Graph g(n);
	for(i=0; i<n-1; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		u--; v--;
		g.add(u, v);
	}
	int parent[n];
	vector<int> bfs;
	int leaf[n];
	for(i=0; i<n; i++) {
		leaf[i] = 1;
	}
	int visited[n] = {};
	queue<int> to;
	to.push(0);
	bfs.push_back(0);
	visited[0] = 1;
	while(!to.empty()) {
		int node = to.front();
		to.pop();
		int s = g.a[node].size();
		/*for(i=0; i<s-1; i++) {
			j = rand()%(s-i-1)+i+1;
			swap(g.a[node][i], g.a[node][j]);
		}*/
		for(int con:g.a[node]) {
			if(!visited[con]) {
				leaf[node] = 0;
				bfs.push_back(con);
				parent[con] = node;
				visited[con] = 1;
				to.push(con);
			}
		}
	}
	int leaf_num = 0;
	for(i=0; i<n; i++) {
		leaf_num += leaf[i];
	}
	if(k > leaf_num) {
		int red = max(leaf_num, min(n/2, k));
		printf("%lld\n", (long long)(n-red)*red);
	} else {
		priority_queue<vector<int>> max_leaf;
		vector<int> max_child[n];
		int red[n] = {};
		for(i=0; i<n; i++) {
			max_child[i] = {1, i};
		}
		for(i=n-1; i>=1; i--) {
			int node = bfs[i];
			vector<int> large = max_child[node];
			if(max_child[parent[node]][0] < max_child[node][0]+1) {
				max_child[parent[node]] = {large[0]+1, large[1]};
			}
		}
		/*for(i=0; i<n; i++) {
			printf("%d %d\n", max_child[i][0], max_child[i][1]);
		}*/
		max_leaf.push(max_child[0]);
		for(i=0; i<k; i++) {
			int take = max_leaf.top()[1];
			//printf("%d\n", take);
			max_leaf.pop();
			while(true) {
				red[take] = 1;
				for(int con:g.a[take]) {
					if(con != parent[take] && !red[con]) {
						max_leaf.push(max_child[con]);
					}
				}
				if(take == 0 || red[parent[take]]) {
					break;
				}
				take = parent[take];
			}
		}
		int blue = n;
		for(i=0; i<n; i++) {
			blue -= red[i];
		}
		if(k < blue) {
			blue = min(blue, n/2);
		}
		printf("%lld\n", (long long)(n-k-blue)*(k-blue));
	}
}