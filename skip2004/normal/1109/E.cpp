#include<bits/stdc++.h>
using std::cin;
using std::cout;
const int maxn = 100100;
typedef long long ll;
 
int n, mod;
 
int p[100], tot;
inline void exgcd(int a, int b, int & x, int & y) {
	if(!a) {
		x = 0, y = 1;
		return ;
	}
	exgcd(b % a, a, y, x);
	x -= b / a * y;
}
inline int inv(int x) {
	int a, b;
	exgcd(x, mod, a, b);
	return a < 0 ? a + mod : a;
}
inline int pow(int a, int b, int ans = 1) {
	for(;b;b >>= 1, a = (ll) a * a % mod) if(b & 1)
		ans = (ll) ans * a % mod;
	return ans;
}
 
struct modint
{
	int val;
	int power[10];
	inline modint() { }
	inline int eval() const {
		int res = val;
		for(int i = 0;i < tot;++i) {
			if(power[i]) res = (ll) res * pow(p[i], power[i]) % mod;
		}
		return res;
	}
	inline modint(int x) {
		for(int i = 0;i < tot;++i) {
			power[i] = 0;
			while(x % p[i] == 0) {
				++ power[i];
				x /= p[i];
			}
		}
		val = x;
	}
};
 
inline void factor(int x) {
	for(int i = 2;i * i <= x;++i) {
		if(x % i == 0) {
			p[tot ++] = i;
			do {
				x /= i;
			} while(x % i == 0);
		}
	}
	if(x != 1) {
		p[tot ++] = x;
	}
}
 
inline modint const mul(modint const& x, modint const& y) {
	modint res;
	res.val = (ll) x.val * y.val % mod;
	for(int i = 0;i < 10;++i) {
		res.power[i] = x.power[i] + y.power[i];
	}
	return res;
}
inline modint const inv(modint x) {
	x.val = inv(x.val);
	for(int i = 0;i < 10;++i) x.power[i] = - x.power[i];
	return x;
}

int a[maxn];
modint none;
namespace sgt0 {
	modint tree[maxn << 2];
	inline void put(int cur, const modint & x) { tree[cur] = mul(tree[cur], x); }
	inline void pushdown(int cur) {
		put(cur << 1, tree[cur]);
		put(cur << 1 | 1, tree[cur]);
		tree[cur] = none;
	}
	inline void build(int cur, int l, int r) {
		if(l == r) {
			tree[cur] = a[l];
			return ;
		}
		tree[cur] = none;
		int mid = l + r >> 1;
		build(cur << 1, l, mid);
		build(cur << 1 | 1, mid + 1, r);
	}
	inline void upt(int ql, int qr, const modint & v, int cur = 1, int l = 1, int r = n) {
		if(ql <= l && r <= qr) return put(cur, v);
		int mid = l + r >> 1;
		if(ql <= mid) upt(ql, qr, v, cur << 1, l, mid);
		if(mid < qr) upt(ql, qr, v, cur << 1 | 1, mid + 1, r);
	}
	inline modint test(int pos, int cur = 1, int l = 1, int r = n) {
		if(l == r) return tree[cur];
		int mid = l + r >> 1;
		pushdown(cur);
		return pos <= mid ? test(pos, cur << 1, l, mid) : test(pos, cur << 1 | 1, mid + 1, r);
	}
}
namespace sgt1 {
	int sum[maxn << 2], tag[maxn << 2];
	inline void update(int cur) {
		sum[cur] = (sum[cur << 1] + sum[cur << 1 | 1]) % mod;
	}
	inline void put(int cur, int v) {
		sum[cur] = (ll) sum[cur] * v % mod;
		tag[cur] = (ll) tag[cur] * v % mod;
	}
	inline void pushdown(int cur) {
		if(tag[cur] != 1) {
			put(cur << 1, tag[cur]);
			put(cur << 1 | 1, tag[cur]);
			tag[cur] = 1;
		}
	}
	inline void build(int cur, int l, int r) {
		tag[cur] = 1;
		if(l == r) {
			sum[cur] = a[l];
			return ;
		}
		int mid = l + r >> 1;
		build(cur << 1, l, mid);
		build(cur << 1 | 1, mid + 1, r);
		update(cur);
	}
	inline void upt(int ql, int qr, int v, int cur = 1, int l = 1, int r = n) {
		if(ql <= l && r <= qr) return put(cur, v);
		int mid = l + r >> 1;
		pushdown(cur);
		if(ql <= mid) upt(ql, qr, v, cur << 1, l, mid);
		if(mid < qr) upt(ql, qr, v, cur << 1 | 1, mid + 1, r);
		update(cur);
	}
	inline ll ask(int ql, int qr, int cur = 1, int l = 1, int r = n) {
		if(ql <= l && r <= qr) return sum[cur];
		int mid = l + r >> 1; ll sum = 0;
		pushdown(cur);
		if(ql <= mid) sum += ask(ql, qr, cur << 1, l, mid);
		if(mid < qr) sum += ask(ql, qr, cur << 1 | 1, mid + 1, r);
		return sum;
	}
	inline void mdf(int pos, int v, int cur = 1, int l = 1, int r = n) {
		if(l == r) {
			sum[cur] = v;
			return ;
		}
		int mid = l + r >> 1;
		pushdown(cur);
		pos <= mid ? mdf(pos, v, cur << 1, l, mid) : mdf(pos, v, cur << 1 | 1, mid + 1, r);
		update(cur);
	}
}
int main() {
	std::ios::sync_with_stdio(false), cin.tie(0);
	none.val = 1;
	cin >> n >> mod;
	factor(mod);
	for(int i = 1;i <= n;++i) {
		cin >> a[i];
	}
	int q;
	cin >> q;
	sgt0::build(1, 1, n);
	sgt1::build(1, 1, n);
	for(int i = 1, opt, l, r, p, x;i <= q;++i) {
		cin >> opt;
		if(opt == 1) {
			cin >> l >> r >> x;
			sgt0::upt(l, r, x);
			sgt1::upt(l, r, x);
		}
		if(opt == 2) {
			cin >> p >> x;
			const auto & o = inv(modint(x));
			auto res = sgt0::test(p);
			res = mul(res, o);
			sgt0::upt(p, p, o);
			sgt1::mdf(p, res.eval());
		}
		if(opt == 3) {
			cin >> l >> r;
			cout << int(sgt1::ask(l, r) % mod) << '\n';
		}
	}
}