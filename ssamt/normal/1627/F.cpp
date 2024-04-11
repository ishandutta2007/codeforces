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

//untested
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
	int cl, ql;
	int i, j, k, l;
	int t, n, m, q;
	int u, v;
	int in;
	scanf("%d", &t);
	for(cl=0; cl<t; cl++) {
		scanf("%d %d", &n, &k);
		int r1, c1, r2, c2;
		WeightGraph wg((k+1)*(k+1)+1);
		auto index = [&](int a, int b) {
			return a*(k+1)+b;
		};
		auto ring = [&](int a, int b) {
			return max(abs(a-k/2), abs(b-k/2));
		};
		auto ring_minus = [&](int a1, int b1, int a2, int b2) {
			return ring(a1, b1)-ring(a2, b2);
		};
		auto add_proper = [&](int a1, int b1, int a2, int b2, int w) {
			wg.add_both(index(a1, b1), index(a2, b2), w);
		};
		auto change_proper = [&](int a1, int b1, int a2, int b2, int w) {
			wg.change_weight_both(index(a1, b1), index(a2, b2), w);
		};
		for(i=0; i<=k; i++) {
			for(j=0; j<k; j++) {
				add_proper(i, j, i, j+1, 0);
			}
		}
		for(i=0; i<k; i++) {
			for(j=0; j<=k; j++) {
				add_proper(i, j, i+1, j, 0);
			}
		}
		for(i=0; i<=k; i++) {
			wg.add(index(0, i), (k+1)*(k+1), 0);
			wg.add(index(k, i), (k+1)*(k+1), 0);
		}
		for(i=0; i<=k; i++) {
			wg.add(index(i, 0), (k+1)*(k+1), 0);
			wg.add(index(i, k), (k+1)*(k+1), 0);
		}
		for(i=0; i<n; i++) {
			scanf("%d %d %d %d", &r1, &c1, &r2, &c2);
			if(r1 == r2+1 || c1 == c2+1) {
				r1--; c1--;
			} else {
				r2--; c2--;
			}
			change_proper(r1, c1, r2, c2, 1);
			change_proper(k-r1, k-c1, k-r2, k-c2, 1);
		}
		vector<long long> dist = wg.dijkstra(index(k/2, k/2));
		printf("%lld\n", n-dist.back());
	}
}