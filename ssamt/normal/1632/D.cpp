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

int gcd(int a, int b) {
	if(a < 0) {
		return gcd(-a, b);
	} else if(a == 0) {
		return b;
	} else if(a > b) {
		return gcd(b, a);
	} else if(b%a == 0) {
		return a;
	} else {
		return gcd(b%a, a);
	}
}

int main() {
	int cl, ql;
	int i, j, k, l;
	int t, n, m, q;
	int u, v;
	int in;
	scanf("%d", &n);
	SegmentTree<int> tree(n, gcd, 0);
	int a[n];
	for(i=0; i<n; i++) {
		scanf("%d", &a[i]);
		tree.update(i, a[i]);
	}
	int last = -1;
	int answer = 0;
	for(i=1; i<=n; i++) {
		int start = last+1;
		int end = i;
		int find = 0;
		while(start+1 < end) {
			int mid = (start+end)/2;
			int res = tree.query(mid, i);
			if(res < i-mid) {
				start = mid;
			} else if(res > i-mid) {
				end = mid;
			} else {
				start = mid;
				break;
			}
		}
		int res = tree.query(start, i);
		if(res == i-start) {
			find = 1;
		}
		if(find) {
			answer++;
			last = i-1;
		}
		printf("%d ", answer);
	}
}