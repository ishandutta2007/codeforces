#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll X, d;
	cin >> X >> d;
	ll curcon = 1LL;
	vector<ll> ans;
	for (int i = 35; i >= 0; i--) {
		if (X & (1LL << i)) {
			//add i guys to the spot
			for (int j = 0; j < i; j++) {
				ans.push_back(curcon);
			}
			curcon += d;
			ans.push_back(curcon);
			curcon += d;
		}
	}
	cout << ans.size() << endl;
	for (auto v : ans) cout << v << " ";
	cout << endl;
	cin >> d;
}