#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define pii pair<ll, ll>

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	ll x[n], y[n];
	vector<pii> cos;
	for (int i = 0; i < n; i++) {
		cin >> x[i] >> y[i];
		cos.push_back(pii(x[i], y[i]));
	}
	if (n <= 4) {
		cout << "YES" << endl;
		return 0;
	}

	bool ok = false;
	vector<pii> bad; //what is currently bad for this test

	//copy this three times basically
	ll rm = y[1]-y[0];
	ll lm = x[1]-x[0];
	for (int i = 0; i < n; i++) {
		if ((y[i]-y[0])*lm == (x[i]-x[0])*rm) {
			continue;
		}
		bad.push_back(pii(x[i], y[i]));
	}
	if (bad.size() <= 2) {
		ok = true;
	}
	else {
		rm = bad[0].second-bad[1].second;
		lm = bad[0].first-bad[1].first;
		ll y1 = bad[0].second;
		ll x1 = bad[0].first;
		bool cok = true;
		for (int i = 0; i < bad.size(); i++) {
			if ((bad[i].second-y1)*lm == (bad[i].first-x1)*rm) {
				continue;
			}
			cok = false;
		}

		if (cok) ok = true;

	}

	bad.clear();
	rm = y[2]-y[0];
	lm = x[2]-x[0];
	for (int i = 0; i < n; i++) {
		if ((y[i]-y[0])*lm == (x[i]-x[0])*rm) {
			continue;
		}
		bad.push_back(pii(x[i], y[i]));
	}
	if (bad.size() <= 2) {
		ok = true;
	}
	else {
		rm = bad[0].second-bad[1].second;
		lm = bad[0].first-bad[1].first;
		ll y1 = bad[0].second;
		ll x1 = bad[0].first;
		bool cok = true;
		for (int i = 0; i < bad.size(); i++) {
			if ((bad[i].second-y1)*lm == (bad[i].first-x1)*rm) {
				continue;
			}
			cok = false;
		}

		if (cok) ok = true;

	}

	bad.clear();
	rm = y[1]-y[2];
	lm = x[1]-x[2];
	for (int i = 0; i < n; i++) {
		if ((y[i]-y[1])*lm == (x[i]-x[1])*rm) {
			continue;
		}
		bad.push_back(pii(x[i], y[i]));
	}
	if (bad.size() <= 2) {
		ok = true;
	}
	else {
		rm = bad[0].second-bad[1].second;
		lm = bad[0].first-bad[1].first;
		ll y1 = bad[0].second;
		ll x1 = bad[0].first;
		bool cok = true;
		for (int i = 0; i < bad.size(); i++) {
			if ((bad[i].second-y1)*lm == (bad[i].first-x1)*rm) {
				continue;
			}
			cok = false;
		}

		if (cok) ok = true;

	}

	if (ok) {
		cout << "YES" << endl;
	}
	else cout << "NO" << endl;
	cin >> n;


}