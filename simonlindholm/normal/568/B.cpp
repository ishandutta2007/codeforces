#include <bits/stdc++.h>
using namespace std;

#define rep(i, from, to) for (int i = from; i < int(to); ++i)
#define trav(a, x) for (auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

static const ll mod = 1000000007;

vector<ll> mem[2];

vector<ll> invs;
struct Bin {
	int N = 0, K = 0;
	ll r = 1;
	void m(ll a, ll b) { r = r * a % mod * invs[b] % mod; }
	ll choose(int n, int k) {
		if (k > n || k < 0) return 0;
		while (N < n) ++N, m(N, N-K);
		while (K < k) ++K, m(N-K+1, K);
		while (K > k) m(K, N-K+1), --K;
		while (N > n) m(N-K, N), --N;
		return r;
	}
};

ll f(int rem, bool failed) {
	if (rem == 0)
		return failed;
	ll& out = mem[failed][rem];
	if (out != -1) return out;
	ll ret = f(rem-1, true);
	Bin b;
	rep(i,1,rem+1)
		ret += f(rem-i, failed) * b.choose(rem-1, i-1) % mod;
	ret %= mod;
	return out = ret;
}

ll modpow(ll a, ll e) {
	if (e == 0) return 1;
	ll x = modpow(a*a % mod, e >> 1);
	if (e & 1) x = x * a % mod;
	return x;
}

int main() {
	cin.sync_with_stdio(false);
	int N;
	cin >> N;
	mem[0].assign(N+1, -1);
	mem[1].assign(N+1, -1);
	invs.assign(N+1, 0);
	rep(i,1,N+1)
		invs[i] = modpow(i, mod-2);
	cout << f(N, false) << endl;
}