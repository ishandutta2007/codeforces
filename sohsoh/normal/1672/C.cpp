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
bool B[MAXN];

inline int solve() {
	for (int i = 0; i < n + 5; i++) B[i] = false;
	int ans = 0, cnt = 0;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> A[i];
		if (i > 1) B[i - 1] = (A[i] == A[i - 1]);
		cnt += B[i - 1];
	}

	for (int i = 1; i < n && cnt > 1; i++) {
		if (B[i]) {
			cnt -= B[i];
			cnt -= B[i + 2];
			cnt += (!B[i + 1]);

			ans++;
			B[i] = false;
			B[i + 2] = false;
			B[i + 1] = true;
		}
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