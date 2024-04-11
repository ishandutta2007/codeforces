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
	int cl, ql;
	int i, j, k, l;
	int t, n, m, q;
	int u, v;
	int in;
	scanf("%d %d", &n, &m);
	vector<vector<int>> edge;
	int w;
	for(i=0; i<m; i++) {
		scanf("%d %d %d", &u, &v, &w);
		u--; v--;
		edge.push_back({w, u, v});
	}
	sort(edge.begin(), edge.end(), greater<vector<int>>());
	vector<int> cut{0};
	for(i=0; i<m; i++) {
		cut.push_back(edge[i][0]);
		for(j=i+1; j<m; j++) {
			cut.push_back((edge[i][0]+edge[j][0]+1)/2);
		}
	}
	sort(cut.begin(), cut.end());
	vector<vector<long long>> pre;
	for(i=0; i<cut.size(); i++) {
		if(i == 0 || cut[i-1] != cut[i]) {
			DisjointSet ds(n);
			vector<vector<int>> s;
			for(j=0; j<m; j++) {
				s.push_back({abs(edge[j][0]-cut[i]), j});
			}
			int count = 0;
			long long val = 0;
			int slope = 0;
			sort(s.begin(), s.end());
			for(j=0; j<s.size(); j++) {
				int idx = s[j][1];
				int suc = ds.merge(edge[idx][1], edge[idx][2]);
				if(suc == 0) {
					count++;
					val += abs(edge[idx][0]-cut[i]);
					slope += (edge[idx][0]>cut[i])?-1:1;
				}
				if(count == n-1) {
					break;
				}
			}
			pre.push_back({cut[i], val, slope});
		}
	}
	vector<int> find;
	for(i=0; i<pre.size(); i++) {
		find.push_back(pre[i][0]);
	}
	auto ans = [&](int val) {
		int idx = upper_bound(find.begin(), find.end(), val)-find.begin()-1;
		return pre[idx][1]+pre[idx][2]*(val-pre[idx][0]);
	};
	long long answer = 0;
	int p, a, b, c;
	scanf("%d %d %d %d %d", &p, &k, &a, &b, &c);
	for(ql=0; ql<p; ql++) {
		scanf("%d", &q);
		answer ^= ans(q);
	}
	long long qi = q;
	for(ql=p; ql<k; ql++) {
		qi = (a*qi+b)%c;
		answer ^= ans(qi);
	}
	printf("%lld\n", answer);
}