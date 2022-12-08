#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n;
	cin >> n;
	n--; //weird stuff
	ll ans = 0LL;
	vector<int> bw; //bitwise representation
	ll tmp = n;
	while (tmp > 0) {
		if (tmp & 1) {
			bw.push_back(1);
		}
		else bw.push_back(0);
		tmp/=2;
	}
	// reverse(bw.begin(), bw.end());
	for (int i = 0; i < bw.size(); i++) {
		ll cost = 1LL << i;
		ll ct = n >> (i+1);
		if (bw[i] == 1) {
			ct += 1LL;
		}
		// cout << "vals:  " << cost << "  " << ct << endl;
		ans += cost*ct;
	}
	cout << ans << endl;
	cin >> n;



}