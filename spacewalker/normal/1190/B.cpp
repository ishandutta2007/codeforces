#include <bits/stdc++.h>

using namespace std;
using ll = long long;
constexpr char FIRST_WIN[] = "sjfnb\n";
constexpr char SECOND_WIN[] = "cslnb\n";

bool firstWins(map<ll, int> &occs) {
	ll sum = 0;
	ll ct = 0;
	for (auto pp : occs) {
		if (pp.second == 1) {
			++ct;
			sum += pp.first;
		}
	}
	return ((sum - ((ct - 1) * ct / 2)) % 2 == 1);
}

int main() {
	int n; scanf("%d", &n);
	vector<ll> arr(n);
	for (int i = 0; i < n; ++i) scanf("%lld", &arr[i]);
	map<ll, int> elemct;
	for (ll x : arr) elemct[x]++;
	int totalnd = 0;
	for (auto pp : elemct) if (pp.second > 1) totalnd += pp.second;
	if (totalnd > 2) {
		printf(SECOND_WIN);
		return 0;
	}
	int toLower = -1;
	for (auto pp : elemct) if (pp.second == 2) toLower = pp.first;
	if (toLower == 0 || elemct.count(toLower-1) > 0) {
		printf(SECOND_WIN);
		return 0;
	}
	// now we can actually do it
	bool firstWin = false;
	if (toLower == -1) {
		// all elements 
		firstWin = firstWins(elemct);
	} else {
		elemct[toLower]--;
		elemct[toLower - 1]++;
		firstWin = !firstWins(elemct);
	}
	if (firstWin) printf(FIRST_WIN);
	else printf(SECOND_WIN);
	return 0;
}