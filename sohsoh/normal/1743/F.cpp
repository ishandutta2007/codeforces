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

const ll MAXN = 3e5 + 10;
const ll MOD = 998244353;

inline ll poww(ll a, ll b) {
	ll ans = 1;
	while (b) {
		if (b & 1) ans = ans * a % MOD;
		a = a * a % MOD;
		b >>= 1;
	}

	return ans;
}

vector<int> S[MAXN], E[MAXN];
set<int> st;
int n;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int s, e;
		cin >> s >> e;
		S[s].push_back(i);
		E[e].push_back(i);
	}

	ll ans = 0;
	for (int i = 0; i < MAXN; i++) {
		for (int e : S[i]) st.insert(e);

		if (!st.empty()) {
			int e = *st.rbegin();
			if (e == 1) ans += poww(2, n - e);
			else ans += poww(3, e - 2) * poww(2, n - e + 1) % MOD;
		}

		for (int e : E[i]) st.erase(e);
	}

	cout << ans % MOD << endl;
	return 0;
}