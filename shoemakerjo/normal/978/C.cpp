#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector<ll> pref;
	pref.push_back(0LL);
	ll sum = 0LL;
	ll cur;
	for (int i = 0; i < n; i++) {
		cin >> cur;
		sum += cur;
		pref.push_back(sum);
	}
	while (m--) {
		cin >> cur;
		int ind = lower_bound(pref.begin(), pref.end(), cur) - pref.begin();
		--ind;
		cout << ind+1 << " " << cur-pref[ind] << endl;


	}
	cin >> n;

}