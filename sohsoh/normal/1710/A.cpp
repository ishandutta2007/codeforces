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

ll n, m, k, s, A[MAXN];

inline bool solve() {
	s = n * m;
	sort(A + 1, A + k + 1, greater<int>());

	int t = m;

	for (int i = 1; i <= k; i++) {
		int x = A[i] / n;
		if (x < 2 || t <= 0) continue;
		if (t == 1) {
			if (A[1] / n > 2) return true;
			return false;
		}

		t -= x;
	}

	return t <= 0;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		cin >> n >> m >> k;
		for (int i = 1; i <= k; i++) cin >> A[i];

		bool flag = solve();
		swap(n, m);
		flag |= solve();

		cout << (flag ? "Yes" : "No") << endl;
	}
	return 0;
}