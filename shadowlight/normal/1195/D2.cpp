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
	vector <vector <ll> > b;
	vector <ll> szs(11, 0);
	for (ll i = 0; i < n; i++) {
		string s;
		cin >> s;
		vector <ll> a;
		for (char c : s) {
			a.push_back(c - '0');
		}
		b.push_back(a);
		szs[a.size()]++;
	}
	for (ll i = 0; i < n; i++) {
		auto a = b[i];
		for (ll len2 = 0; len2 <= 10; len2++) {
			if (!szs[len2]) continue;
			for (ll pos = 0; pos < (ll) a.size(); pos++) {
				ll now;
				if (a.size() - pos > len2) {
					now = 2 * a[pos] * power(10, a.size() + len2 - pos - 1) % INF;
				} else {
					ll sz = min((ll) a.size(), len2);
					ll posn = pos;
					if (a.size() >= len2) {
						posn -= a.size() - len2;
					}
					//cout << a.size() << " " << len2 << "\n";
					now = a[pos] * (power(10, 2 * (sz - posn - 1)) + power(10, 2 * (sz - posn - 1) + 1)) % INF;
				}
				add(res, szs[len2] * now % INF);
			}
		}
	}
	cout << res << "\n";
}