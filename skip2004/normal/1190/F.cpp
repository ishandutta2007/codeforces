#include<bits/stdc++.h>
typedef long long ll;
typedef __int128 LL;
using std::cin;
using std::cout;
inline ll mul(ll a, ll b, ll mod) { return (LL) a * b % mod; }
inline void reduce(ll & x, ll mod) {
	x += x >> 63 & mod;
}
inline ll pow(ll a, ll b, ll mod) {
	ll ans = 1;
	for(;b;b >>= 1, a = (LL) a * a % mod) if(b & 1) {
		ans = (LL) ans * a % mod;
	}
	return ans;
}
const int test_primes[12] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
bool miller(ll n) {
	ll e = n - 1 >> __builtin_ctzll(n - 1);
	for (int i = 0; i < 12; ++i) {
		const int p = test_primes[i];
		if (n == p) return 1;
		for (ll d = e, lst = pow(p, d, n), now; d != n - 1; d <<= 1, lst = now) {
			now = mul(lst, lst, n);
			if (now == 1 && lst != 1 && lst != n - 1) return 0;
		}
		if (pow(p, n - 1, n) != 1) return 0;
	}
	return 1;
}

std::mt19937_64 rd(time(0));
std::map<ll,int> map;

inline ll gcd(ll x,ll y){
	int s = __builtin_ctzll(x | y);
	x >>= __builtin_ctzll(x),y >>= __builtin_ctzll(y);
	while(y){
		if(x > y) std::swap(x,y);
		y -= x,y >>= __builtin_ctzll(y);
	}
	return x << s;
}

inline void rho(ll x){
	if(x <= 1) return ;
	if(miller(x)) return void(++map[x]);
	for(;;){
		ll x1 = rd() % x;
		ll x2 = x1;
		ll c = rd() % x - x;
		int i = 1,h = 2;
		for(;i < 1e5;){
			++ i, reduce(x1 = mul(x1,x1,x) + c,x);
			ll dt = x1 - x2; if(dt < 0) dt = - dt;
			ll p = gcd(x,dt);
			if(p != 1 && p != x) return rho(p),rho(x/p);
			if(i == h) x2 = x1, h <<= 1;
		}
	}
}

ll n, m, p, P;
inline ll get(ll x) {
	for(ll i = 2;i * i * i <= x;++i) {
		ll p = x;
		for(;p % i == 0;p /= i);
		if(p == 1) return i;
	}
	ll o = round(sqrt(x)); if(o * o == x) return o;
	return x;
}
inline ll wwj(ll x, ll phi) {
	x = phi;
	for(auto i : map) {
		if(phi % i.first == 0) {
			x = x / i.first * (i.first - 1);
			while(phi % i.first == 0) phi /= i.first;
		}
	}
	return x;
}
inline ll get_g(ll phi) {
	for(ll i = 2;;++i) {
		for(auto x : map) if(pow(i, phi / x.first, m) == 1) {
			goto next;
		}
		return i;
next:;
	}
}
int main() {
	std::ios::sync_with_stdio(false), std::cin.tie(0);
	cin >> n >> m >> p;
	P = get(m);
	rho(m - m / P);
	std::vector<ll> vc;
	if(std::__gcd(m, p) != 1) {
		for(ll i = 2;i < m;++i) if(gcd(i, m) == 1) {
			vc.push_back(i);
			if(vc.size() == n) break;
		}
		if(vc.size() == n) {
			for(ll i : vc) {
				cout << i << ' ';
			}
		} else {
			cout << -1 << '\n';
		}
	} else {
		ll phi = m - m / P, o = phi;
		for(auto i : map) {
			for(;o % i.first == 0 && pow(p, o / i.first, m) == 1;)
				o /= i.first;
		}
		ll ln = phi / o;
		if(phi - o < n) {
			cout << -1 << '\n';
			return 0;
		}
		if(m & m - 1) {
			ll G = get_g(phi), xxx = 1;
			for(int t = 1;;++t) {
				xxx = mul(xxx, G, m);
				if(t % ln) {
					vc.push_back(xxx);
				}
				if(vc.size() == n) {
					break;
				}
			}
			for(ll i : vc) {
				cout << i << ' ';
			}
		} else {
			if(m < 1 << 21) {
				static bool ok[1 << 21];
				for(int i = 1;i < m;++i){
					ok[i] = i % P;
				}
				ok[1] = 0;
				for(ll now = p;now != 1;now = now * p % m) ok[now] = 0;
				for(int i = 1;i < m;++i) {
					if(ok[i]) vc.push_back(i);
					if(vc.size() == n) break;
				}
				for(ll i : vc) {
					cout << i << ' ';
				}
			} else {
				if(p % 4 == 1) {
					for(int i = 0;;++i) {
						vc.push_back(i * 4 + 3);
						if(vc.size() == n) break;
					}
					for(ll i : vc) {
						cout << i << ' ';
					}
				} else {
					ll now = 1;
					for(int t = 1;;++t) {
						now = now * 5 % m;
						if(t & 1) vc.push_back(now);
						if(vc.size() == n) break;
					}
					for(ll i : vc) {
						cout << i << ' ';
					}
				}
			}
		}
	}
}