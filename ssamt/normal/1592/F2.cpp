#include <stdio.h>
#include <limits.h>
#include <time.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <cmath>
#include <set>
#include <queue>
#include <string>
#include <map>
#include <functional>

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

class DirGraph : public Graph {
	public:
		using Graph::Graph;
		
		void add(int i, int j) {
			a[i].insert(j);
		}

		void del(int i, int j) {
			a[i].erase(j);
		}
};

class Bipartite : public Graph {
	public:
		vector<bool> s;
		
		Bipartite(vector<bool> s) : Graph(s.size()) {
            this->s = s;
		}
		
		vector<vector<int>> max_match() {
			int i;
			DirGraph dg(n+2);
			for(i=0; i<n; i++) {
				if(s[i]) {
					for(int con:a[i]) {
						dg.add(i, con);
					}
					dg.add(n, i);
				} else {
					dg.add(i, n+1);
				}
			}
			vector<int> path;
			while(true) {
				path = dg.path(n, n+1);
				if(path.size() == 0) {
					break;
				}
				dg.del(path[0], path[1]);
				for(i=1; i<path.size()-2; i++) {
					dg.del(path[i], path[i+1]);
					dg.add(path[i+1], path[i]);
				}
				dg.del(path[path.size()-2], path.back());
			}
			vector<vector<int>> pairs;
			for(i=0; i<n; i++) {
				if(!s[i]) {
					for(int con:dg.a[i]) {
						if(con < n) {
							pairs.push_back(vector<int>{con, i});
						}
					}
				}
			}
			return pairs;
		}
};

int main() {
	int i, j, k;
	int t, n, m, q;
	scanf("%d %d", &n, &m);
	char s[n][m];
	for(i=0; i<n; i++) {
		scanf("%s", s[i]);
	}
	int a[n][m];
	for(i=0; i<n; i++) {
		for(j=0; j<m; j++) {
			if(s[i][j] == 'W') {
				a[i][j] = 0;
			} else {
				a[i][j] = 1;
			}
		}
	}
	int acc[m] = {};
	int flip[n][m];
	for(i=n-1; i>=0; i--) {
		int sum = 0;
		for(j=m-1; j>=0; j--) {
			flip[i][j] = (acc[j]+sum+a[i][j])%2;
			sum += flip[i][j];
			acc[j] += sum;
		}
	}
	/*for(i=0; i<n; i++) {
		for(j=0; j<m; j++) {
			printf("%d", flip[i][j]);
		}
		printf("\n");
	}*/
	int h = 0, w = 0;
	vector<int> x, y;
	for(i=0; i<n-1; i++) {
		if(flip[i][m-1]) {
			y.push_back(i);
			h++;
		}
	}
	for(i=0; i<m-1; i++) {
		if(flip[n-1][i]) {
			x.push_back(i);
			w++;
		}
	}
	int b[h][w];
	for(i=0; i<h; i++) {
		for(j=0; j<w; j++) {
			b[i][j] = flip[y[i]][x[j]];
		}
	}
	/*for(i=0; i<h; i++) {
		for(j=0; j<w; j++) {
			printf("%d", b[i][j]);
		}
		printf("\n");
	}*/
	vector<bool> set;
	for(i=0; i<h; i++) {
		set.push_back(true);
	}
	for(i=0; i<w; i++) {
		set.push_back(false);
	}
	Bipartite bg(set);
	for(i=0; i<h; i++) {
		for(j=0; j<w; j++) {
			if(b[i][j]) {
				bg.add(i, h+j);
			}
		}
	}
	vector<vector<int>> match = bg.max_match();
	/*for(i=0; i<match.size(); i++) {
		printf("%d", match[i][0]);
		printf("%d", match[i][1]-h);
		printf("\n");
	}*/
	int answer = 0;
	flip[n-1][m-1] = (flip[n-1][m-1]+match.size())%2;
	for(i=0; i<n; i++) {
		for(j=0; j<m; j++) {
			answer += flip[i][j];
		}
	}
	answer -= match.size();
	printf("%d\n", answer);
}