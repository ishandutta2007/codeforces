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

int A[MAXN], B[MAXN];

inline int solve() {
	int n, x, y;
	cin >> n >> x >> y;

	vector<int> vec;
	for (int i = 1; i <= n; i++) {
		char c;
		cin >> c;
		A[i] = int(c - '0');
	}

	for (int i = 1; i <= n; i++) {
		char c;
		cin >> c;
		B[i] = int(c - '0');

		if (A[i] != B[i]) vec.push_back(i);
	}

	if (vec.empty()) return cout << 0 << endl, 0;
	if (int(vec.size()) & 1) return cout << -1 << endl, 0;
	if (vec.size() > 2 || vec[0] < vec[1] - 1) cout << 1ll * vec.size() / 2 * y << endl;
	else cout << min(2 * y, x) << endl;
	
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}