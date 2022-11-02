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
	scanf("%d", &t);
	for(int cl=0; cl<t; cl++) {
		scanf("%d", &n);
		string s;
		cin >> s;
		int count = 0;
		int check = 1;
		for(i=n-1; i>=0; i--) {
			if(s[i] == 'Q') {
				count++;
			} else {
				count--;
			}
			if(count > 0) {
				check = 0;
				break;
			}
		}
		if(s[0] == 'A' || !check) {
			printf("No\n");
		} else {
			printf("Yes\n");
		}
	}
}