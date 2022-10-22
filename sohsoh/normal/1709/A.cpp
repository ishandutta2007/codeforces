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

int A[4], x;

inline int solve() {
	cin >> x >> A[1] >> A[2] >> A[3];
	if (!A[x]) return cout << "NO" << endl, 0;
	for (int i = 1; i <= 3; i++)
		if (A[i] == i)
			return cout << "NO" << endl, 0;

	cout << "YES" << endl;
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}