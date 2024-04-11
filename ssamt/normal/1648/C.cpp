#include <bits/stdc++.h>

using namespace std;

int mod = 998244353;

int pow_mod(int a, int k) {
	if(k == 0) {
		return 1;
	}
	int sub = pow_mod(a, k/2);
	if(k%2 == 0) {
		return ((long long)sub*sub)%mod;
	} else {
		return (((long long)sub*sub)%mod*a)%mod;
	}
}

int inv_mod(int a) {
	return pow_mod(a, mod-2);
}

int comb_mod(int n, int r) {
	int i;
	int answer = 1;
	if(2*r > n) {
		return comb_mod(n, n-r);
	}
	for(i=n-r+1; i<=n; i++) {
		answer = ((long long)answer*i)%mod;
	}
	for(i=1; i<=r; i++) {
		answer = ((long long)answer*inv_mod(i))%mod;
	}
	return answer;
}

class Mod {
	public:
		long long val;
		
		Mod() {
			this->val = 0;
		}
		Mod(int val) {
			this->val = val;
		}
		Mod(int num, int den) {
			this->val = ((long long)num*inv_mod(den))%mod;
		}
		Mod operator+(Mod a) {
			return Mod((val+a.val)%mod);
		}
		Mod operator+=(Mod a) {
			val = (val+a.val)%mod;
		}
		Mod operator+(int a) {
			return Mod((val+a)%mod);
		}
		Mod operator+=(int a) {
			val = (val+a)%mod;
		}
		Mod operator-(Mod a) {
			return Mod((mod+val-a.val)%mod);
		}
		Mod operator-=(Mod a) {
			val = (mod+val-a.val)%mod;
		}
		Mod operator-(int a) {
			return Mod((mod+val-a)%mod);
		}
		Mod operator-=(int a) {
			val = (mod+val-a)%mod;
		}
		Mod operator*(Mod a) {
			return Mod((val*a.val)%mod);
		}
		Mod operator*=(Mod a) {
			val = (val*a.val)%mod;
		}
		Mod operator*(int a) {
			return Mod((val*a)%mod);
		}
		Mod operator*=(int a) {
			val = (val*a)%mod;
		}
		Mod operator/(Mod a) {
			return Mod((val*inv_mod(a.val))%mod);
		}
		Mod operator/=(Mod a) {
			val = (val*inv_mod(a.val))%mod;
		}
		Mod operator/(int a) {
			return Mod((val*inv_mod(a))%mod);
		}
		Mod operator/=(int a) {
			val = (val*inv_mod(a))%mod;
		}
};

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
	int n, m, q;
	int u, v;
	int in;
	scanf("%d %d", &n, &m);
	int size = 200000;
	SegmentTree<int> tree(size+1, add, 0);
	vector<int> s, t;
	for(i=0; i<n; i++) {
		scanf("%d", &in);
		s.push_back(in);
		tree.update(in, tree.idx(in)+1);
	}
	for(i=0; i<m; i++) {
		scanf("%d", &in);
		t.push_back(in);
	}
	Mod answer;
	Mod state(1);
	for(i=1; i<=n; i++) {
		state *= i;
	}
	for(i=1; i<=size; i++) {
		for(j=1; j<=tree.idx(i); j++) {
			state /= j;
		}
	}
	for(i=0; i<m; i++) {
		int val = tree.query(0, t[i]);
		answer += state*val/(n-i);
		if(tree.idx(t[i]) > 0) {
			state /= (n-i);
			state *= tree.idx(t[i]);
			tree.update(t[i], tree.idx(t[i])-1);
		} else {
			break;
		}
	}
	if(i == n && n < m) {
		answer += 1;
	}
	printf("%lld\n", answer.val);
}