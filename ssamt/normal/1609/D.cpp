#include <bits/stdc++.h>

using namespace std;

class DisjointSet {
	public:
		int n;
		vector<int> p; //point
		vector<int> h; //height
		vector<int> w; //weight
		
		DisjointSet(int n) {
			int i;
			this->n = n;
			for(i=0; i<n; i++) {
				p.push_back(i);
				h.push_back(1);
				w.push_back(1);
			}
		}
		
		int find(int idx) {
			while(p[idx] != idx) {
				idx = p[idx];
			}
			return idx;
		}
		
		void merge(int u, int v) {
			u = find(u);
			v = find(v);
			if(h[u] > h[v]) {
				p[v] = u;
				h[u] = max(h[u], h[v]+1);
				w[u] += w[v];
			} else {
				p[u] = v;
				h[v] = max(h[v], h[u]+1);
				w[v] += w[u];
			}
		}
		
		int height(int u) {
			return h[find(u)];
		}
		
		int weight(int u) {
			return w[find(u)];
		}
};

int main() {
	int cl, ql;
	int i, j, k, l;
	int t, n, m, q;
	int in;
	int d;
	scanf("%d %d", &n, &d);
	DisjointSet ds(n);
	int max_h = 1;
	int rest = 0;
	for(ql=0; ql<d; ql++) {
		int u, v;
		scanf("%d %d", &u, &v);
		u--; v--;
		if(ds.find(u) == ds.find(v)) {
			rest++;
		} else {
			ds.merge(u, v);
		}
		vector<int> wc;
		for(i=0; i<n; i++) {
			if(ds.p[i] == i) {
				wc.push_back(ds.w[i]);
			}
		}
		sort(wc.begin(), wc.end());
		int answer = 0;
		for(i=0; i<=rest; i++) {
			answer += wc[wc.size()-i-1];
		}
		answer--;
		printf("%d\n", answer);
	}
}