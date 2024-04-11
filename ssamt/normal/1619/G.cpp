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
		
		void merge(int u, int v) {
			u = find(u);
			v = find(v);
			if(h[u] > h[v]) {
				p[v] = u;
				h[u] = max(h[u], h[v]+1);
			} else {
				p[u] = v;
				h[v] = max(h[v], h[u]+1);
			}
		}
};

int main() {
	int cl, ql;
	int i, j, k, l;
	int t, n, m, q;
	int in;
	scanf("%d", &t);
	for(cl=0; cl<t; cl++) {
		getchar();
		scanf("%d %d", &n, &k);
		int a[n][3];
		for(i=0; i<n; i++) {
			for(j=0; j<3; j++) {
				scanf("%d", &a[i][j]);
			}
		}
		DisjointSet ds(n);
		for(l=0; l<2; l++) {
			vector<vector<int>> s;
			for(i=0; i<n; i++) {
				s.push_back({a[i][l], a[i][(l+1)%2], i});
			}
			sort(s.begin(), s.end());
			for(i=0; i<n-1; i++) {
				if(s[i][0] == s[i+1][0] && s[i+1][1]-s[i][1] <= k) {
					ds.merge(s[i][2], s[i+1][2]);
				}
			}
		}
		vector<int> time;
		int min_val[n];
		for(i=0; i<n; i++) {
			min_val[i] = INT_MAX;
		}
		for(i=0; i<n; i++) {
			int idx = ds.find(i);
			min_val[idx] = min(min_val[idx], a[i][2]);
		}
		for(i=0; i<n; i++) {
			if(min_val[i] != INT_MAX) {
				time.push_back(min_val[i]);
			}
		}
		sort(time.begin(), time.end());
		int answer = time.size()-1;
		for(i=0; i<time.size(); i++) {
			answer = min(answer, max(time[i], (int)time.size()-i-2));
		}
		printf("%d\n", answer);
	}
}