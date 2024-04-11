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

int add(int a, int b) {
	return a+b;
}

int main() {
	int cl, ql;
	int i, j, k, l;
	int t, n, m, q;
	int in;
	scanf("%d", &t);
	for(cl=0; cl<t; cl++) {
		scanf("%d", &n);
		char ss[n+1];
		char ts[n+1];
		scanf("%s", ss);
		scanf("%s", ts);
		int s[n], t[n];
		for(i=0; i<n; i++) {
			s[i] = ss[i]-'a';
			t[i] = ts[i]-'a';
		}
		int first[26];
		for(i=0; i<26; i++) {
			for(j=0; j<n && s[j]!=i; j++);
			first[i] = j;
		}
		/*for(i=0; i<26; i++) {
			printf("%d ", first[i]);
		}
		printf("\n");*/
		SegmentTree<int> tree(n, add, 0);
		long long answer = LLONG_MAX;
		long long sum = 0;
		for(i=0; i<n; i++) {
			for(j=t[i]-1; j>=0; j--) {
				if(first[j] != n) {
					answer = min(answer, sum+first[j]+tree.query(first[j], n)-i);
				}
			}
			if(first[t[i]] == n) {
				break;
			} else {
				sum += first[t[i]]+tree.query(first[t[i]], n)-i;
				tree.update(first[t[i]], 1);
				for(j=first[t[i]]+1; j<n && s[j]!=t[i]; j++);
				first[t[i]] = j;
			}
		}
		if(answer == LLONG_MAX) {
			printf("-1\n");
		} else {
			printf("%lld\n", answer);
		}
	}
}