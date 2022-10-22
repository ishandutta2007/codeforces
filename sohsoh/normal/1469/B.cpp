#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
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

int A[MAXN], B[MAXN], ps1[MAXN], ps2[MAXN], n, m;

inline int solve() {
	cin >> n;
	int m1 = 0, m2 = 0;
	for (int i = 1; i <= n; i++) {
		cin >> A[i];
		ps1[i] = ps1[i - 1];
		ps1[i] += A[i];
		m1 = max(m1, ps1[i]);
	}

	cin >> m;
	for (int i = 1; i <= m; i++) {
		cin >> B[i];
		ps2[i] = ps2[i - 1];
		ps2[i] += B[i];
		m2 = max(m2, ps2[i]);
	}

	cout << m1 + m2 << endl;
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) solve(); 
	return 0;
}