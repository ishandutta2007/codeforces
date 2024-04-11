#include<bits/stdc++.h>
#define rep(i, l, r) for(int i = (l), i##end = (r);i <= i##end;++i)
using std::cin;
using std::cout;

typedef unsigned long long u64;
typedef double db;
typedef long long ll;
typedef unsigned u32;
const int mod = 1e9 + 7;
const int N = 200200;
const int M = 1e6 + 10;

int n, q, a[N];
int pre[N];
int ans[N];

inline int pow(int a, int b, int ans = 1) {
	for(;b;b >>= 1, a = (u64) a * a % mod) if(b & 1)
		ans = (u64) ans * a % mod;
	return ans;
}
struct Ask { int l, id; };
std::vector<Ask> vec[N];
int map[M];
int inv[M];

int bit[N];
inline int ask(int x) {
	int res = 1;
	for(;x <= n;x += x & -x) res = (u64) res * bit[x] % mod;
	return res;
}

inline void add(int x, int v) {
	for(;x;x &= x - 1) bit[x] = (u64) bit[x] * v % mod;
}

inline void push(int id, int x) {
	add(map[x], 1 + inv[x - 1]);
	map[x] = id;
	add(id, mod + 1 - inv[x]);
}
int main() {
	std::ios::sync_with_stdio(false), cin.tie(0);
	*pre = 1;
	inv[1] = 1;
	for(int i = 2;i < M;++i) {
		inv[i] = u64(mod - mod / i) * inv[mod % i] % mod;
	}
	cin >> n;
	rep(i, 1, n) {
		cin >> a[i], pre[i] = (u64) pre[i - 1] * a[i] % mod;
	}
	cin >> q;
	rep(i, 1, q) {
		int l, r;
		cin >> l >> r;
		ans[i] = pow(pre[l - 1], mod - 2, pre[r]);
		vec[r].push_back((Ask){l, i});
	}
	std::fill(bit + 1, bit + n + 1, 1);
	rep(id, 1, n) {
		int x = a[id];
		for(int i = 2;i * i <= x;++i) if(x % i == 0) {
			push(id, i);
			do x /= i; while(x % i == 0);
		}
		if(x != 1) push(id, x);
		for(const Ask & x : vec[id]) {
			ans[x.id] = (u64) ans[x.id] * ask(x.l) % mod;
		}
	}
	rep(i, 1, q) cout << ans[i] << '\n';
}