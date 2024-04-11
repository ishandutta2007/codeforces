#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

#define all(x)                      (x).begin(),(x).end()
#define X                           first
#define Y                           second
#define sep                         ' '
#define debug(x)                    cerr << #x << ": " <<  x << endl;

const ll MAXN = 1e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

int A[MAXN], n;

inline int solve() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> A[i];
	
	cout << 3 * n << endl;
	for (int i = 1; i <= n; i += 2) {
		cout << 1 << sep << i << sep << i + 1 << endl;
		cout << 2 << sep << i << sep << i + 1 << endl;
		cout << 1 << sep << i << sep << i + 1 << endl;
		cout << 1 << sep << i << sep << i + 1 << endl;
		cout << 2 << sep << i << sep << i + 1 << endl;
		cout << 1 << sep << i << sep << i + 1 << endl;
	}
	
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}