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
	scanf("%d", &t);
	for(int cl=0; cl<t; cl++) {
		scanf("%d", &n);
		vector<vector<int>> a;
		for(i=0; i<n; i++) {
			a.push_back({-1, i});
			scanf("%d", &a[i][0]);
		}
		DisjointSet ds(n);
		vector<int> v(n, 0);
		sort(a.begin(), a.end(), greater<vector<int>>());
		for(int idx=0; idx<n; idx++) {
			int node = a[idx][1];
			if(!v[node]) {
				v[node] = 1;
				for(i=0; i<a[idx][0]; i++) {
					printf("? %d\n", node+1);
					fflush(stdout);
					int in;
					scanf("%d", &in);
					in--;
					ds.merge(node, in);
					if(v[in]) {
						v[in] = 1;
						break;
					} else {
						v[in] = 1;
					}
				}
			}
		}
		printf("! ");
		for(i=0; i<n; i++) {
			printf("%d ", ds.find(i)+1);
		}
		printf("\n");
		fflush(stdout);
	}
}