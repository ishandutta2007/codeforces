#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

#define all(x)                      (x).begin(),(x).end()
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define debug(x)                    cerr << #x << ": " <<  x << endl;

const ll MAXM = 1e7 + 10;
const ll MAXN = 5e5 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

bool ok[MAXM], B[MAXM], T[MAXM];
vector<int> D[MAXN], primes[MAXN];
int A[MAXN], n, cnt[MAXM], ans[MAXN], M[MAXN], p_fact[MAXM], in_seq[MAXM];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> A[i];
		if (!in_seq[A[i]]) in_seq[A[i]] = i;
	}
	
	for (int i = 1; i < MAXM; i++) {	
		if (i > 1 && p_fact[i] == 0) {
			for (int j = i; j < MAXM; j += i) {
				p_fact[j] = i;
				if ((j / i) % i == 0) B[j] = true;
			}
		}

		for (int j = i; j < MAXM; j += i) {
			if (in_seq[j]) {
				D[in_seq[j]].push_back(i);
				if (p_fact[i] == i) primes[in_seq[j]].push_back(i);
			}
		}
	}

	for (int i = 2; i < MAXM; i++)
		T[i] = 1 - T[i / p_fact[i]];

	for (int i = 1; i <= n; i++) {
		int ind = in_seq[A[i]];
		for (int e : D[ind]) {
			cnt[e] = 2 * cnt[e] + 1;
			if (cnt[e] >= MOD) cnt[e] -= MOD;
		}
	}
	
	ll gcd1 = 0;
	for (int i = 1; i < MAXM; i++) {
		if (B[i]) continue;
		if (T[i]) gcd1 -= cnt[i];
		else gcd1 += cnt[i];
	}	
	
	gcd1 = (MAXM * MOD * 10 + gcd1) % MOD;
	
	ll ans = 0;
	for (int i = 1; i <= n; i++) {
		int tind = in_seq[A[i]];
		int MASK = (1 << primes[tind].size());
		M[0] = 1;
		for (int msk = 1; msk < MASK; msk++) {
			int ind = __builtin_ctz(msk);
			M[msk] = M[msk ^ (1 << ind)] * primes[tind][ind];
		}

		for (int msk = MASK - 1; msk >= 0; msk--) {
			if (__builtin_popcount(msk) & 1) ans = ans - cnt[M[msk]];
			else ans = ans + cnt[M[msk]];
		}
		
		ans -= gcd1;
		ans = (ans + MAXN * MOD) % MOD;
	}

	cout << ans << endl;
	return 0;
}