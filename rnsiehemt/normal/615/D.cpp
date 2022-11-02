#include <bits/stdc++.h>
#define sz(x) (int((x).size()))
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
template<typename T> bool domax(T &a, T b) { return (b > a ? (a = b, true) : false); }
template<typename T> bool domin(T &a, T b) { return (b < a ? (a = b, true) : false); }
typedef long long ll;

const ll Mod = 1000*1000*1000+7;

int M;
ll ans, p[800005], q[800005];
std::vector<ll> v;
std::vector<std::pair<ll, int>> w;

ll sqr(ll a) {
	return (a*a) % Mod;
}
ll modexp(ll b, ll e) {
	if (!e) return 1ll;
	else if (e&1) return (sqr(modexp(b, e/2)) * b) % Mod;
	else return sqr(modexp(b, e/2));
}
void go(int n, int l, int r) {
	if (l+1 == r) p[n] = w[l].second + 1;
	else {
		int m = (l+r)/2;
		go(n*2+1, l, m);
		go(n*2+2, m, r);
		p[n] = (p[n*2+1] * p[n*2+2]) % (Mod - 1);
	}
}
void go2(int n, int l, int r, ll cur) {
	if (l+1 == r) q[l] = cur;
	else {
		int m = (l+r)/2;
		go2(n*2+1, l, m, (cur * p[n*2+2]) % (Mod - 1));
		go2(n*2+2, m, r, (cur * p[n*2+1]) % (Mod - 1));
	}
}

int main()
{
	scanf("%d", &M);
	v.resize(M);
	for (ll &a : v) scanf("%lld", &a);
	std::sort(all(v));
	for (int i = 0; i < sz(v); i++) {
		if (i && v[i-1] == v[i]) w.back().second++;
		else w.eb(v[i], 1);
	}
	go(0, 0, sz(w));
	go2(0, 0, sz(w), 1);
	ans = 1;
	for (int i = 0; i < sz(w); i++) {
		auto &p = w[i];
		ll thing = 0;
		for (int e = 0; e <= p.second; e++) {
			thing = (thing + e) % (Mod - 1);
		}
		thing = (thing * q[i]) % (Mod - 1);
		ans = (ans * modexp(p.first, thing)) % Mod;
	}
	printf("%lld\n", ans);
}