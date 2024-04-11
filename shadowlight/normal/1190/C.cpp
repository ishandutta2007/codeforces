#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll n, k;
bool good(set <ll> a) {
	if (!a.size()) {
		return true;
	}
	ll l = *a.begin(), r = *a.rbegin();
	return (r - l) < k;
}

int main() {
	//freopen("C.in", "r", stdin);
	//freopen("C.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin >> n >> k;
	string s;
	cin >> s;
	set <ll> a, b;
	for (ll i = 0; i < n; i++) {
		if (s[i] == '1') {
			b.insert(i);
		} else {
			a.insert(i);
		}
	}
	if (good(a) || good(b)) {
		cout << "tokitsukaze\n";
		return 0;
	}
	bool win = true;
	
	for (ll l = 0; l <= n - k; l++) {
		ll r = l + k - 1;
		int mina = min(*a.begin(), l), maxa = max(*a.rbegin(), r);
		int minb = *b.begin(), maxb = *b.rbegin();
		if (minb >= l) {
			minb = *b.upper_bound(r);
		}
		if (maxb <= r) {
			maxb = *(--b.lower_bound(l));
		}
		if (maxa - mina >= k && maxb - minb >= k) {
			//cout << l << " " << r << " " << 0 << "\n";
			win = false;
			break;
		}

		mina = *a.begin(), maxa = *a.rbegin();
		if (mina >= l) {
			mina = *a.upper_bound(r);
		}
		if (maxa <= r) {
			maxa = *(--a.lower_bound(l));
		}

		minb = min(*b.begin(), l), maxb = max(*b.rbegin(), r);

		if (maxa - mina >= k && maxb - minb >= k) {
			//cout << l << " " << r << " " << 1 << "\n";
			//cout << mina << " " << maxa << " " << minb << " " << maxb << "\n";
			win = false;
			break;
		}

	}


	if (!win) {
		cout << "once again\n";
	} else {
		cout << "quailty\n";
	}
}