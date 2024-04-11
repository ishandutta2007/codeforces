#include <bits/stdc++.h>

using namespace std;

template <typename T>
class SegmentTree {
	public:
		T (*func)(T, T);
		int n;
		T* tree;
		T def;
		
		SegmentTree(int nodes, T (*f)(T, T), T def_val) {
			int i;
			nodes--;
			for(n=1; nodes>0; n<<=1, nodes>>=1);
			func = f;
			def = def_val;
			tree = (T*)malloc(sizeof(T)*2*n);
			for(i=2*n-1; i>0; i--) {
				if(i >= n) {
					tree[i] = def;
				} else {
					tree[i] = func(tree[2*i], tree[2*i+1]);
				}
			}
		}
		
		void update(int idx, T val) {
			int i;
			for(i=n+idx; i>0; i/=2) {
				if(i >= n) {
					tree[i] = val;
				} else {
					tree[i] = func(tree[2*i], tree[2*i+1]);
				}
			}
		}
		
		T query(int l, int r) {
			if(l == r) {
				return def;
			}
			return cur(0, n, 1, l, r);
		}
		
		T cur(int start, int end, int idx, int l, int r) {
			if(l <= start && end <= r) {
				return tree[idx];
			}
			if(end <= l || r <= start) {
				return def;
			}
			int mid = (start+end)/2;
			return func(cur(start, mid, idx*2, l, r), cur(mid, end, idx*2+1, l, r));
		}
		
		T idx(int i) {
			return tree[n+i];
		}
		
		void print() {
			int i;
			for(i=1; i<2*n; i++) {
				printf("%d ", tree[i]);
			}
			printf("\n");
		}
};

long long add(long long a, long long b) {
	return a+b;
}

int main() {
	int cl, ql;
	int i, j, k, l;
	int t, n, q;
	int in;
	scanf("%d %d", &n, &q);
	char s[n+1];
	scanf("%s", s);
	int parent[n];
	for(i=0; i<n; i++) {
		parent[i] = n;
	}
	long long count[n] = {};
	vector<int> child[n];
	int idx;
	function<void(int)> parse = [&](int start) {
		for(idx=start; idx<n; idx++) {
			if(s[idx] == '(') {
				child[start].push_back(idx);
				parent[idx] = start;
				int save = idx;
				parse(idx+1);
				count[start] += count[save+1];
			} else {
				break;
			}
		}
		count[start] += (long long)child[start].size()*(child[start].size()+1)/2;
	};
	for(idx=0; idx<n; idx++) {
		if(s[idx] == '(') {
			parse(idx);
		}
	}
	/*for(i=0; i<n; i++) {
		printf("%d ", count[i]);
	}
	printf("\n");
	for(i=0; i<n; i++) {
		for(j=0; j<child[i].size(); j++) {
			printf("%d ", child[i][j]);
		}
		printf("\n");
	}
	printf("\n");*/
	vector<SegmentTree<long long>> tree;
	for(i=0; i<n; i++) {
		tree.push_back(SegmentTree<long long>(child[i].size(), add, (long long)0));
		for(j=0; j<child[i].size(); j++) {
			tree[i].update(j, count[child[i][j]+1]);
		}
		//printf("Tree %d\n", i);
		//tree[i].print();
	}
	for(ql=0; ql<q; ql++) {
		int t, l, r;
		scanf("%d %d %d", &t, &l, &r);
		l--; r--;
		int p = parent[l];
		l = lower_bound(child[p].begin(), child[p].end(), l)-child[p].begin();
		r = lower_bound(child[p].begin(), child[p].end(), r)-child[p].begin();
		long long answer = tree[p].query(l, r);
		answer += ((long long)r-l)*(r-l+1)/2;
		printf("%lld\n", answer);
	}
}