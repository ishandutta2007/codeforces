#pragma GCC diagnostic ignored "-Wunused-result"
#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;

ll getSum(const vector<ll> &p, int l, int r) {
	return p[r] - p[l];
}

void solve() {
	int n;
	cin >> n;
	vector<ll> a(n), p(n + 1, 0);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a.rbegin(), a.rend());
	for (int i = 0; i < n; i++) {
		p[i + 1] = p[i] + a[i];
	}
	ll X, A, Y, B, k;
	cin >> X >> A >> Y >> B >> k;
	if (X < Y) {
		swap(X, Y);
		swap(A, B);
	}
	ll G = A * B / __gcd(A, B);

	int r = n + 1;
	int l = 0;
	while (r - l > 1) {
		int m = (l + r) / 2;
		int t1 = m / A;
		int t2 = m / B;
		int t12 = m / G;
		t1 -= t12;
		t2 -= t12; 
		ll score = getSum(p, 0, t12) * (X + Y) / 100;
		score += getSum(p, t12, t12 + t1) * X / 100;
		score += getSum(p, t12 + t1, t12 + t1 + t2) * Y / 100;
		if (score >= k) r = m;
		else l = m;
	}
	if (r == n + 1) cout << "-1\n";
	else cout << r << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while (t--) solve();
}