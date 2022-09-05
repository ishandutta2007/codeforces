#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define RFOR(i,b,a) for (int i = (b) - 1; i >= (a); i--)
#define ITER(it,a) for (__typeof(a.begin()) it = a.begin(); it != a.end(); it++)
#define FILL(a,value) memset(a, value, sizeof(a))
 
#define SZ(a) (int)a.size()
#define ALL(a) a.begin(), a.end()
#define PB push_back
#define MP make_pair
 
typedef long long Int;
typedef vector<int> VI;
typedef pair<int, int> PII;
 
const double PI = acos(-1.0);
const int INF = 1000 * 1000 * 1000;
const Int LINF = INF * (Int) INF;
const int MAX = 1000007;
const int MOD = 1000000007;

Int F[MAX];
Int IF[MAX];

Int bpow(Int a, int k) {
	Int res = 1;
	while (k) {
		if (k & 1) {
			res *= a;
			res %= MOD;
		}
		a *= a;
		a %= MOD;
		k /= 2;
	}
	return res;
}

Int C(int n, int k) {
	if (k < 0 || k > n)
		return 0;
	return F[n] * IF[k] % MOD * IF[n - k] % MOD;
}


Int g(int n, int k) {
	Int res = 0;
	FOR(i,0,n + 1) {
		Int val = (i > 0 ? 1LL * (i + 2) * bpow(2, i - 1) % MOD : 1);
		res += C(n - i, k) * val % MOD;
		res %= MOD;
	}
	return res;
}

int main(int argc, char* argv[])
{
	ios::sync_with_stdio(false); cin.tie(0);
	mt19937 rng(time(0));

	F[0] = 1;
	FOR(i,1,MAX)
		F[i] = F[i - 1] * i % MOD;
	FOR(i,0,MAX) {
		IF[i] = bpow(F[i], MOD - 2);
	}


	int t;
	cin >> t;


	Int inv2 = (MOD + 1) / 2;
	FOR(tt,0,t) {
		int n, m;
		Int k;
		cin >> n >> m >> k;
		if (m == 0) {
			cout << 0 << endl;
			continue;
		}
		// cout << g(n - 1, n - m) << endl;
		cout << g(n - 1, n - m) * bpow(bpow(2, n - 1), MOD - 2) % MOD * k % MOD << endl;
	}
	
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	return 0;
}