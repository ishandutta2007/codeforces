#pragma GCC diagnostic ignored "-Wunused-result"
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int N = (int)1e6 + 34;
const ll INF = (ll)1e18 + 41;
// const int INF = (int)1e9 + 41;
const ll MD = (ll)1e9 + 7;
bool D = false;

void solve() {	

	vector<int> p;
	vector<bool> u(4431, false);
	for (int i = 2; i < (int)u.size(); i++) {
		if (u[i]) continue;
		p.push_back(i);
		for (int j = i * i; j < (int)u.size(); j += i) u[j] = true;
	}

	int n;
	cin >> n;
	vector<int> a(n);
	int g = 0;
	for (auto &x : a) {
		cin >> x;
		g = __gcd(g, x);
	}
	for (auto &x : a) x /= g;
	vector<int> num((int)1.5e7 + 3431, 0);
	for (auto x : a) {
		for (int i = 0; p[i] * p[i] <= x; i++) {
			if (x % p[i]) continue;
			num[p[i]]++;
			while (x % p[i] == 0) x /= p[i];
		}
		if (x > 1) num[x]++;
	}
	int mx = *max_element(num.begin(), num.end());
	if (mx == 0) cout << "-1\n";
	else cout << n - mx << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tst = 1;
	//cin >> tst;
#ifdef MADE_BY_SERT
	D = true;	
	tst = 1;
	while (tst--) {
		solve();
	}
#else
	while (tst--) solve();
#endif
}