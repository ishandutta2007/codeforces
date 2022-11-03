#include <cstdio>
#include <vector>

using namespace std;

typedef long long ll;

const int MAXN = 3E5 + 10, MAXK = 19, MAXT = 3E5 + 10;
const ll MOD = 1E9 + 7;

int n;
ll com[MAXN], c[MAXN];

vector<int> divisor[MAXT];
int cnt[MAXT][MAXK];

ll expMod(ll e, ll n, ll m = MOD){
	ll ret = 1;
	for (; n ; n >>= 1, e = e * e % m)
		if (n & 1)
			ret = ret * e % m;
	return ret;
}

void getDivisor(){
	for (int i = 2; i < MAXT; ++i){
		if (divisor[i].size())
			continue;
		for (int j = i; j < MAXT; j += i)
			divisor[j].push_back(i);
	}
}

void getCoefficents(){
	ll e = MOD + 1 - expMod(2, n - 1);
	com[0] = 1;
	for (int i = 1; i <= n; ++i)
		com[i] = com[i - 1] * i % MOD;
	for (int i = 1; i <= n; ++i){
		c[i] = (c[i - 1] + e) % MOD;
		e = (e + com[n] * expMod(com[i] * com[n - i] % MOD, MOD - 2)) % MOD;
	}
}

int main(){
	scanf("%d", &n);
	getDivisor();
	getCoefficents();

	for (int t, i = 0; i < n; ++i){
		scanf("%d", &t);
		while (t > 1){
			int s = 0, p = divisor[t][0];
			for (; t % p == 0; t /= p, ++s);
			++cnt[p][s];
		}
	}

	ll ans = 0;
	for (int i = 2; i < MAXT; ++i){
		cnt[i][0] = n;
		for (int j = 1; j < MAXK; ++j)
			cnt[i][0] -= cnt[i][j];

		for (int j = 1; j < MAXK; ++j){
			cnt[i][j] += cnt[i][j - 1];
			ans = (ans + j * (c[cnt[i][j]] - c[cnt[i][j - 1]] + MOD)) % MOD;
		}
	}
	printf("%d\n", (int)ans);
	return 0;
}