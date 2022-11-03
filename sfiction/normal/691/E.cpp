#include <bits/stdc++.h>

#define debug(x) cout << #x" = " << x;

#define st first
#define nd second

using namespace std;
using namespace placeholders;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> PII;
typedef pair<ll, ll> PLL;

const int MAXN = 1E2 + 10;
const ll MOD = 1E9 + 7;

struct mat{
	static int n;
	ll a[MAXN][MAXN];
};

int mat::n;

mat operator *(mat &l, mat &r){
	mat ret;
	for (int i = 0; i < mat::n; ++i)
		for (int j = 0; j < mat::n; ++j)
			ret.a[i][j] = 0;
	for (int i = 0; i < mat::n; ++i)
		for (int k = 0; k < mat::n; ++k)
			for (int j = 0; j < mat::n; ++j)
				ret.a[i][j] = (ret.a[i][j] + l.a[i][k] * r.a[k][j]) % MOD;
	return ret;
}

mat e, res;

int n;
ll a[MAXN];

int main(){
	ll L;
	scanf("%d%I64d", &n, &L);
	--L;
	for (int i = 0; i < n; ++i)
		scanf("%I64d", &a[i]);
	mat::n = n;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			e.a[i][j] = __builtin_popcountll(a[i] ^ a[j]) % 3 == 0;
	for (int i = 0; i < n; ++i)
		res.a[i][0] = 1;
	for (; L; L >>= 1, e = e * e)
		if (L & 1)
			res = e * res;
	ll ans = 0;
	for (int i = 0; i < mat::n; ++i)
		ans = (ans + res.a[i][0]) % MOD;
	printf("%I64d\n", ans);
	return 0;
}