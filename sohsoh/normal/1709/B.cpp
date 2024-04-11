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

ll n, ps[MAXN], A[MAXN], q, ss[MAXN];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> A[i];
		if (i > 1)
			ps[i - 1] = ps[i - 2] + max(0ll, A[i - 1] - A[i]);
	}

	for (int i = n; i > 0; i--)
		ss[i + 1] = ss[i + 2] + max(0ll, A[i + 1] - A[i]);

	while (q--) {
		int l, r;
		cin >> l >> r;
		if (l <= r) cout << ps[r - 1] - ps[l - 1] << endl;
		else cout << ss[r + 1] - ss[l + 1] << endl;
	}
	return 0;
}