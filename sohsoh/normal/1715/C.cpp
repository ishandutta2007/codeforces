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

int A[MAXN], n, m;
ll ans = 0;

inline ll f(ll ind) {
	if (ind >= n || ind < 1) return 0;
	return ind * (n - ind) * int(A[ind] != A[ind + 1]);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	
	ans = 1ll * (n + 1) * n / 2;
	for (int i = 1; i <= n; i++) {
		cin >> A[i];
		ans += f(i - 1);
	}

	while (m--) {
		int ind, x;
		cin >> ind >> x;
		ans -= f(ind);
		ans -= f(ind - 1);

		A[ind] = x;
		ans += f(ind);
		ans += f(ind - 1);

		cout << ans << endl;
	}
	return 0;
}