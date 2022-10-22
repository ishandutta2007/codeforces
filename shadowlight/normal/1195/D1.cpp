#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll INF = 998244353;

ll power(ll a, ll k) {
	if (!k) {
		return 1;
	}
	ll b = power(a, k / 2);
	b = b * b % INF;
	if (k % 2) {
		return a * b % INF;
	} else {
		return b;
	}
}

void add(ll &x, ll y) {
	x += y;
	if (x >= INF) {
		x -= INF;
	}
}

int main() {
	//freopen("D.in", "r", stdin);
	//freopen("D.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	ll n;
	cin >> n;
	ll res = 0;
	for (ll i = 0; i < n; i++) {
		string s;
		cin >> s;
		vector <ll> a;
		for (char c : s) {
			a.push_back(c - '0');
		}
		//sort(a.begin(), a.end());
		for (ll pos = 0; pos < (ll) a.size(); pos++) {
			ll now = a[pos] * (power(10, 2 * (a.size() - pos - 1)) + power(10, 2 * (a.size() - pos - 1) + 1)) % INF;
			add(res, n * now % INF);
		}
	}
	cout << res << "\n";
}