#include <bits/stdc++.h>
using namespace std;

const int N = (int)1e6 + 11;
const int Mod = (int)1e9 + 7;
using ll = long long;

ll qpow(ll a, ll b) {
	ll r = 1;
	for(; b; b /= 2) {
		if(b & 1) r = r * a % Mod;
		a = a * a % Mod;
	}
	return r;
}

int p[N];
vector <int> fac[N], pos[N];
ll a[N], pre[N];

struct Query {
	int l, r, id;
	bool operator <(Query q) const {
		return l < q.l;
	}
}query[N];
int ans[N];

int lowbit(int x) { return x & (-x); }
struct BIT {
	ll b[N];
	void init() { fill(b, b + N, 1); }
	void change(int p, ll c) {
		p += 2;
		for(; p < N; p += lowbit(p))
			b[p] = b[p] * c % Mod;
	}
	ll query(int p) {
		p += 2; ll r = 1;
		for(; p; p -= lowbit(p))
			r = r * b[p] % Mod;
		return r;
	}
}bit;

int main() {
	iota(p + 2, p + N, 2);
	for(int i = 2; i < N; i ++) if(p[i] == i) {
		for(int j = i * 2; j < N; j += i) p[j] = i;
	}
	ios :: sync_with_stdio(false);
	int n; cin >> n;
	for(int i = 1; i <= n; i ++) {
		cin >> a[i];
		for(int t = a[i]; t != 1; t /= p[t]) {
			if(p[t] != p[t / p[t]]) {
				fac[i].push_back(p[t]);
				pos[p[t]].push_back(i);
			}
		}
	}
	auto change = [&](int p) {
		if(pos[p].size() == 0) return;
		bit.change(pos[p].back(), (p - 1) * qpow(p, Mod - 2) % Mod);
		pos[p].pop_back();
	};
	bit.init();
	for(int i = 1; i < N; i ++) {
		reverse(pos[i].begin(), pos[i].end());
		change(i);
	}
	pre[0] = 1;
	for(int i = 1; i <= n; i ++)
		pre[i] = a[i] * pre[i - 1] % Mod;

	int q; cin >> q;
	for(int i = 0; i < q; i ++) {
		cin >> query[i].l >> query[i].r;
		query[i].id = i;
	}
	sort(query, query + q);
	int last = 1;
	for(int i = 0; i < q; i ++) {
		Query q = query[i];
		while(last < q.l) {
			for(int f : fac[last]) {
				change(f);
			}
			last ++;
		}
		ans[q.id] = pre[q.r] * qpow(pre[q.l - 1], Mod - 2) % Mod *
			bit.query(q.r) % Mod * qpow(bit.query(q.l - 1), Mod - 2) % Mod;
	}
	for(int i = 0; i < q; i ++)
		cout << ans[i] << '\n';
	return 0;
}