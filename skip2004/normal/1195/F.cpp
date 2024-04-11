#include<bits/stdc++.h>
using std::cin;
using std::cout;
const int maxn = 300300;
typedef std::pair<int, int> pr;
int n, q, L[maxn], R[maxn], tot, idx;
pr bak[maxn], a[maxn];
std::map<pr, int> map;
int c[maxn], pre[maxn];
int last[maxn];

struct Q { int id, p; };
std::vector<Q> vec[maxn];
int ans[maxn], bit[maxn];
inline void add(int x) {
	x += 1;
	for(;x < maxn;x += x & -x) bit[x] += 1;
}
inline int ask(int x) {
	x += 1;
	int ans = 0;
	for(;x;x &= x - 1) ans += bit[x];
	return ans;
}
int main() {
	std::ios::sync_with_stdio(false), std::cin.tie(0);
	cin >> n;
	for(int i = 1, k;i <= n;++i) {
		L[i] = tot + 1;
		cin >> k;
		for(int i = 0;i < k;++i) {
			cin >> bak[i].first >> bak[i].second;
		}
		for(int i = 1;i < k;++i) {
			a[tot + i].first = bak[i].first - bak[i - 1].first;
			a[tot + i].second = bak[i].second - bak[i - 1].second;
		}
		a[tot + k].first = bak[0].first - bak[k - 1].first;
		a[tot + k].second = bak[0].second - bak[k - 1].second;
		R[i] = tot += k;
	}
	cin >> q;
	for(int i = 1, l, r;i <= q;++i) {
		cin >> l >> r, l = L[l], r = R[r];
		ans[i] = 1 - l;
		vec[r].push_back({i, l - 1});
	}
	for(int i = 1;i <= tot;++i) {
		int gcd = std::abs(std::__gcd(a[i].first, a[i].second));
		a[i].first /= gcd;
		a[i].second /= gcd;
		if(!map.count(a[i])) map[a[i]] = ++ idx;
		c[i] = map[a[i]];
		add(last[c[i]]);
		pre[i] = last[c[i]];
		last[c[i]] = i;
		for(auto x : vec[i]) {
			ans[x.id] += ask(x.p);
		}
	}
	for(int i = 1;i <= q;++i) {
		cout << ans[i] << '\n';
	}
}