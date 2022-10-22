//: // ////: ///  / : //// / :
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

map<int, int> cnt;
int A[MAXN], n;

inline int solve() {
	ll s = 0;
	cnt.clear();
	cin >> n;

	for (int i = 1; i <= n; i++) cin >> A[i], s += A[i];

	__int128 t = s;
	t = t * (n - 2);

	if (t % n) return cout << 0 << endl, 0;
	ll f = s - t / n;

	ll ans = 0;
	for (int i = 1; i <= n; i++) {
		ans += cnt[f - A[i]];
		cnt[A[i]]++;
	}

	cout << ans << endl;
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}