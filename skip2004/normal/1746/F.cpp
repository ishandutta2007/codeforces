#include<bits/stdc++.h>
using std::cin;
using std::cout;
const int N = 300005;
const int P = 50;
using ll = long long;
int n, q;
int a[N];
inline int get(int x) {
	static std::map<int, int> mp;
	if(mp.count(x)) return mp[x];
	int p = mp.size() + 1;
	return mp[x] = p;
}
static std::mt19937 gen(time(0)+(size_t)new char);
struct PBPB {
	std::bitset<N * 2> w, v;
	int bit[N];
	int a[N];
	inline int calc(int o) {
		if(!v[o]) w[o] = gen() & 1, v[o] = 1;
		return w[o];
	}
	inline void add(int x, int v) {
		for(int i = x;i <= n;i += i & -i) {
			bit[i] += v;
		}
	}
	inline int qry(int x) {
		int ans = 0;
		for(int i = x;i;i &= i - 1) {
			ans += bit[i];
		}
		return ans;
	}
	inline int chk(int l, int r, int k) {
		return ((qry(r) - qry(l - 1)) % k == 0);
	}
	inline void c(int p, int w) {
		add(p, calc(w)-a[p]);
		a[p] = calc(w);
	}
} z[P];
int main() {
	std::ios::sync_with_stdio(false), cin.tie(0);
	cin >> n >> q;
	for(int i = 1;i <= n;++i) {
		cin >> a[i], a[i] = get(a[i]);
		for(int j = 0;j < P;++j) {
			z[j].c(i, a[i]);
		}
	}
	for(int i = 0;i < q;++i) {
		int op, x, l, r, k;
		cin >> op;
		if(op == 1) {
			int p; cin >> p >> x;
			x = get(x);
			for(int j = 0;j < P;++j) {
				z[j].c(p, x);
			}
		} else {
			cin >> l >> r >> k;
			if((r - l + 1) % k) {
				cout << "NO" << '\n';
				continue;
			}
			for(int j = 0;j < P;++j) {
				if(!z[j].chk(l, r, k)) {
					cout << "NO" << '\n';
					goto pass;
				}
			}
			cout << "YES" << '\n';
pass:;
		}
	}
}