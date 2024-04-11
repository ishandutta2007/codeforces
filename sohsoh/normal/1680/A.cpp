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

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int l1, r1, l2, r2;
		cin >> l1 >> r1 >> l2 >> r2;

		if (max(l1, l2) <= min(r1, r2))
			cout << max(l1, l2) << endl;
		else cout << l1 + l2 << endl;
	}
	return 0;
}