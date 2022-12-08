#include <bits/stdc++.h>

// #define endl '\n'
using namespace std;
#define ll long long

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int Q;
	cin >> Q;
	ll sum = 0LL;
	ll ct = 0LL;
	ll mx = 0LL;
	multiset<ll> vals;
	int tp;
	ll num;
	cout << fixed << setprecision(10);
	while (Q--) {
		cin >> tp;
		if (tp == 2) {
			double ans = (sum+mx+0.0)/(ct+1.0);
			cout << mx-ans << endl;
		}
		else {
			cin >> num;
			if (mx != 0) vals.insert(mx);
			mx = num;
			multiset<ll>::iterator it = vals.begin();
			while (it != vals.end()) {
				ll cur = *it;
				double avg = (mx + sum + 0.0)/(ct+1.0);
				if (cur < avg) {
					// cout << "here   " << cur << " " << avg << endl;
					sum += cur;
					ct+=1LL;
					it = vals.erase(it);
				}
				else break;
			}
		}
	}
	cin >> Q;
}