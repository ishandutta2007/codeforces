#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

#define all(x)			(x).begin(),(x).end()
#define X			first
#define Y			second
#define sep			' '
#define endl			'\n'
#define debug(x)		cerr << #x << ": " <<  x << endl;
#define int			ll

const ll MAXN = 1e6 + 10;
const ll MOD = 1e9 + 7;

int n, fact[MAXN], base[MAXN], LPF[MAXN], base_cnt[MAXN], par[MAXN], f[MAXN];
bool flag = true;

int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	fill(base, base + MAXN, 1);

	cin >> n;
	fact[0] = 1;
	for (int i = 1; i <= n; i++)
		fact[i] = fact[i - 1] * i % MOD;

	for (int i = 2; i <= n; i++) {
		if (!LPF[i]) {
			f[n / i]++;
			for (int j = i; j < MAXN; j += i) {
				base[j] *= i;
				LPF[j] = i;			
			}

			if ((i << 1) > n) base[i] = 1;
		}
	}

	for (int i = 1; i <= n; i++)
		base_cnt[base[i]]++;

	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		if (!x) continue;

		if (base[i] == base[x]) {
			if (base[i] > 1 && LPF[i] * LPF[i] > n) {
				flag &= (!(par[LPF[i]] && par[LPF[i]] != LPF[i]));	
				if (!par[LPF[i]]) f[n / LPF[i]]--;	
				par[LPF[i]] = LPF[i];
			}

			base_cnt[base[i]]--;
		} else {
			flag &= ((base[i] - 1) * (base[x] - 1) > 0);
			if (i > 1 && x > 1 && base[i / LPF[i]] == base[x / LPF[x]] &&
					LPF[i] * LPF[i] > n && LPF[x] * LPF[x] > n) {
				flag &= (n / LPF[i] == n / LPF[x]);
				flag &= (!(par[LPF[x]] && par[LPF[x]] != LPF[i]));
				if (!par[LPF[x]]) f[n / LPF[x]]--;
				par[LPF[x]] = LPF[i];
				base_cnt[base[i]]--;
			} else flag = false;
		}
	}

	ll ans = 1;
	for (int i = 1; i < MAXN; i++)
		ans = ans * fact[base_cnt[i]] % MOD;
	for (int i = 2; i < MAXN; i++)
		ans = ans * fact[f[i]] % MOD;

	cout << (flag ? ans : 0) << endl;
	return 0;
}