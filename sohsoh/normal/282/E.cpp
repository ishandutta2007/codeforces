// \_()_/
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

const ll MAXN = 5e6 + 10;
const ll LOG = 45;

int C[MAXN][2], n, sz = 1;
ll A[MAXN], suff[MAXN], pref[MAXN];

inline void Insert(ll x) {
	int node = 1;
	for (int i = LOG - 1; i >= 0; i--) {
		if (x & (1ll << i)) {
			if (!C[node][1]) C[node][1] = ++sz;	
			node = C[node][1];
		} else {
			if (!C[node][0]) C[node][0] = ++sz;
			node = C[node][0];
		}
	}
}

inline ll Find(ll x) {
	ll ans = 0;
	int node = 1;

	for (int i = LOG - 1; i >= 0; i--) {
		int ind = (x & (1ll << i)) != 0;
		if (C[node][1 - ind]) node = C[node][1 - ind], ans ^= (1ll << i);
		else node = C[node][ind];
	}

	return ans;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> A[i];
		pref[i] = pref[i - 1] ^ A[i];
	}

	for (int i = n; i > 0; i--) suff[i] = suff[i + 1] ^ A[i];
	
	Insert(0);
	ll ans = 0;
	for (int i = 1; i <= n + 1; i++) {
		ans = max(ans, Find(suff[i]));
		Insert(pref[i]);
	}

	cout << ans << endl;
	return 0;
}