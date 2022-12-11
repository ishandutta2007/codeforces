#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <cmath>

#define NMAX 1000000000000000000
#define AMAX 1000000

using namespace std;
typedef long long ll;

ll firstExceedant(ll x) {
	ll lo = 0;
	ll hi = 1000000000;
	while (lo < hi) {
		ll mid = (lo + hi) / 2;
		if (mid * mid >= x) {
			hi = mid;
		} else {
			lo = mid + 1;
		}
	}
	return lo;
}

bool isSquare(ll x) {
	ll guess = firstExceedant(x);
	return (guess*guess == x);
}

ll squaresUnder(ll x) {
	ll guess = firstExceedant(x);
	return ((guess*guess==x) ? guess : guess-1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	unordered_set<ll> perfectPowers;
	perfectPowers.insert(1);
	for (ll a = 2; a <= AMAX; ++a) {
		ll curp = a*a*a;
		for (ll p = 3; p <= 60; ++p) {
			perfectPowers.insert(curp);
			if (curp >= NMAX/(long double)a) {
				break;
			} else {
				curp *= a;
			}
		}
	}
	vector<ll> ppList;
	int ct = 0;
	ppList.reserve(perfectPowers.size());
	for (ll x : perfectPowers) {
		if (!isSquare(x)) {
			ppList.push_back(x);
		}
	}
	int n = ppList.size();
	sort(ppList.begin(), ppList.end());
	//cout << squaresUnder(NMAX) << " " << squaresUnder(NMAX-1) << endl;
	//printf("finished with prepros\n");
	int q; cin >> q;
	for (int i = 0; i < q; ++i) {
		ll l, r; cin >> l >> r;
		ll squaresInInterval = squaresUnder(r) - squaresUnder(l-1);
		auto firstAtLeastL = lower_bound(ppList.begin(), ppList.end(), l);
		auto firstGreaterThanR = upper_bound(ppList.begin(), ppList.end(), r);
		/*if (firstGreaterThanR == ppList.end()) {
			cout << "booyah!" << endl;
		}
		cout << "sqc ppd " << squaresInInterval << " " << distance(firstAtLeastL, firstGreaterThanR) << endl;*/
		cout << squaresInInterval + distance(firstAtLeastL, firstGreaterThanR) << "\n";
	}
	return 0;
}