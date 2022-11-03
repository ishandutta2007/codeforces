#include <cstdio>

typedef long long ll;

const int MAXK = 2E2 + 10;
const int MOD = 1E9 + 7;

struct Num{
	int a, b;

	Num(int ta = 0, int tb = 0): a(ta), b(tb){
	}
};

Num operator +(const Num &l, const Num &r){
	return Num((l.a + r.a) % MOD, (l.b + r.b) % MOD);
}

Num operator *(const Num &l, const Num &r){
	return Num(((ll)l.a * r.a + 5ll * l.b * r.b) % MOD, ((ll)l.a * r.b + (ll)l.b * r.a) % MOD);
}

ll modExp(ll e, ll n, ll m = MOD){
	ll ret = 1;
	for (; n; n >>= 1, e = e * e % m)
		if (n & 1)
			ret = ret * e % m;
	return ret;
}

Num modExp(Num e, ll n){
	Num ret(1);
	for (; n; n >>= 1, e = e * e)
		if (n & 1)
			ret = ret * e;
	return ret;
}

Num modSum(Num e, ll n){
	Num ret(0), s(e);
	for (; n; n >>= 1, s = s * e + s, e = e * e)
		if (n & 1)
			ret = ret * e + s;
	return ret;
}

ll c[MAXK][MAXK];

void init(){
	for (int i = 0; i < MAXK; ++i){
		c[i][0] = c[i][i] = 1;
		for (int j = 1; j < i; ++j)
			c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % MOD;
	}
}

int solve(ll n, int K){
	n += 2;

	static ll e[MAXK];
	e[0] = 1;
	for (int i = 2; i <= K; ++i)
		e[0] = e[0] * i % MOD;
	e[0] = modExp(e[0], MOD - 2);
	for (int i = 0; i < K; ++i){
		e[i + 1] = e[i];
		for (int j = i; j > 0; --j)
			e[j] = (e[j - 1] - e[j] * i % MOD + MOD) % MOD;
		e[0] = e[0] * i % MOD;
	}

	Num eff(1, 0), ret;
	ll inv2 = modExp(2, MOD - 2), inv5 = modExp(5, MOD - 2);
	for (int i = 1; i <= K; ++i){
		Num toti;
		for (int j = 0; j <= i; ++j)
			toti = toti + modSum(modExp(Num(inv2, inv2), j) * modExp(Num(inv2, MOD - inv2), i - j), n) * (i - j & 1 ? MOD - c[i][j] : c[i][j]);
		eff = eff * Num(0, inv5);
		ret = ret + toti * eff * e[i];
	}
	return ret.a;
}

int main(){
	init();

	int K;
	ll l, r;
	scanf("%d%I64d%I64d", &K, &l, &r);
	printf("%d\n", (int)((solve(r, K) - solve(l - 1, K) + (ll)MOD) % MOD));
	return 0;
}