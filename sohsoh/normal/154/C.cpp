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

const ll MAXN = 1e6 + 10;
const ll MOD = 1e9 + 7;
const ll P = 23;
const ll P2 = 31;

map<pll, int> cnt;
ll ans = 0, pw[MAXN], pw2[MAXN];
pll hsh[MAXN];
int n, m;

inline void add(int u, int v) {
	hsh[u].X = (hsh[u].X + pw[v]) % MOD;
	hsh[u].Y = (hsh[u].Y + pw2[v]) % MOD;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	pw[0] = pw2[0] = 1;
	for (int i = 1; i < MAXN; i++)
		pw[i] = pw[i - 1] * P % MOD, pw2[i] = pw2[i - 1] * P2 % MOD;

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		add(u, v);
		add(v, u);
	}

	for (int i = 1; i <= n; i++) {
		pll hp = hsh[i];
		add(i, i);
		ans += cnt[hsh[i]];
		ans += cnt[hp];
		cnt[hsh[i]]++;
		cnt[hp]++;
	}

	cout << ans << endl;
	return 0; 
}