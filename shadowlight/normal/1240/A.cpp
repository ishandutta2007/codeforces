#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector <ll> p(n);
	for (int i = 0; i < n; i++) {
		cin >> p[i];
	}
	sort(p.rbegin(), p.rend());
	ll x, a, y, b, k;
	cin >> x >> a >> y >> b >> k;
	if (x < y) {
		swap(x, y);
		swap(a, b);
	}
	int lt = 0, rt = n + 1;
	ll d = a * b / __gcd(a, b);
	//cout << d << "\n";
	while (rt - lt > 1) {
		int mid = (lt + rt) / 2;
		ll now = 0;
		ll pos = 0;
		for (ll i = d; i <= mid; i += d) {
			now += (x + y) * p[pos++] / 100; 
		}
		for (ll i = a; i <= mid; i += a) {
			if (i % d == 0) continue;
			now += x * p[pos++] / 100;
		}
		for (ll i = b; i <= mid; i += b) {
			if (i % d == 0) continue;
			now += y * p[pos++] / 100;
		}
		if (now >= k) {
			rt = mid;
		} else {
			lt = mid;
		}
	}
	cout << (rt == n + 1 ? -1 : rt) << "\n";
}

int main(){
#ifdef LOCAL
	freopen("A_input.txt", "r", stdin);
	//freopen("A_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int q;
	cin >> q;
	for (int i = 0; i < q; i++) {
		solve();
	}
}