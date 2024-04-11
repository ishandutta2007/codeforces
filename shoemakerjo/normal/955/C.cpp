#include <bits/stdc++.h>

using namespace std;
#define ll long long
// #define endl '\n'
vector<ll> nums;
set<ll> seen;
const ll big = 1000000000000000000LL;
ll cnums[1000010]; //current powers

bool issquare(ll x) {
	ll cur = sqrt(x);
	return cur*cur == x;
}

bool isprime(int x) {
	for (int i = 2; i <= sqrt(x); i++) {
		if (x%i == 0) return false;
	}
	return true;
}



void buildlist() {
	fill(cnums, cnums+1000010, 1LL);
	for (int i = 1; i <= 1000000; i++) {
		cnums[i] = (i+0LL)*(i+0LL);
	}
	for (int i = 3; i <= 60; i++) {
		if (!isprime(i)) { //still have to mult stuff

			for (int j = 1; cnums[j] <= big/j && j <= 1000000; j++) {
				cnums[j] *= (j+0LL);
			}
			continue;
		}
		for (int j = 1; cnums[j] <= big/j && j <= 1000000; j++) {
			cnums[j]*=(j+0LL);
			ll cur = cnums[j];
			if (seen.count(cur) == 0 && !issquare(cur)) {
				if (cur < 0) {
					cout << "danger at  " << j << " " << i <<  endl;
				}
				seen.insert(cur);
			}
		}

	}
	for (auto v : seen) {
		nums.push_back(v);
	}
}

ll sqcount(ll x) {
	ll val = sqrt(x);
	return val;
}

ll getct(ll x) {
	// cout << x << ":  ";
	ll ans = sqcount(x);
	// cout << ans << " ";
	ll addon = upper_bound(nums.begin(), nums.end(), x)-nums.begin();
	// cout << addon << endl;
	return ans+addon;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	buildlist();
	// cout << nums.size() << endl; //this will be huge
	// for (int i = 0; i < 20; i++) {
	// 	cout << nums[i] << " ";
	// }
	// cout << endl;
	int Q;
	cin >> Q;
	ll L, R;
	while (Q--) {
		cin >> L >> R;
		ll ans = getct(R);
		ans -= getct(L-1LL);
		// cout << "ans  "; //just for debugging
		cout << ans << endl;
	}
	cin >> Q;
}