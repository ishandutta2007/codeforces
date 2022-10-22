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

int A[MAXN], n;

inline int solve() {
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> A[i];

	if (n == 1) return cout << 0 << endl, 0;
	cout << n - 1 << endl;
	cout << 1 << sep << n << endl;

	if ((A[1] + A[n]) & 1) A[n] = A[1];
	else A[1] = A[n];

	for (int i = 2; i < n; i++) {
		if ((A[1] + A[i]) & 1) cout << 1 << sep << i << endl;
		else cout << i << sep << n << endl;
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