#include <bits/stdc++.h>

using namespace std;

class Graph {
	public:
		int n;
		std::vector<set<int> > a;

		Graph(int nodes) {
		    int i;
            n = nodes;
            for(i=0; i<n; i++) {
                set<int> e;
                a.push_back(e);
            }
		}

		void add(int i, int j) {
			a[i].insert(j);
			a[j].insert(i);
		}

		void del(int i, int j) {
			a[i].erase(j);
			a[j].erase(i);
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

class Tree : public Graph {
	public:
		using Graph::Graph;
		
		void bfs_tree(Graph& g, int r) {
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
		
		vector<int> depth(vector<int>& start) {
			vector<int> d(n, 0);
			int visited[n] = {};
			queue<int> to;
			for(int i:start) {
				to.push(i);
				visited[i] = 1;
			}
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
	int cl, ql;
	int i, j, k, l;
	int t, n, m, q;
	int in;
	scanf("%d", &t);
	for(cl=0; cl<t; cl++) {
		getchar();
		scanf("%d %d", &n, &k);
		Tree tree(n);
		vector<int> x;
		for(i=0; i<k; i++) {
			scanf("%d", &in);
			x.push_back(in-1);
		}
		for(i=0; i<n-1; i++) {
			int u, v;
			scanf("%d %d", &u, &v);
			u--; v--;
			tree.add(u, v);
		}
		vector<int> zero{0};
		vector<int> d1 = tree.depth(zero);
		vector<int> d2 = tree.depth(x);
		int win = 0;
		for(i=1; i<n; i++) {
			//printf("%d %d\n", d1[i], d2[i]);
			if(tree.a[i].size() == 1 && d1[i] < d2[i]) {
				win = 1;
			}
		}
		if(win) {
			printf("-1\n");
		} else {
			int answer = 0;
			int visited[n] = {};
			queue<int> to;
			to.push(0);
			visited[0] = 1;
			while(!to.empty()) {
				int node = to.front();
				to.pop();
				if(d1[node] < d2[node]) {
					for(int con:tree.a[node]) {
						if(!visited[con]) {
							visited[con] = 1;
							to.push(con);
						}
					}
				} else {
					answer++;
				}
			}
			printf("%d\n", answer);
		}
	}
}