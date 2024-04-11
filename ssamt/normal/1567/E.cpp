#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

class SegmentTree {
	public:
		long long* (*func)(long long*, long long*);
		int n;
		long long** tree;
		long long* def;
		
		SegmentTree(int nodes, long long* (*f)(long long*, long long*), long long* def_val) {
			int i, j;
			nodes--;
			for(n=1; nodes>0; n<<=1, nodes>>=1);
			func = f;
			def = def_val;
			tree = (long long**)malloc(sizeof(long long*)*2*n);
			for(i=1; i<2*n; i++) {
				tree[i] = (long long*)malloc(sizeof(long long)*6);
			}
			for(i=2*n-1; i>0; i--) {
				if(i >= n) {
					for(j=0; j<6; j++) {
						tree[i][j] = def[j];
					}
				} else {
					free(tree[i]);
					tree[i] = func(tree[2*i], tree[2*i+1]);
				}
			}
		}
		
		void update(int idx, long long* val) {
			int i, j;
			for(i=n+idx; i>0; i/=2) {
				if(i >= n) {
					for(j=0; j<6; j++) {
						tree[i][j] = val[j];
					}
				} else {
					free(tree[i]);
					tree[i] = func(tree[2*i], tree[2*i+1]);
				}
			}
		}
		
		long long* query(int l, int r) {
			int j;
			if(l == r) {
				long long* n = (long long*)malloc(sizeof(long long)*6);
				for(j=0; j<6; j++) {
					n[j] = def[j];
				}
				return n;
			}
			return cur(0, n, 1, l, r);
		}
		
		long long* cur(int start, int end, int idx, int l, int r) {
			int j;
			if(l <= start && end <= r) {
				long long* n = (long long*)malloc(sizeof(long long)*6);
				for(j=0; j<6; j++) {
					n[j] = tree[idx][j];
				}
				return n;
			}
			if(end <= l || r <= start) {
				long long* n = (long long*)malloc(sizeof(long long)*6);
				for(j=0; j<6; j++) {
					n[j] = def[j];
				}
				return n;
			}
			int mid = (start+end)/2;
			long long* c1 = cur(start, mid, idx*2, l, r);
			long long* c2 = cur(mid, end, idx*2+1, l, r);
			long long* c3 = func(c1, c2);
			free(c1);
			free(c2);
			return c3;
		}
		
		void print() {
			int i, j;
			for(i=1; i<2*n; i++) {
				for(j=0; j<6; j++) {
					printf("%lld ", tree[i][j]);
				}
				printf("\n");
			}
			printf("\n");
		}
};

//left len, right len, total len, inside, left val, right val
long long* join(long long* a, long long* b) {
	int j;
	long long* answer = (long long*)malloc(sizeof(long long)*6);
	if(a[2] == 0) {
		for(j=0; j<6; j++) {
			answer[j] = b[j];
		}
		return answer;
	}
	if(b[2] == 0) {
		for(j=0; j<6; j++) {
			answer[j] = a[j];
		}
		return answer;
	}
	if(a[0] == a[2] && b[0] == b[2]) {
		if(a[5] <= b[4]) {
			answer[0] = a[0]+b[0];
			answer[1] = a[0]+b[0];
			answer[3] = 0;
		} else {
			answer[0] = a[0];
			answer[1] = b[1];
			answer[3] = 0;
		}
	} else if(a[0] == a[2]) {
		if(a[5] <= b[4]) {
			answer[0] = a[0]+b[0];
			answer[1] = b[1];
			answer[3] = b[3];
		} else {
			answer[0] = a[0];
			answer[1] = b[1];
			answer[3] = b[3]+b[0]*(b[0]+1)/2;
		}
	} else if(b[0] == b[2]) {
		if(a[5] <= b[4]) {
			answer[0] = a[0];
			answer[1] = a[1]+b[1];
			answer[3] = a[3];
		} else {
			answer[0] = a[0];
			answer[1] = b[1];
			answer[3] = a[3]+a[1]*(a[1]+1)/2;
		}
	} else {
		if(a[5] <= b[4]) {
			answer[0] = a[0];
			answer[1] = b[1];
			long long in = a[1]+b[0];
			answer[3] = a[3]+b[3]+in*(in+1)/2;
		} else {
			answer[0] = a[0];
			answer[1] = b[1];
			answer[3] = a[3]+b[3]+a[1]*(a[1]+1)/2+b[0]*(b[0]+1)/2;
		}
	}
	answer[2] = a[2]+b[2];
	answer[4] = a[4];
	answer[5] = b[5];
	return answer;
}

int main() {
	long long h, i, j;
	long long n, q, t, x, y;
	scanf("%lld %lld", &n, &q);
	long long* def = (long long*)malloc(sizeof(long long)*6);
	long long* alloc;
	def[2] = 0;
	SegmentTree seg(n, join, def);
	long long a[n];
	for(i=0; i<n; i++) {
		scanf("%lld", &a[i]);
		alloc = (long long*)malloc(sizeof(long long)*6);
		alloc[0] = 1;
		alloc[1] = 1;
		alloc[2] = 1;
		alloc[3] = 0;
		alloc[4] = a[i];
		alloc[5] = a[i];
		seg.update(i, alloc);
	}
	for(h=0; h<q; h++) {
		scanf("%lld %lld %lld", &t, &x, &y);
		if(t == 1) {
			alloc = (long long*)malloc(sizeof(long long)*6);
			alloc[0] = 1;
			alloc[1] = 1;
			alloc[2] = 1;
			alloc[3] = 0;
			alloc[4] = y;
			alloc[5] = y;
			seg.update(x-1, alloc);
			free(alloc);
		} else {
			long long* answer = seg.query(x-1, y);
			long long comb = answer[3];
			comb += answer[0]*(answer[0]+1)/2;
			if(answer[0] != answer[2]) {
				comb += answer[1]*(answer[1]+1)/2;
			}
			printf("%lld\n", comb);
			free(answer);
		}
	}
}