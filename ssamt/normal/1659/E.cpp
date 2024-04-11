#include <bits/stdc++.h>

using namespace std;

class DisjointSet {
	public:
		int n;
		vector<int> p;
		vector<int> h;
		
		DisjointSet(int n) {
			int i;
			this->n = n;
			for(i=0; i<n; i++) {
				p.push_back(i);
				h.push_back(1);
			}
		}
		
		int find(int idx) {
			while(p[idx] != idx) {
				idx = p[idx];
			}
			return idx;
		}
		
		int merge(int u, int v) {
			u = find(u);
			v = find(v);
			if(u == v) {
				return 1;
			} else {
				if(h[u] > h[v]) {
					p[v] = u;
					h[u] = max(h[u], h[v]+1);
				} else {
					p[u] = v;
					h[v] = max(h[v], h[u]+1);
				}
				return 0;
			}
		}
};

int main() {
	int i, j, k, l;
	int t, n, m, q;
	scanf("%d %d", &n, &m);
	vector<vector<int>> a(m, vector<int>(3));
	for(i=0; i<m; i++) {
		for(j=0; j<3; j++) {
			scanf("%d", &a[i][j]);
			if(j != 2) {
				a[i][j]--;
			}
		}
	}
	scanf("%d", &q);
	vector<vector<int>> b(q, vector<int>(2));
	vector<int> answer(q, 2);
	for(i=0; i<q; i++) {
		for(j=0; j<2; j++) {
			scanf("%d", &b[i][j]);
			b[i][j]--;
		}
	}
	for(int d=0; d<30; d++) {
		DisjointSet ds(n);
		for(i=0; i<m; i++) {
			if(a[i][2]&(1<<d)) {
				ds.merge(a[i][0], a[i][1]);
			}
		}
		vector<int> find(n, 0);
		for(i=0; i<m; i++) {
			if(!(a[i][2]&1)) {
				find[ds.find(a[i][0])] = 1;
				find[ds.find(a[i][1])] = 1;
			}
		}
		for(i=0; i<q; i++) {
			if(ds.find(b[i][0]) == ds.find(b[i][1])) {
				answer[i] = 0;
			}
			if(d != 0 && find[ds.find(b[i][0])]) {
				answer[i] = min(answer[i], 1);
			}
		}
	}
	for(i=0; i<q; i++) {
		printf("%d\n", answer[i]);
	}
	
}