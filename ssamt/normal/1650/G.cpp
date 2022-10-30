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

int mod = 1e9+7;

int main() {
	int cl, ql;
	int i, j, k, l;
	int t, n, m, q;
	int u, v;
	int in;
	scanf("%d", &t);
	for(cl=0; cl<t; cl++) {
		scanf("%d %d", &n, &m);
		int s, e;
		scanf("%d %d", &s, &e);
		s--, e--;
		Graph g(n);
		int u[m][2];
		for(i=0; i<m; i++) {
			scanf("%d %d", &u[i][0], &u[i][1]);
			u[i][0]--, u[i][1]--;
			g.add_both(u[i][0], u[i][1]);
		}
		auto dist = [&](int start) {
			vector<vector<int>> d(n, vector<int>{INT_MAX, 0});
			d[start][0] = 0;
			d[start][1] = 1;
			queue<int> to;
			to.push(start);
			while(!to.empty()) {
				int node = to.front();
				to.pop();
				for(int con:g.a[node]) {
					if(d[node][0]+1 < d[con][0]) {
						d[con][0] = d[node][0]+1;
						d[con][1] = 0;
						to.push(con);
					}
					if(d[con][0] == d[node][0]+1) {
						d[con][1] = (d[con][1]+d[node][1])%mod;
					}
				}
			}
			return d;
		};
		vector<vector<int>> ds = dist(s);
		vector<vector<int>> de = dist(e);
		/*for(i=0; i<n; i++) {
			printf("%d %d\n", ds[i][0], ds[i][1]);
		}
		for(i=0; i<n; i++) {
			printf("%d %d\n", de[i][0], de[i][1]);
		}*/
		int far = ds[e][0];
		long long answer = ds[e][1];
		for(i=0; i<m; i++) {
			if(ds[u[i][0]][0]+de[u[i][1]][0] == far && ds[u[i][0]][0] == ds[u[i][1]][0]) {
				answer = (answer+(long long)ds[u[i][0]][1]*de[u[i][1]][1])%mod;
			}
			if(de[u[i][0]][0]+ds[u[i][1]][0] == far && ds[u[i][0]][0] == ds[u[i][1]][0]) {
				answer = (answer+(long long)de[u[i][0]][1]*ds[u[i][1]][1])%mod;
			}
		}
		printf("%lld\n", answer);
	}
}