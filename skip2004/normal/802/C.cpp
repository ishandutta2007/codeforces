#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include<bits/stdc++.h>
const int maxn = 82;
typedef long long ll;
int n, k;
int a[maxn], c[maxn];
int ans;
std::bitset<maxn> use[maxn];
struct status {
	std::bitset<maxn> in;
	int now, val, cnt, cost;
	inline int calc() {
		val = cost; 
		auto set = in &= use[now], other = use[now]; other ^= in;
		int ct = cnt = in.count(), most = val;
		for(int i = other._Find_first();i < maxn;i = other._Find_next(i)) {
			most += c[i];
		}
		for(int i = now;i <= n;++i) {
			if(set.test(a[i])) continue;
			if(ct == k) {
				set.reset(set._Find_first());
				-- ct;
			}
			val += c[a[i]];
			if(use[i + 1].test(a[i])) {
				++ ct, set.set(a[i]);
			}
		}
		if(val < ans) ans = val;
		return most;
	}
	inline int operator < (const status& b) const {
		return cost > b.cost;
	}
} R;
std::unordered_set<std::bitset<maxn>> set[maxn];
int bak[maxn], rk[maxn], is[maxn];
int main() {
	using std::cin;
	using std::cout;
	cin >> n >> k;
	for(int i = 1;i <= n;++i) {
		cin >> a[i];
	}
	for(int i = 1;i <= n;++i) {
		cin >> c[i];
		rk[i] = i;
	}
	std::sort(rk + 1, rk + n + 1, [](int x, int y){ return c[x] < c[y]; });
	for(int i = 1;i <= n;++i) is[rk[i]] = i;
	for(int i = 1;i <= n;++i) a[i] = is[a[i]];
	std::sort(c + 1, c + n + 1);
	for(int i = n;i >= 1;--i) {
		(use[i] = use[i + 1]).set(a[i]);
	}
	c[0] = 1e9;
	std::priority_queue<status> q;
	ans = 1e9, R.now = 1, R.calc(), q.push(R);
	for(;!q.empty();) {
		status x = q.top();
		q.pop();
		if(set[x.now].count(x.in)) {
			continue;
		}
		set[x.now].insert(x.in);
		const auto solve = [&](status&x) {
			x.in.set(a[x.now]), ++ x.cnt, x.cost += c[a[x.now]];
			for(;x.now <= n && x.in.test(a[x.now]);) ++ x.now;
			static const int limit = 5000;
			if(x.calc() <= ans && x.now <= n && ++ bak[x.now] <= limit) {
				q.push(x);
			}
		};
		if(x.cnt < k) {
			solve(x);
		} else {
			for(int i = x.in._Find_first();i < maxn;i = x.in._Find_next(i)) {
				auto y = x; -- y.cnt, y.in.reset(i);
				solve(y);
			}
		}
	}
	cout << ans << '\n';
}