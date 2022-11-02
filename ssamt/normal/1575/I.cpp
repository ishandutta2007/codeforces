#include <stdio.h>
#include <limits.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <set>
#include <queue>
#include <string>
#include <map>
#include <functional>

using namespace std;

class DirTree {
	public:
		int n;
		int root;
		std::vector< std::vector<int> > a;

		DirTree(int nodes) {
		    int i;
            n = nodes;
            for(i=0; i<n; i++) {
                std::vector<int> e;
                a.push_back(e);
            }
		}

		void add(int i, int j) {
			a[i].push_back(j);
		}
		
		vector<int> prefix() {
			int i;
			queue<int> visit;
			vector<int> post;
			int visited[n] = {};
			visit.push(root);
			post.push_back(root);
			while(!visit.empty()) {
				int node = visit.front();
				visit.pop();
				for(i=0; i<a[node].size(); i++) {
					int con = a[node][i];
					if(!visited[con]) {
						visit.push(con);
						post.push_back(con);
					}
				}
				visited[node] = 1;
			}
			return post;
		}
		
		vector<int> weights() {
			int i, j;
			vector<int> w(n, 1);
			vector<int> post = prefix();
			for(i=post.size()-1; i>=0; i--) {
				int node = post[i];
				for(j=0; j<a[node].size(); j++) {
					w[node] += w[a[node][j]];
				}
			}
			return w;
		}
		
		void print() {
			int i, j;
			for(i=0; i<a.size(); i++) {
				printf("%d: ", i);
				for(j=0; j<a[i].size(); j++) {
					printf("%d ", a[i][j]);
				}
				printf("\n");
			}
		}
};

class AdjGraph {
	public:
		int n;
		std::vector< std::vector<int> > a;

		AdjGraph(int nodes) {
		    int i;
            n = nodes;
            for(i=0; i<n; i++) {
                std::vector<int> e;
                a.push_back(e);
            }
		}

		void add(int i, int j) {
			a[i].push_back(j);
			a[j].push_back(i);
		}
		
		DirTree bfs_tree(int start) {
			int i;
			DirTree d(n);
			d.root = start;
			queue<int> visit;
			int visited[n] = {};
			visit.push(start);
			while(!visit.empty()) {
				int node = visit.front();
				visit.pop();
				for(i=0; i<a[node].size(); i++) {
					int con = a[node][i];
					if(!visited[con]) {
						d.add(node, con);
						visit.push(con);
					}
				}
				visited[node] = 1;
			}
			return d;
		}
		
		void print() {
			int i, j;
			for(i=0; i<a.size(); i++) {
				printf("%d: ", i);
				for(j=0; j<a[i].size(); j++) {
					printf("%d ", a[i][j]);
				}
				printf("\n");
			}
		}
};

//untested
class LLSegmentTree {
	public:
		long long (*func)(long long, long long);
		int n;
		long long* tree;
		long long def;
		
		LLSegmentTree(int nodes, long long (*f)(long long, long long), long long def_val) {
			int i;
			nodes--;
			for(n=1; nodes>0; n<<=1, nodes>>=1);
			func = f;
			def = def_val;
			tree = (long long*)malloc(sizeof(long long)*2*n);
			for(i=2*n-1; i>0; i--) {
				if(i >= n) {
					tree[i] = def;
				} else {
					tree[i] = func(tree[2*i], tree[2*i+1]);
				}
			}
		}
		
		void update(int idx, long long val) {
			int i;
			for(i=n+idx; i>0; i/=2) {
				if(i >= n) {
					tree[i] = val;
				} else {
					tree[i] = func(tree[2*i], tree[2*i+1]);
				}
			}
		}
		
		long long query(int l, int r) {
			if(l == r) {
				return def;
			}
			return cur(0, n, 1, l, r);
		}
		
		long long cur(int start, int end, int idx, int l, int r) {
			if(l <= start && end <= r) {
				return tree[idx];
			}
			if(end <= l || r <= start) {
				return def;
			}
			int mid = (start+end)/2;
			return func(cur(start, mid, idx*2, l, r), cur(mid, end, idx*2+1, l, r));
		}
		
		void print() {
			int i;
			for(i=1; i<2*n; i++) {
				printf("%d ", tree[i]);
			}
			printf("\n");
		}
};

long long sum(long long a, long long b) {
	return a+b;
}

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
	int h, i, j, l;
	int t, n, m, k, q;
	int type;
	int u, v;
	scanf("%d %d", &n, &q);
	int a[n];
	for(i=0; i<n; i++) {
		scanf("%d", &a[i]);
		a[i] = abs(a[i]);
	}
	AdjGraph g(n);
	for(i=0; i<n-1; i++) {
		scanf("%d %d", &u, &v);
		g.add(u-1, v-1);
	}
	DirTree d = g.bfs_tree(0);
	vector<int> w = d.weights();
	vector<int> pre = d.prefix();
	int tree_idx[n] = {0};
	int elem_idx[n] = {0};
	int pred[n] = {-1};
	for(i=0; i<pre.size(); i++) {
		int node = pre[i];
		int max = 0;
		int max_idx = -1;
		for(j=0; j<d.a[node].size(); j++) {
			int con = d.a[node][j];
			if(w[con] > max) {
				max = w[con];
				max_idx = j;
			}
		}
		for(j=0; j<d.a[node].size(); j++) {
			int con = d.a[node][j];
			if(j == max_idx) {
				tree_idx[con] = tree_idx[node];
				elem_idx[con] = elem_idx[node]+1;
			} else {
				tree_idx[con] = con;
				elem_idx[con] = 0;
				pred[con] = node;
			}
		}
	}
	int tree_len[n] = {};
	for(i=0; i<n; i++) {
		tree_len[tree_idx[i]]++;
	}
	LLSegmentTree* tree[n];
	for(i=0; i<n; i++) {
		if(tree_len[i]) {
			tree[i] = new LLSegmentTree(tree_len[i], sum, 0);
		}
	}
	for(i=0; i<n; i++) {
		tree[tree_idx[i]]->update(elem_idx[i], a[i]);
	}
	
	auto to_root = [&](int n) {
		long long answer = 0;
		while(true) {
			answer += tree[tree_idx[n]]->query(0, elem_idx[n]+1);
			if(tree_idx[n] == 0) {
				break;
			}
			n = pred[tree_idx[n]];
		}
		return answer;
	};
	
	int query[q][3];
	vector<pair<int, int> > find[n];
	for(h=0; h<q; h++) {
		scanf("%d %d %d", &query[h][0], &query[h][1], &query[h][2]);
		if(query[h][0] == 1) {
			query[h][1]--;
			query[h][2] = abs(query[h][2]);
		} else {
			query[h][1]--;
			query[h][2]--;
			find[query[h][1]].push_back(pair<int, int>{query[h][2], h});
			find[query[h][2]].push_back(pair<int, int>{query[h][1], h});
		}
	}
	
	int lca[q];
	DisjointSet tar(n);
	int checked[n] = {};
	int ancestor[n];
	for(i=0; i<n; i++) {
		ancestor[i] = i;
	}
	function<void(int)> tarjan;
	tarjan = [&](int n) {
		int i;
		for(i=0; i<d.a[n].size(); i++) {
			int con = d.a[n][i];
			tarjan(con);
			tar.merge(n, con);
			ancestor[tar.find(n)] = n;
		}
		checked[n] = 1;
		for(i=0; i<find[n].size(); i++) {
			int other = find[n][i].first;
			if(checked[other]) {
				lca[find[n][i].second] = ancestor[tar.find(other)];
			}
		}
		/*printf("n:%d\n", n);
		for(i=0; i<n; i++) {
			printf("%d ", ancestor[i]);
		}
		printf("\n");*/
	};
	tarjan(0);
	/*for(i=0; i<q; i++) {
		printf("%d ", lca[i]);
	}
	printf("\n");*/
	
	for(h=0; h<q; h++) {
		u = query[h][1];
		v = query[h][2];
		if(query[h][0] == 1) {
			tree[tree_idx[u]]->update(elem_idx[u], v);
			a[u] = v;
		} else {
			//printf("u:%d %d\n", u, to_root(u));
			//printf("v:%d %d\n", v, to_root(v));
			//printf("lca:%d %d\n", lca[h], to_root(lca[h]));
			long long sum = to_root(u)+to_root(v)-2*to_root(lca[h])+a[lca[h]];
			long long answer = 2*sum-a[u]-a[v];
			printf("%lld\n", answer);
		}
	}
	
}