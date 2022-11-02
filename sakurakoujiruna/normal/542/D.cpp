#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using vi = vector <int>;
#define pb push_back
const int N = int(1e6) + 111;

int p[N];
vi vp;

ll qmul(ll a, ll b, ll m) { a %= m; b %= m;
	ll r = a * b, s = ld(a) * b / m;
	return ((r - m * s) % m + m) % m;
}
ll qpow(ll a, ll b, ll mod) {
	ll r = 1;
	for(; b > 0; b /= 2) {
		if(b & 1)
			r = qmul(r, a, mod);
		a = qmul(a, a, mod);
	}
	return r;
}
bool miller_rabin(ll n, ll base) {
	ll n2 = n - 1, s = 0;
	while(n2 % 2 == 0) n2 /= 2, s ++;
	ll t = qpow(base, n2, n);
	if(t == 1 || t == n - 1) return true;
	for(s --; s >= 0; s --)
		if((t = qmul(t, t, n)) == n - 1) return true;
	return false;
}
bool m_is_prime(ll n) {
	static ll base[] = {2,3,5,7,11,13,17,19,23,29,31,37};
	static ll lim[]={4,2047,1373653,25326001,3215031751LL,21\
52302898747LL,3474749660383LL,341550071728321LL,0,0,0,0};
	if(n < 2) return false;
	for(int i = 0; i < 12 && base[i] < n; i ++) {
		if(n < lim[i]) return true;
		if(!miller_rabin(n, base[i])) return false;
	}
	return true;
}

bool is_prime(ll n) {
	if(n < 2) return false;
	if(n < N) return p[n] == n;
	return m_is_prime(n);
}

int ans = 0;

ll qpow(ll a, ll b) {
	ll r = 1;
	for(; b > 0; b /= 2) {
		if(b & 1)
			r = r * a;
		a = a * a;
	}
	return r;
}

bool solve(ll lim, ll n) {
	if(is_prime(n) && n > lim) return true;
	if(lim < 2 && __builtin_popcountll(n) == 1 && n != 1) return true;
	int tt = 26;
	if(lim > 1)
		tt = llround(log(n) / log(lim)) + 1;
	for(int i = 2; i <= min(26, tt); i ++) {
		ll x = llround(powl(n, 1.0L / i));
		if(qpow(x, i) == n && is_prime(x) && x > lim)
			return true;
	}
	return false;
}

void dfs(vi :: iterator it, ll n) {
	if(ll(*it + 1) * (*it + 2) > n) return;
	for(ll t = *it; t < n; t *= (*it))
		if(n % (t + 1) == 0) {
			if(n / (t + 1) != 1) {
				ans += solve(*it, n / (t + 1) - 1);
				dfs(next(it), n / (t + 1));
			}
		}
	dfs(next(it), n);
}

int main() {
	iota(p, p + N, 0);
	for(int i = 2; i < N; i ++) if(p[i] == i) {
		vp.pb(i);
		for(int j = i * 2; j < N; j += i) p[j] = i;
	}
	ios :: sync_with_stdio(false);
	
	ll n; cin >> n;
	if(n == 1)
		cout << "1\n";
	else {
		ans = solve(1, n - 1);
		dfs(vp.begin(), n);
		cout << ans << '\n';
	}
	
	return 0;
}