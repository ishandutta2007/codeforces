#include <bits/stdc++.h>
#define ll long long

using namespace std;

vector <ll> a;
ll n, m;

ll cnt(ll d) {
	ll res = 0;
	for (ll i = 0; i < n; i++) {
		res += max(0LL, a[i] - (i / d));
	}
	return res;
}

int main() {
	//freopen("D.in", "r", stdin);
	//freopen("D.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	a.resize(n);
	ll sum = 0;
	for (ll i = 0; i < n; i++) {
		cin >> a[i];
		sum += a[i];
	}
	if (sum < m) {
		cout << "-1\n";
		return 0;
	}
	sort(a.rbegin(), a.rend());
	ll lt = 0, rt = n;
	while (rt - lt > 1) {
		ll mid = (lt + rt) / 2;
		if (cnt(mid) >= m) {
			rt = mid;
		} else {
			lt = mid;
		}
	}
	cout << rt << "\n";
}