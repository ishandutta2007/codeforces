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
const ll inv10 = 700000005;
const ll LIM = 120000;
ll* inv;

vector<ll> p102;

ll modpow(ll a, ll e) {
	if (e == 0) return 1;
	if (e == 1) return a;
	ll x = modpow(a, e >> 1);
	x = x * x % mod;
	if (e & 1) x = x * a % mod;
	return x;
}

struct Num {
	ll value;
	ll p10, p10inv;
	static Num from(int x) {
		return {x, 10, inv10};
	}
};
const Num ZERO = {0,1,1};

Num concat(Num a, Num b) {
	Num res;
	res.value = (a.value * b.p10 + b.value) % mod;
	res.p10 = a.p10 * b.p10 % mod;
	res.p10inv = a.p10inv * b.p10inv % mod;
	return res;
}

Num overlay(Num a, Num b) {
	assert((a.p10 - b.p10) % mod == 0);
	Num res = a;
	res.value = (a.value + b.value) % mod;
	return res;
}

Num conc10(Num num) {
	if (num.value == 0 && num.p10 == 1) return num;
	num = concat(num, num);
	Num q = concat(num, num);
	q = concat(q, q);
	return concat(num, q);
}

Num repeat(const string& str, Num num) {
	Num res = ZERO;
	for (char c : str) {
		res = conc10(res);
		int d = c - '0';
		rep(i,0,d)
			res = concat(res, num);
	}
	return res;
}

Num unconcatLeft(Num a, Num b) {
	Num res;
	res.p10 = b.p10 * a.p10inv % mod;
	res.p10inv = b.p10inv * a.p10 % mod;
	res.value = (b.value - a.value * res.p10) % mod;
	if (res.value < 0) res.value += mod;
	return res;
}

Num zeroes(ll len) {
	Num ret;
	ret.value = 0;
	ret.p10 = modpow(10, len);
	ret.p10inv = modpow(inv10, len);
	return ret;
}

Num ones(int dim, int d) {
	ll inv = modpow(modpow(10, dim) - 1, mod - 2);
	ll len = p102[d] * dim % (mod - 1);
	Num ret = zeroes(len);
	ret.value = (modpow(10, len) - 1) * inv % mod;
	return ret;
}

Num iot(int dim, int d) {
	ll inv = modpow(modpow(10, dim) - 1, mod - 2);
	Num ret = ones(dim, d);
	ret.value = (ret.value - modpow(10, d)) * inv % mod;
	return ret;
}

Num range(const string& lim) {
	if (lim.empty()) return ZERO;
	Num res = ZERO;
	rep(d,1,sz(lim)) {
		Num full = iot(d, d);
		Num part = iot(d, d-1);
		Num n = unconcatLeft(part, full);
		res = concat(res, n);
	}

	int len = sz(lim);
	function<void(int, Num)> rec = [&](int at, Num prev) {
		if (at == len) return;
		int right = len - at - 1;
		Num one = ones(len, right);
		Num after = iot(len, right);
		Num zr = zeroes(right);
		int dig = lim[at] - '0';
		rep(d,0,dig) {
			if (d == 0 && at == 0) continue;
			Num before = one;
			before.value *= concat(concat(prev, Num::from(d)), zr).value;
			res = concat(res, overlay(before, after));
		}
		rec(at+1, concat(prev, Num::from(dig)));
	};
	rec(0, ZERO);

	for (char c : lim) {
		res = concat(res, Num::from(c - '0'));
	}

	return res;
}

Num range(const string& a, const string& b) {
	assert(sz(a) <= sz(b));
	string amin1 = a;
	if (amin1 == '1' + string(sz(a)-1, '0')) {
		amin1 = string(sz(a)-1, '9');
	} else {
		int i = sz(a)-1;
		while (amin1[i] == '0') --i;
		--amin1[i];
		rep(j,i+1,sz(a)) amin1[j] = '9';
	}
	return unconcatLeft(range(amin1), range(b));
}

pair<Num, char> parseTerm();

pair<Num, char> parse() {
	auto pa = parseTerm();
	Num res = pa.first;
	char ch = pa.second;
	while (ch == '+') {
		auto pa2 = parseTerm();
		Num res2 = pa2.first;
		ch = pa2.second;
		res = concat(res, res2);
	}
	return make_pair(res, ch);
}

bool isdig(char ch) { return '0' <= ch && ch <= '9'; }

pair<Num, char> parseTerm() {
	char ch;
	Num val = ZERO;
	string str;
	while (isdig(ch = (char)getchar())) {
		str += ch;
		val = concat(val, Num::from(ch - '0'));
	}

	if (ch == '-') {
		string str2;
		while (isdig(ch = (char)getchar())) {
			str2 += ch;
		}
		return make_pair(range(str, str2), ch);
	}

	if (ch == '(') {
		auto pa = parse();
		assert(pa.second == ')');
		ch = (char)getchar();
		return make_pair(repeat(str, pa.first), ch);
	}

	return make_pair(val, ch);
}

int main() {
	cin.sync_with_stdio(false);
	inv = new ll[LIM] - 1; inv[1] = 1;
	rep(i,2,LIM) inv[i] = mod - (mod / i) * inv[mod % i] % mod;
	p102.resize(LIM);
	p102[0] = 1;
	rep(i,1,LIM) p102[i] = p102[i-1] * 10 % (mod - 1);

	ll res = parse().first.value;
	res %= mod;
	if (res < 0) res += mod;
	cout << res << endl;
	exit(0);
}