#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <cmath>

class SegmentTree {
	public:
		int (*func)(int, int);
		int n;
		int* tree;
		int def;
		
		SegmentTree(int nodes, int (*f)(int, int), int def_val) {
			int i;
			nodes--;
			for(n=1; nodes>0; n<<=1, nodes>>=1);
			func = f;
			def = def_val;
			tree = (int*)malloc(sizeof(int)*2*n);
			for(i=2*n-1; i>0; i--) {
				if(i >= n) {
					tree[i] = def;
				} else {
					tree[i] = func(tree[2*i], tree[2*i+1]);
				}
			}
		}
		
		void update(int idx, int val) {
			int i;
			for(i=n+idx; i>0; i/=2) {
				if(i >= n) {
					tree[i] = val;
				} else {
					tree[i] = func(tree[2*i], tree[2*i+1]);
				}
			}
		}
		
		int query(int l, int r) {
			if(l == r) {
				return def;
			}
			return cur(0, n, 1, l, r);
		}
		
		int cur(int start, int end, int idx, int l, int r) {
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

int cmp_first(const void* num1, const void* num2) {
	int* a = *(int**)num1;
	int* b = *(int**)num2;
	if(a[0] > b[0]) {
		return 1;
	} else if(a[0] < b[0]) {
		return -1;
	} else {
		return 0;
	}
}

int max(int a, int b) {
	if(a > b) {
		return a;
	} else {
		return b;
	}
}

int main() {
	int h, i, j, k;
	int t, n;
	scanf("%d", &t);
	for(h=0; h<t; h++) {
		scanf("%d", &n);
		int b[n];
		for(i=0; i<n; i++) {
			scanf("%d", &b[i]);
		}
		int* order[n];
		for(i=0; i<n; i++) {
			order[i] = (int*)malloc(sizeof(int)*2);
			order[i][0] = b[i];
			order[i][1] = i;
		}
		qsort(order, n, sizeof(int*), cmp_first);
		int count = 0;
		for(i=0; i<n; i++) {
			b[order[i][1]] = count;
			if(i == n-1 || order[i][0] < order[i+1][0]) {
				count++;
			}
		}
		int nodes = count;
		SegmentTree seg(count, max, 0);
		seg.update(b[0], 1);
		int a = 1;
		for(i=1; i<n; i++) {
			if(b[i-1] < b[i]) {
				if(seg.query(b[i-1]+1, b[i]) == 1) {
					a = 0;
					break;
				}
			} else if(b[i-1] > b[i]) {
				if(seg.query(b[i]+1, b[i-1]) == 1) {
					a = 0;
					break;
				}
			}
			seg.update(b[i], 1);
		}
		if(a) {
			printf("YES\n");
		} else {
			printf("NO\n");
		}
	}
}