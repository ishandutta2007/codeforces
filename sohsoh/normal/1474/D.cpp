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

ll poww(ll a, ll b, ll md) {
	return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXN = 1e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll n, A[MAXN], B[MAXN], suff_odd[MAXN], suff_even[MAXN], pref_odd[MAXN], pref_even[MAXN];

ll k = 0;

inline int solve() {
	k++;
	fill(suff_odd, suff_odd + n + 10, 0);
	fill(suff_even, suff_even + n + 10, 0);

	cin >> n;
	for (int i = 1; i <= n; i++) cin >> A[i];
	for (int i = 1; i <= n; i++) B[i] = A[i] - B[i - 1];	
	
	suff_odd[n + 1] = INF;
	suff_even[n + 1] = INF;
	pref_even[0] = INF;
	pref_odd[0] = INF;
	for (int i = n; i > 0; i--) {
		suff_odd[i] = suff_odd[i + 1];
		suff_even[i] = suff_even[i + 1];
		if (i & 1) suff_odd[i] = min(suff_odd[i], B[i]);
		else suff_even[i] = min(suff_even[i], B[i]);
	}

	for (int i = 1; i <= n; i++) {
		pref_odd[i] = pref_odd[i - 1];
		pref_even[i] = pref_even[i - 1];
		if (i & 1) pref_odd[i] = min(pref_odd[i], B[i]);
		else pref_even[i] = min(pref_even[i], B[i]);
	}
	
	if (B[n] == 0 && min(suff_odd[1], suff_even[1]) >= 0) return cout << "YES" << endl, 0;
	for (int i = 1; i < n; i++) {
		if (pref_odd[i - 1] < 0 || pref_even[i - 1] < 0) continue;
		int x = A[i], y = A[i + 1];		
		
		if (i & 1) {
			if (B[i] + (y - x) >= 0 && suff_odd[i + 1] + 2 * (y - x) >= 0 && suff_even[i + 1] + 2 * (x - y) >= 0) {
				if (n & 1) {
					if (B[n] + 2 * (y - x) == 0) return cout << "YES" << endl, 0;
				} else {
					if (B[n] + 2 * (x - y) == 0) return cout << "YES" << endl, 0;
				}
				
			}  
		} else {
			if (B[i] + (y - x) >= 0 && suff_even[i + 1] + 2 * (y - x) >= 0 && suff_odd[i + 1] + 2 * (x - y) >= 0) {
				if (n & 1) {
					if (B[n] + 2 * (x - y) == 0) return cout << "YES" << endl, 0;
				} else {
					if (B[n] + 2 * (y - x) == 0) return cout << "YES" << endl, 0;
				}
				
			} 	
		}
	}

	cout << "NO" << endl;
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}