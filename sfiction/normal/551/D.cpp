/*
 * ID: Sfiction
 * OJ: CF
 * PROB: 550D
 */
#include <cstdio>

typedef long long ll;

ll n, k, m;
int l;

struct Matrix{
	ll a, b, c;
};

Matrix operator*(const Matrix &l, const Matrix &r){
	Matrix ret;
	
	ret.a = l.a * r.a + l.b * r.b;
	ret.b = l.a * r.b + l.b * r.c;
	ret.c = l.b * r.b + l.c * r.c;

	return ret;
}

Matrix operator%(const Matrix &l, ll m){
	Matrix ret;

	ret.a = l.a % m;
	ret.b = l.b % m;
	ret.c = l.c % m;

	return ret;
}

template<typename T>
T quickExp(T e, ll n){
	T ret = e;

	for (--n; n; n >>= 1){
		if (n & 1)
			ret = ret * e % m;
		e = e * e % m;
	}

	return ret;
}

int main(){
	scanf("%I64d%I64d%d%I64d", &n, &k, &l, &m);

	ll a = 1, b = 1, c = 1;
	for (int i=1;i<=n;++i){
		a = (a + b) % m;
		b = (a - b + m) % m;
		c = c * 2 % m;
	}

	if (k != 0 && 64 - __builtin_clzll(k) > l)
		puts("0");
	else if (l == 0)
		putchar('0' + 1 % m);
	else{
		Matrix Fib1 = {1, 1, 0};
		Matrix Fibn = quickExp(Fib1, n + 1);
		ll sum = quickExp(2LL, n);
		ll zero = Fibn.a % m, one = (sum - Fibn.a + m) % m;
		ll ans = 1 % m;
		for (int i=0;i<l;++i)
			if (1LL << i & k)
				ans = ans * one % m;
			else
				ans = ans * zero % m;

		printf("%I64d", ans);
	}

	return 0;
}