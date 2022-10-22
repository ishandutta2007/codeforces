#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll MAXN = 1e6 + 7;

ll cntq(ll n, ll g) {
	ll d = n / g;
	ll res = 0;
	res += (d + 1) * d / 2 * g;
	res += (n - d * g + 1) * (d + 1);
	return res;
}

int main() {
	//freopen("D.in", "r", stdin);
	//freopen("D.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	ll m, a, b;
	cin >> m >> a >> b;
	ll cnt = 0;
	ll g = __gcd(a, b);
	vector <bool> can(MAXN, false);
	can[0] = true;
	cnt++;
	ll res = 0;
	for (ll i = 0; i <= min(m, MAXN - 1); i++) {
		queue <ll> q;
		if (i - a >= 0 && can[i - a]) {
			q.push(i);
			cnt++;
			can[i] = true;
		}
		while (!q.empty()) {
			ll v = q.front();
			q.pop();
			if (v - b >= 0 && !can[v - b]) {
				can[v - b] = true;
				cnt++;
				q.push(v - b);
			}
			if (v + a <= i && !can[v + a]) {
				can[v + a] = true;
				cnt++;
				q.push(v + a);
			}
		}
		res += cnt;
	}
	//cout << res << "\n";
	if (m >= MAXN) {
		res += cntq(m, g) - cntq(MAXN - 1, g);
	}
	cout << res << "\n";
}