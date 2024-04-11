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

const ll MAXN = 1e3 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

int n;
bool G1[MAXN][MAXN], M[MAXN][MAXN], C[MAXN], R[MAXN];

inline bool Majik() {
	for (int i = 1; i <= n; i++) C[i] = R[1] ^ M[1][i];
	for (int i = 1; i <= n; i++) R[i] = C[1] ^ M[i][1];
	for (int i = 2; i <= n; i++) 
		for (int j = 2; j <= n; j++) 
			if (R[i] ^ C[j] ^ M[i][j])
				return false;
	return true;	
}

inline int solve() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			char c;
			cin >> c;
			G1[i][j] = bool(c - '0');
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			char c;
			cin >> c;
			M[i][j] = G1[i][j] ^ bool(c - '0');
		}
	}

	R[1] = 0;
	if (Majik()) return cout << "YES" << endl, 0;
	R[1] = 1;
	if (Majik()) return cout << "YES" << endl, 0;
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