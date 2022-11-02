#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <set>

using namespace std;

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
		
		int index(int idx) {
			return tree[n+idx];
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
	int h, i, j;
	int t, n, m, k;
	scanf("%d", &t);
	for(h=0; h<t; h++) {
		scanf("%d", &n);
		int a[n], b[n];
		for(i=0; i<n; i++) {
			scanf("%d", &a[i]);
			b[i] = a[i];
		}
		sort(b, b+n);
		for(i=0; i<n; i++) {
			a[i] = lower_bound(b, b+n, a[i])-b;
		}
		long long answer = 0;
		SegmentTree s(n, add, 0);
		for(i=0; i<n; i++) {
			int r = s.query(a[i]+1, n);
			int l = s.query(0, a[i]);
			answer += min(l, r);
			s.update(a[i], s.index(a[i])+1);
		}
		printf("%lld\n", answer);
	}
}