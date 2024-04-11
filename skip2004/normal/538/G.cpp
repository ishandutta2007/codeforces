#include<bits/stdc++.h>
const int maxn = 2000200;
const int mod = 998244353;
typedef long long ll;
inline ll pow(ll a,int b,ll ans = 1) {
	for(;b;b >>= 1,a = a * a % mod) if(b & 1) ans = ans * a % mod;
	return ans;
}
inline ll inverse(int x){ return pow(x, mod - 2); }
inline void reduce(int & x){ x += x >> 31 & mod; }
#define rep(i, l, r) for(int i = (l), i##end = (r);i <= i##end;++i)
int n, l;
inline ll dv(ll x,ll y){ return x > 0 ? x / y : (x - y + 1) / y; }
inline void solve(std::map<ll, ll>& map, int * a){
	struct T{ ll pos, d, cnt; };
	std::vector<T> vector;
	vector.push_back({l - 1, -1, 0});
	vector.push_back({-1, 0, 0});
	for(auto i : map) {
		vector.push_back({i.first % l, i.first / l, i.second});
	}
	// di * l = cnti - s_posi
	// dj * l = cntj - s_posj
	// (di - dj) * l = cnti - cntj + s_posj - s_posi
	// 0 <= s_posj - s_posi <= posj - posi
	// cnt_i - cnt_j <= (di - dj) * l <= cnti - cntj + posj - posi
	std::sort(vector.begin(),vector.end(),[&](const T & x,const T & y) { return x.pos < y.pos; });
	ll min = 1e18, max = 0;
	for(int i = 1;i < vector.size();++i) {
		const T & x = vector[i - 1],& y = vector[i];
		ll lhs = x.cnt - y.cnt;
		ll rhs = x.cnt - y.cnt - x.pos + y.pos;
		if(x.d == y.d) {
			if(lhs > 0 || rhs < 0) min = 0,max = 1;
		} else {
			ll d = x.d - y.d;
			if(d < 0) std::swap(lhs = -lhs, rhs = - rhs), d = - d;
			min = std::min<ll> (min, dv(rhs, d));
			max = std::max<ll> (max, dv(lhs + d - 1, d));
		}
	}
	if(min < max) {
		std::cout << "NO" << '\n', exit(0);
	} else {
		ll s = min;
		const auto getval = [&](const T & i) { return i.cnt - i.d * s; };
		for(int i = 1;i < vector.size();++i) {
			const T & x = vector[i - 1], & y = vector[i];
			int cnt = getval(y) - getval(x);
			for(int i = x.pos + 1;cnt--;++i) a[i] = 1;
		}
	}
}
std::map<ll, ll> map0;
std::map<ll, ll> map1;
int ans0[maxn];
int ans1[maxn];
int main() {
	std::ios::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n >> l;
	for(int i = 1;i <= n;++i) {
		ll t, x, y;
		std::cin >> t >> x >> y;
		if(x + y + t & 1) {
			puts("NO");
			return 0;
		}
		map0[t - 1] = x + y + t >> 1;
		map1[t - 1] = x - y + t >> 1;
	}
	solve(map0, ans0);
	solve(map1, ans1);
	for(int i = 0;i < l;++i) std::cout << "LDUR"[ans0[i] << 1 | ans1[i]];
	std::cout << '\n';
}