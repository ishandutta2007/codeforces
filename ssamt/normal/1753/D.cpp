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

class WeightGraph : public Graph {
	public:
		vector<map<int, int>> w;
		
		WeightGraph(int nodes) : Graph(nodes) {
			int i;
			for(i=0; i<nodes; i++) {
				w.push_back(map<int, int>{});
			}
		}
	
		void add(int i, int j, int w) {
			Graph::add(i, j);
			this->w[i][j] = w;
		}
	
		void del(int i, int j, int w) {
			Graph::del(i, j);
			this->w[i].erase(j);
		}
		
		void change_weight(int i, int j, int dw) {
			this->w[i][j] += dw;
		}
	
		void add_both(int i, int j, int w) {
			add(i, j, w);
			add(j, i, w);
		}
	
		void del_both(int i, int j, int w) {
			del(i, j, w);
			del(j, i, w);
		}
		
		void change_weight_both(int i, int j, int dw) {
			change_weight(i, j, dw);
			change_weight(j, i, dw);
		}
		
		vector<long long> dijkstra(int u) {
			int i;
			int visited[n] = {};
			vector<long long> dist(n, LLONG_MAX);
			dist[u] = 0;
			priority_queue<vector<long long>, vector<vector<long long>>, greater<vector<long long>>> to;
			to.push({0, u});
			while(!to.empty()) {
				int node = to.top()[1];
				to.pop();
				if(!visited[node]) {
					for(int con:a[node]) {
						if(!visited[con] && dist[node]+w[node][con] < dist[con]) {
							dist[con] = dist[node]+w[node][con];
							to.push({dist[con], con});
						}
					}
				}
				visited[node] = 1;
			}
			return dist;
		}
};

int main() {
	int i, j, k, l;
	int t, n, m, q;
	scanf("%d %d", &n, &m);
	int p;
	scanf("%d %d", &p, &q);
	WeightGraph g(n*m+2);
	vector<string> a(n);
	for(i=0; i<n; i++) {
		cin >> a[i];
	}
	for(i=0; i<n; i++) {
		for(j=0; j<m; j++) {
			vector<vector<int>> ad;
			if(a[i][j] == 'L') {
				ad = {{i, j+2}, {i+1, j+1}, {i-1, j+1}};
			} else if(a[i][j] == 'R') {
				ad = {{i, j-2}, {i+1, j-1}, {i-1, j-1}};
			} else if(a[i][j] == 'U') {
				ad = {{i+2, j}, {i+1, j+1}, {i+1, j-1}};
			} else if(a[i][j] == 'D') {
				ad = {{i-2, j}, {i-1, j+1}, {i-1, j-1}};
			}
			for(int k=0; k<ad.size(); k++) {
				int x = ad[k][0], y = ad[k][1];
				if(0<=x && x<n && 0<=y && y<m && a[x][y] != '#') {
					g.add(x*m+y, i*m+j, k==0?q:p);
				}
			}
		}
	}
	//g.print();
	auto get_depth = [&](int par) {
		for(i=0; i<n; i++) {
			for(j=0; j<m; j++) {
				if((i+j)%2 == par && a[i][j] == '.') {
					g.add(n*m+par, i*m+j, 0);
				}
			}
		}
		return g.dijkstra(n*m+par);
	};
	long long answer = LLONG_MAX;
	vector<long long> d0 = get_depth(0);
	vector<long long> d1 = get_depth(1);
	for(i=0; i<n; i++) {
		for(j=0; j<m; j++) {
			if((i+j)%2 == 0) {
				int code = i*m+j;
				vector<vector<int>> ad{{i-1, j}, {i+1, j}, {i, j-1}, {i, j+1}};
				for(vector<int> pos:ad) {
					int x = pos[0], y = pos[1];
					if(0<=x && x<n && 0<=y && y<m) {
						int num = x*m+y;
						if(d0[code] != LLONG_MAX && d1[num] != LLONG_MAX) {
							answer = min(answer, d0[code]+d1[num]);
						}
					}
				}
			}
		}
	}
	if(answer == LLONG_MAX) {
		printf("-1\n");
	} else {
		printf("%lld\n", answer);
	}
}