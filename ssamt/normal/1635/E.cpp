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
		}

		void del(int i, int j) {
			a[i].erase(j);
		}

		void add_both(int i, int j) {
			add(i, j);
			add(j, i);
		}

		void del_both(int i, int j) {
			del(i, j);
			del(j, i);
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
	int u, v;
	int in;
	scanf("%d %d", &n, &m);
	vector<vector<int>> info;
	Graph bi(n);
	for(i=0; i<m; i++) {
		int tp;
		scanf("%d %d %d", &tp, &u, &v);
		tp--; u--; v--;
		bi.add_both(u, v);
		info.push_back({tp, u, v});
	}
	int dir[n];
	for(i=0; i<n; i++) {
		dir[i] = -1;
	}
	int check = 1;
	int start = 0;
	int visited[n] = {};
	while(start < n) {
		queue<int> to;
		to.push(start);
		visited[start] = 1;
		dir[start] = 0;
		while(!to.empty()) {
			int node = to.front();
			to.pop();
			for(int con:bi.a[node]) {
				if(dir[con] == dir[node]) {
					check = 0;
					goto OUT;
				}
				if(!visited[con]) {
					visited[con] = 1;
					to.push(con);
					dir[con] = 1-dir[node];
				}
			}
		}
		while(start < n && visited[start]) {
			start++;
		}
	}
OUT:;
	if(check) {
		Graph g(n);
		for(i=0; i<m; i++) {
			if(!(dir[info[i][1]]^info[i][0])) {
				g.add(info[i][1], info[i][2]);
			} else {
				g.add(info[i][2], info[i][1]);
			}
		}
		int loc[n];
		int in[n] = {};
		for(i=0; i<n; i++) {
			for(int con:g.a[i]) {
				in[con]++;
			}
		}
		int idx = 0;
		for(i=0; i<n; i++) {
			visited[i] = 0;
			loc[i] = -1;
		}
		queue<int> to;
		for(i=0; i<n; i++) {
			if(in[i] == 0) {
				loc[i] = idx;
				idx++;
				to.push(i);
				visited[i] = 1;
			}
		}
		while(!to.empty()) {
			int node = to.front();
			to.pop();
			for(int con:g.a[node]) {
				if(!visited[con]) {
					in[con]--;
					if(in[con] == 0) {
						loc[con] = idx;
						idx++;
						visited[con] = 1;
						to.push(con);
					}
				}
			}
		}
OUT2:;
		check = 1;
		for(i=0; i<n; i++) {
			if(loc[i] == -1) {
				check = 0;
			}
		}
		if(check) {
			printf("YES\n");
			for(i=0; i<n; i++) {
				printf(dir[i]?"R":"L");
				printf(" %d\n", loc[i]);
			}
		}
	}
	if(!check) {
		printf("NO\n");
	}
}