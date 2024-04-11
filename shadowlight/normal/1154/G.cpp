#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int MAXN = 1e7 + 7;
const ll INF = 1e18 + 7;
const int MINF = 1e9 + 7;

int main() {
	//freopen("G.in", "r", stdin);
	//freopen("G.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	ll n;
	cin >> n;
	vector <pair <int, int> > a(MAXN, {-1, -1});
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		a[x].second = a[x].first;
		a[x].first = i;
	}	
	ll res = INF;
	ll x, y;
	for (ll i = 1; i < MAXN; i++) {
		ll pr = -1;
		for (ll d = i; d < MAXN; d += i) {
			if (a[d].first == -1) continue;
			if (pr != -1) {
				if (res > d * pr / i) {
					res = d * pr / i;
					//cout << d << " " << pr << " " << i << "\n";
					x = a[pr].first, y = a[d].first;
				}
				break;
			}
			if (a[d].second != -1) {
				if (res > d * d / i) {
					res = d * d / i;
					//cout << d << " " << d << " " << i << "\n";
					x = a[d].first, y = a[d].second;
				}
				break;
			}
			pr = d;
		}
	}
	if (x > y) swap(x, y);
	cout << x + 1 << " " << y + 1 << "\n";
}