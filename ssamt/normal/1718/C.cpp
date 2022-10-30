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

long long binm(long long a, long long b) {
	return max(a, b);
}

int main() {
	int cl, ql;
	int i, j, k, l;
	int t, n, m, q;
	int u, v;
	int in;
	cin >> t;
	for(cl=0; cl<t; cl++) {
		cin >> n >> q;
		vector<int> a(n);
		for(i=0; i<n; i++) {
			cin >> a[i];
		}
		vector<int> prime(n+1, 1);
		prime[1] = 0;
		for(i=2; i<=n; i++) {
			if(prime[i]) {
				for(j=i+i; j<=n; j+=i) {
					prime[j] = 0;
				}
			}
		}
		vector<int> div;
		for(i=1; i<n; i++) {
			if(n%i == 0 && prime[n/i]) {
				div.push_back(i);
			}
		}
		vector<long long> dividx{0};
		vector<long long> temp;
		for(i=0; i<div.size(); i++) {
			for(j=0; j<div[i]; j++) {
				long long sum = 0;
				for(k=j; k<n; k+=div[i]) {
					sum += (long long)a[k]*div[i];
					//cout << k << " " << temp.size() << " " << div[i] << endl;
				}
				temp.push_back(sum);
			}
			dividx.push_back(temp.size());
		}
		SegmentTree<long long> st(temp.size(), binm, 0);
		for(i=0; i<temp.size(); i++) {
			//cout << temp[i] << " ";
			st.update(i, temp[i]);
		}
		cout << st.query(0, temp.size()) << endl;
		for(ql=0; ql<q; ql++) {
			int p, x;
			cin >> p >> x;
			p--;
			int diff = x-a[p];
			a[p] = x;
			for(i=0; i<div.size(); i++) {
				int idx = dividx[i]+p%div[i];
				int mul = div[i];
				long long val = st.idx(idx);
				val += (long long)diff*mul;
				st.update(idx, val);
			}
			cout << st.query(0, temp.size()) << endl;
		}
	}
}