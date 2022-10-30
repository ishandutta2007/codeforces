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
	int i, j, k, l;
	int t, n, m, q;
	cin >> t;
	for(int cl=0; cl<t; cl++) {
		cin >> n >> m;
		vector<vector<int>> a(n, vector<int>(m, 0));
		for(i=0; i<n; i++) {
			string s;
			cin >> s;
			for(j=0; j<m; j++) {
				if(s[j] == '*') {
					a[i][j] = 1;
				}
			}
		}
		Graph g(n*m);
		for(i=0; i<n; i++) {
			for(j=0; j<m; j++) {
				for(int x=-1; x<=1; x++) {
					for(int y=-1; y<=1; y++) {
						if(!(x==0 && y==0) && 0<=i+x && i+x<n && 0<=j+y && j+y<m) {
							if(a[i][j] && a[i+x][j+y]) {
								g.add_both(i*m+j, (i+x)*m+j+y);
							}
						}
					}
				}
			}
		}
		vector<vector<int>> c = g.components();
		int check = 1;
		for(i=0; i<c.size(); i++) {
			if(c[i].size() == 1) {
				int num = c[i][0];
				if(a[num/m][num%m]) {
					check = 0;
					break;
				}
				continue;
			}
			if(c[i].size() != 3) {
				check = 0;
				break;
			}
			if(!(g.a[c[i][0]].count(c[i][1]) && g.a[c[i][1]].count(c[i][2]) && g.a[c[i][2]].count(c[i][0]))) {
				check = 0;
				break;
			}
		}
		cout << (check?"YES":"NO") << endl;
	}
}