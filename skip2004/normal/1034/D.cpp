#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include<bits/stdc++.h>
const int maxn = 300100;
struct istream { static const int size = 1 << 23; char buf[size], *vin; inline istream() { fread(buf,1,size,stdin); vin = buf - 1; } inline istream& operator >> (int & x) { for(x = *++vin & 15;isdigit(*++vin);) x = x * 10 + (*vin & 15); return * this; } } cin;
typedef long long ll;
using std::cout;
int n, k;
int l[maxn], r[maxn];
std::vector<int> vc;
int N;
inline int get(int x) {
	return std::lower_bound(vc.begin(), vc.end(), x) - vc.begin();
}
int max[maxn];
namespace dak {
	typedef std::map<int, int>::iterator iter;
	std::map<int, int> map;
	inline iter split(int x) {
		iter it = map.lower_bound(x);
		return it -> first == x ? it : map.emplace_hint(it, x, std::prev(it) -> second);
	}
	struct opt { int idx, cnt; };
	inline void make(int x, int y, int v, std::vector<opt> & vec) {
		iter R = split(y + 1), L = split(x);
		for(iter i = L;i != R;++i) vec.push_back({i -> second, - vc[std::next(i) -> first] + vc[i -> first]});
		map.erase(L, R);
		map[x] = v;
		vec.push_back({v, vc[y + 1] - vc[x]});
	}
	std::vector<opt> vector[maxn];
	inline void init() {
		map[0] = map[(int)2e9] = n + 1;
		for(int i = n;i >= 1;--i) {
			make(l[i], r[i], i, vector[i]);
		}
	}
}
int cnt[maxn];
inline ll calc(int x) {
	memset(cnt, 0, sizeof cnt);
	ll ans = 0;
	int now = 0;
	for(int i = n, j = n;i >= 1;--i) {
		for(const dak::opt & x : dak::vector[i]) {
			cnt[x.idx] += x.cnt;
			if(x.idx <= j) now += x.cnt;
		}
		for(;now >= x;) now -= cnt[j--];
		ans += n - j;
		max[i] = j + 1;
	}
	return ans;
}
std::vector<int> ins[maxn << 1], del[maxn << 1];
namespace seg {
	const int N = 1 << 20;
	int min[N], max[N];
	ll sum[N];
	inline void build(int cur, int l, int r) {
		if(l == r) {
			min[cur] = max[cur] = sum[cur] = ::max[l];
			return ;
		}
		int mid = l + r >> 1;
		build(cur << 1, l, mid);
		build(cur << 1 | 1, mid + 1, r);
		sum[cur] = sum[cur << 1] + sum[cur << 1 | 1];
		min[cur] = std::min(min[cur << 1], min[cur << 1 | 1]);
		max[cur] = std::max(max[cur << 1], max[cur << 1 | 1]);
	}
	inline ll ask(int ql, int qr, int cur = 1, int l = 1, int r = n) {
		if(ql <= l && r <= qr) {
			if(min[cur] > qr) return 0;
			if(max[cur] <= qr) return ll(r - l + 1) * (qr + 1) - sum[cur];
		}
		int mid = l + r >> 1; ll ans = 0;
		if(ql <= mid) ans += ask(ql, qr, cur << 1, l, mid);
		if(mid < qr) ans += ask(ql, qr, cur << 1 | 1, mid + 1, r);
		return ans;
	}
}
inline ll cal(int x) {
	for(int i = 0;i <= N;++i) {
		ins[i].reserve(4);
		del[i].reserve(4);
	}
	for(int i = 1;i <= n;++i) {
		ins[l[i]].push_back(i);
		del[r[i]].push_back(i);
	}
	seg::build(1, 1, n);
	ll ans = 0, c = 0;
	std::set<int> set = {0, n + 1};
	const auto ask = [&](int l, int r) {
		return l <= r ? seg::ask(l, r) : 0;
	};
	const auto push = [&](int x) {
		auto it = set.lower_bound(x);
		c += ask(*std::prev(it) + 1, *it - 1);
		c -= ask(*std::prev(it) + 1, x - 1);
		c -= ask(x + 1, * it - 1);
		set.emplace_hint(it, x);
	};
	const auto pop = [&](int x) {
		set.erase(x);
		auto it = set.lower_bound(x);
		c -= ask(*std::prev(it) + 1, *it - 1);
		c += ask(*std::prev(it) + 1, x - 1);
		c += ask(x + 1, * it - 1);
	};
	for(int i = 0;i <= N;++i) {
		for(int x : ins[i]) push(x);
		ans = ans + (ll) (vc[i + 1] - vc[i]) * c;
		for(int x : del[i]) pop(x);
	}
	return ans;
}

int main() {
	cin >> n >> k;
	vc.reserve(n + n);
	for(int i = 1;i <= n;++i) {
		cin >> l[i] >> r[i];
		vc.push_back(l[i]);
		vc.push_back(r[i]);
	}
	sort(vc.begin(), vc.end()), vc.erase(unique(vc.begin(), vc.end()), vc.end());
	for(int i = 1;i <= n;++i) {
		l[i] = get(l[i]);
		r[i] = get(r[i]) - 1;
	}
	N = vc.size() - 1;
	dak::init();
	int l = 0, r = 1e9 + 1;
	for(;l + 1 != r;) {
		int mid = l + r >> 1;
		if(calc(mid) < k) {
			r = mid;
		} else {
			l = mid;
		}
	}
	const ll cnt = calc(l);
	const ll sum = cal(l);
	cout << sum - (cnt - k) * l << '\n';
}