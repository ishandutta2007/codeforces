#include <bits/stdc++.h>

using namespace std;

int mod = 1e9+7;

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
		Mod(long long val) {
			this->val = val%mod;
		}
		Mod(long long num, long long den) {
			this->val = ((long long)num*inv_mod(den))%mod;
		}
		Mod operator+(Mod a) {
			return Mod((val+a.val)%mod);
		}
		void operator+=(Mod a) {
			val = (val+a.val)%mod;
		}
		Mod operator+(int a) {
			return Mod((val+a)%mod);
		}
		void operator+=(int a) {
			val = (val+a)%mod;
		}
		Mod operator-(Mod a) {
			return Mod((mod+val-a.val)%mod);
		}
		void operator-=(Mod a) {
			val = (mod+val-a.val)%mod;
		}
		Mod operator-(int a) {
			return Mod((mod+val-a)%mod);
		}
		void operator-=(int a) {
			val = (mod+val-a)%mod;
		}
		Mod operator*(Mod a) {
			return Mod((val*a.val)%mod);
		}
		void operator*=(Mod a) {
			val = (val*a.val)%mod;
		}
		Mod operator*(int a) {
			return Mod((val*a)%mod);
		}
		void operator*=(int a) {
			val = (val*a)%mod;
		}
		Mod operator/(Mod a) {
			return Mod((val*inv_mod(a.val))%mod);
		}
		void operator/=(Mod a) {
			val = (val*inv_mod(a.val))%mod;
		}
		Mod operator/(int a) {
			return Mod((val*inv_mod(a))%mod);
		}
		void operator/=(int a) {
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
	int t, n, m, q;
	int u, v;
	int in;
	cin >> n >> m >> k;
	vector<Mod> a;
	for(i=0; i<n; i++) {
		cin >> in;
		a.push_back(Mod(in));
	}
	mod = k;
	vector<Mod> sum{Mod(0)};
	for(i=0; i<n; i++) {
		sum.push_back(sum.back()+a[i]);
	}
	if(sum.back().val == 0) {
		vector<int> count(k, 0);
		for(i=0; i<n; i++) {
			count[sum[i].val]++;
		}
		long long seg = 0;
		for(i=0; i<n; i++) {
			seg += count[sum[i].val];
		}
		mod = 1e9+7;
		Mod answer(seg);
		answer *= m;
		answer *= m;
		answer -= Mod(m)*n-1;
		cout << answer.val;
	} else {
		Mod rev = Mod(k-1)/sum.back();
		for(i=0; i<=n; i++) {
			sum[i] *= rev;
		}
		SegmentTree<int> tree(k, add, 0);
		int rem;
		for(i=0; i<n; i++) {
			rem = sum[i].val;
			tree.update(rem, tree.idx(rem)+1);
		}
		long long seg = 0;
		for(i=0; i<n; i++) {
			rem = (sum[i]-1).val;
			tree.update(rem, tree.idx(rem)+1);
			rem = sum[i].val;
			tree.update(rem, tree.idx(rem)-1);
			if(rem+m%k >= k) {
				seg += tree.query(rem, k);
				seg += tree.query(0, (rem+m)%k);
			} else {
				seg += tree.query(rem, rem+m%k);
			}
		}
		mod = 1e9+7;
		Mod answer(seg);
		answer += Mod(n)*n*(m/k);
		answer *= m;
		if(m%k == 0) {
			answer -= Mod(m)*n-1;
		}
		cout << answer.val;
	}
}