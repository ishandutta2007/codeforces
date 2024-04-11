#include <stdio.h>
#include <limits.h>
#include <time.h>
#include <algorithm>
#include <vector>
#include <cmath>
#include <set>
#include <queue>
#include <string>
#include <map>
#include <functional>

using namespace std;

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
		
		long long idx(int idx) {
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

long long min_int(long long a, long long b) {
	return min(a, b);
}

long long max_int(long long a, long long b) {
	return max(a, b);
}

int main() {
	int h, i, j;
	int t, n, m, k, q;
	scanf("%d", &t);
	for(h=0; h<t; h++) {
		long long answer = 0;
		scanf("%d", &n);
		int a[n];
		for(i=0; i<n; i++) {
			scanf("%d", &a[i]);
		}
		long long s[n+1];
		s[0] = 0;
		for(i=1; i<=n; i++) {
			if(i%2 == 0) {
				s[i] = s[i-1]-a[i-1];
			} else {
				s[i] = s[i-1]+a[i-1];
			}
		}
		LLSegmentTree s1((n+2)/2, max_int, LONG_LONG_MIN);
		LLSegmentTree s2((n+1)/2, min_int, LONG_LONG_MAX);
		for(i=0; i<=n; i++) {
			if(i%2 == 0) {
				s1.update(i/2, s[i]);
			} else {
				s2.update(i/2, s[i]);
			}
		}
		vector<pair<long long, int> > idx;
		for(i=0; i<=n; i++) {
			idx.push_back(pair<long long, int>{s[i], i});
		}
		sort(idx.begin(), idx.end());
		/*for(i=0; i<=n; i++) {
			printf("%lld %d\n", idx[i].first, idx[i].second);
		}*/
		int count = 0;
		for(i=0; i<n; i++) {
			if(idx[i].first == idx[i+1].first) {
				long long end = idx[i].first;
				long long all_max = s1.query(idx[i].second/2, idx[i+1].second/2);
				long long all_min = s2.query(idx[i].second/2, idx[i+1].second/2);
				if(all_max <= end && end <= all_min) {
					count++;
					answer += count;
				} else {
					count = 0;
				}
			} else {
				count = 0;
			}
		}
		printf("%lld\n", answer);
	}
}