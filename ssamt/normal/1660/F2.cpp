#include <bits/stdc++.h>

using namespace std;

template <typename T>
class SegmentTree {
	public:
		T (*func)(T, T);
		int n;
		vector<T> tree;
		T def;
		
		SegmentTree(int nodes, T (*f)(T, T), T def_val) {
			int i;
			nodes--;
			for(n=1; nodes>0; n<<=1, nodes>>=1);
			func = f;
			def = def_val;
			tree = vector<T>(2*n);
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
		
		void change(int idx, T val) {
			tree[idx+n] = val;
		}
		
		void recal() {
			for(int i=n-1; i>0; i--) {
				tree[i] = func(tree[2*i], tree[2*i+1]);
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

int add(int a, int b) {
	return a+b;
}

int main() {
	int i, j, k, l;
	int t, n, m, q;
	scanf("%d", &t);
	for(int cl=0; cl<t; cl++) {
		scanf("%d", &n);
		string s;
		cin >> s;
		vector<int> sum(n+1);
		sum[0] = n;
		for(i=1; i<=n; i++) {
			sum[i] = sum[i-1];
			if(s[i-1] == '+') {
				sum[i]--;
			} else {
				sum[i]++;
			}
		}
		vector<SegmentTree<int>> tree(3, SegmentTree<int>(2*n/3+1, add, 0));
		long long answer = 0;
		for(i=0; i<=n; i++) {
			answer += tree[sum[i]%3].query(0, sum[i]/3+1);
			tree[sum[i]%3].update(sum[i]/3, tree[sum[i]%3].idx(sum[i]/3)+1);
		}
		printf("%lld\n", answer);
	}
}