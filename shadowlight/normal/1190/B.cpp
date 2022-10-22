#include <bits/stdc++.h>
#define ll long long

using namespace std;

bool good(vector <ll> a) {
	int n = a.size();
	sort(a.begin(), a.end());
	for (int i = 0; i < n - 1; i++) {
		if (a[i] == a[i + 1]) {
			return false;
		}
	}
	return true;
}

void win(bool a) {
	if (a) {
		cout << "sjfnb\n";
	} else {
		cout << "cslnb\n";
	}
	exit(0);
}

int main() {
	//reopen("B.in", "r", stdin);
	//freopen("B.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	vector <ll> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	if (!good(a)) {
		for (int i = 0; i < n - 1; i++) {
			if (a[i] == a[i + 1]) {
				if (a[i]) {
					a[i]--;
				}
				break;
			}
		}
		if (!good(a)) {
			win(false);
		}
		ll sum = 0;
		for (int i = 0; i < n; i++) {
			sum += a[i];
		}
		ll need = (n - 1) * (ll) n / 2;
		win((sum - need) % 2 == 0);
	}
	ll sum = 0;
	for (int i = 0; i < n; i++) {
		sum += a[i];
	}
	ll need = (n - 1) * (ll) (n) / 2;
	win((sum - need) % 2);
}