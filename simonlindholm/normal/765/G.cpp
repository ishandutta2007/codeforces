#include <bits/stdc++.h>
using namespace std;

#define rep(i, from, to) for (int i = from; i < (to); ++i)
#define trav(a, x) for (auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const ll mod = 1000000007;

ll modpow(ll a, ll e) {
	if (e == 0) return 1;
	if (e == 1) return a;
	ll x = modpow(a * a % mod, e >> 1);
	if (e & 1) x = x * a % mod;
	return x;
}

ll bitrev(ll bits, int si) {
	ll ret = 0;
	rep(i,0,si) if (bits & (1LL << i)) {
		ret |= 1LL << (si-1 - i);
	}
	return ret;
}

bool symmetric = false;
int slen;
ll forbidden, required;
int nforb;

vi hips;
vi dp[41];

ll sol(int missing, int atp = 0) {
	if (atp == sz(hips))
		return missing == 0;
	int& out = dp[missing][atp];
	if (out != -1) return out;

	int p = hips[atp];
	int allowed = p - nforb;
	assert(allowed >= missing);
	ll res = 0;
	if (missing)
		res += missing * sol(missing-1, atp+1);
	res += (allowed - missing) * sol(missing, atp+1);
	res %= mod;
	out = (int)res;
	return res;
}

struct Hasher {
	size_t operator()(unsigned long long x) const {
		return x + (x >> 13);
	}
};

unordered_map<ll, int, Hasher> mem;
vi ps;
ll rec(ll bits, int at) {
	if (bits & forbidden) return 0;
	if (at == sz(ps)) {
		int missing = (int)__builtin_popcountll(required & ~bits);
		return sol(missing);
	}

	if (symmetric && at <= 3) {
		bits &= (1LL << slen) - 1;
		ll bits2 = bitrev(bits, slen);
		if (bits2 < bits) bits = bits2;
	}

	int p = ps[at];
	ll lubits = bits;
	if (p >= 23) {
		bits &= (1LL << slen) - 1;

		int diff = slen - p;
		ll midm = ((1LL << (slen - 2*diff)) - 1) << diff;
		ll mid = (bits & midm) >> diff;
		size_t ones = __builtin_popcountll(mid);
		ll sorted = (1LL << ones) - 1;
		lubits = (bits & ~midm) | (sorted << diff);
	}

	lubits = lubits << 20 | at;
	int& out = mem[lubits];
	if (out) return out-1;

	// if (mem.size() % 100000 == 0)
		// cerr << mem.size() << endl;

	ll bits2 = 0;
	for (int j = 0; j < 40; j += p)
		bits2 |= 1LL << j;
	ll mask = (1LL << 40) - 1;

	ll res = 0;

	ll bits3 = bits | bits2;
	ll base = rec(bits3, at+1);
	res += base;

	rep(i,0,p-1) {
		bits2 <<= 1;
		bits2 &= mask;
		ll bits4 = bits | bits2;
		if (bits4 == bits3) res += base;
		else res += rec(bits4, at+1);
	}

	res %= mod;
	out = (int)(res + 1);
	return res;
}

int main() {
	cin.sync_with_stdio(false);
	cin.exceptions(cin.failbit);
	string s;
	cin >> s;
	::slen = sz(s);
	required = forbidden = 0;
	nforb = 0;
	string rev;
	rep(i,0,slen) {
		if (s[i] == '0') required |= 1LL << i;
		else forbidden |= 1LL << i, nforb++;
		rev = s[i] + rev;
	}
	if (s == rev) symmetric = true;
	int N;
	cin >> N;
	set<int> pss;
	ll mult = 1;
	rep(i,0,N) {
		int p, a;
		cin >> p >> a;
		if (p < slen) pss.insert(p);
		else hips.push_back(p);
		mult = mult * modpow(p, a-1) % mod;
	}
	ps.assign(all(pss));

	rep(i,0,41) dp[i].assign(sz(hips)+1, -1);

	mem.reserve(3 << 23);
	ll res = rec(0LL, 0);
	// cerr << sz(mem) << endl;
	cout << res * mult % mod << endl;

	exit(0);
}