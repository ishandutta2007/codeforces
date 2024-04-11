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

		void add_both(int i, int j) {
			add(i, j);
			add(j, i);
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
		
		vector<int> d;
		vector<int> p;
		
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
		
		void cal_vars() {
			int i;
			for(i=0; i<n; i++) {
				d.push_back(0);
				p.push_back(0);
			}
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
						p[con] = node;
						visited[con] = 1;
						to.push(con);
					}
				}
			}
		}
};

int main() {
	int i, j, k, l;
	int t, n, m, q;
	cin >> n >> q;
	Tree tr(n);
	for(i=0; i<n-1; i++) {
		int u, v;
		cin >> u >> v;
		u--; v--;
		tr.add_both(u, v);
	}
	tr.cal_vars();
	vector<int> cover(n, 0);
	vector<vector<vector<vector<int>>>> a(n, vector<vector<vector<int>>>(26));
	vector<vector<int>> path(q);
	vector<string> s(q);
	for(i=0; i<q; i++) {
		int u, v;
		cin >> u >> v >> s[i];
		u--; v--;
		vector<int> pathu, pathv;
		while(u != v) {
			if(tr.d[u] < tr.d[v]) {
				pathv.push_back(v);
				v = tr.p[v];
			} else {
				pathu.push_back(u);
				u = tr.p[u];
			}
		}
		for(j=0; j<pathu.size(); j++) {
			path[i].push_back(pathu[j]);
		}
		path[i].push_back(u);
		for(j=(int)pathv.size()-1; j>=0; j--) {
			path[i].push_back(pathv[j]);
		}
		for(j=0; j<path[i].size(); j++) {
			cover[path[i][j]]++;
		}
		for(j=0; j<path[i].size(); j++) {
			a[path[i][j]][s[i][j]-'a'].push_back({i, 0});
		}
		for(j=0; j<path[i].size(); j++) {
			a[path[i][j]][s[i][path[i].size()-1-j]-'a'].push_back({i, 1});
		}
	}
	int check = 1;
	vector<vector<int>> poss(n);
	for(i=0; i<n; i++) {
		for(j=0; j<26; j++) {
			set<int> all;
			for(auto pair:a[i][j]) {
				all.insert(pair[0]);
			}
			if(all.size() == cover[i]) {
				poss[i].push_back(j);
			}
		}
		if(poss[i].empty()) {
			check = 0;
		}
	}
	if(!check) {
		cout << "NO" << endl;
		return 0;
	}
	vector<int> let(n, -1);
	vector<int> dir(q, -1);
	int idx = 0;
	queue<vector<int>> to;
	for(i=0; i<n; i++) {
		if(poss[i].size() == 1) {
			let[i] = 0;
			to.push({i, 0});
		}
	}
	while(idx < n) {
		while(!to.empty()) {
			vector<int> node = to.front();
			to.pop();
			int num = node[0];
			int code = node[1];
			if(code == 0) {
				vector<vector<int>>& pairs = a[num][poss[num][let[num]]];
				for(i=0; i<pairs.size(); i++) {
					if((i == 0 || pairs[i-1][0] != pairs[i][0]) && (i == pairs.size()-1 || pairs[i][0] != pairs[i+1][0])) {
						if(dir[pairs[i][0]] == -1) {
							dir[pairs[i][0]] = pairs[i][1];
							to.push({pairs[i][0], 1});
						} else if(dir[pairs[i][0]] != pairs[i][1]) {
							cout << "NO" << endl;
							return 0;
						}
					}
				}
			} else {
				for(i=0; i<path[num].size(); i++) {
					int target = dir[num]?s[num][s[num].size()-1-i]:s[num][i];
					target -= 'a';
					int node = path[num][i];
					if(let[node] == -1) {
						if(poss[node][0] == target) {
							let[node] = 0;
						} else {
							let[node] = 1;
						}
						to.push({node, 0});
					} else if(poss[node][let[node]] != target) {
						cout << "NO" << endl;
						return 0;
					}
				}
			}
		}
		while(idx < n && let[idx] != -1) {
			idx++;
		}
		if(idx < n) {
			let[idx] = 0;
			to.push({idx, 0});
		}
	}
	cout << "YES" << endl;
	for(i=0; i<n; i++) {
		if(poss[i].size() == 26) {
			cout << 'a';
		} else {
			cout << static_cast<char>(poss[i][let[i]]+'a');
		}
	}
	cout << endl;
}