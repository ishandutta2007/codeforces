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

int n, f[MAXN], cnt[MAXN], A[MAXN], L[MAXN], R[MAXN];

inline void solve() {
	for (int i = 0; i < n + 10; i++)
		L[i] = R[i] = cnt[i] = f[i] = 0;

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> A[i];
		if (!L[A[i]]) L[A[i]] = i;
		R[A[i]] = i;
	}

	for (int i = 1; i <= n; i++) {
		if (!L[i]) continue;

		f[L[i]]++;
		f[R[i]]--;
		cnt[L[i]]++;
	}

	for (int i = 1; i <= n; i++) {
		f[i] += f[i - 1];
		cnt[i] += cnt[i - 1];
	}

	if (is_sorted(A + 1, A + n + 1)) {
		cout << 0 << endl;
		return;
	}

	int ans = n;
	for (int i = n; i > 0; i--) {
		if (!f[i]) ans = min(ans, cnt[i]);
		if (i < n && A[i] > A[i + 1]) break;
	}

	cout << ans << endl;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}