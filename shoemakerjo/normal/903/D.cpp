#include <bits/stdc++.h>

using namespace std;

#define ll unsigned long long
int n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	map<int, int> prev;
	map<int, int> aft;
	int vals[n];
	ll ansp =0LL;
	ll ansn = 0LL;
	for (int i = 0; i < n; i++) {
		cin >> vals[i];
		prev[vals[i]] = 0;
		aft[vals[i]] = 0;
	}
	for (int i = 0; i < n; i++) {
		aft[vals[i]]++;
	}
	for (int i = 0; i < n; i++) {
		int spot = i; //i before
		aft[vals[i]]--;
		spot -= prev[vals[i]];
		if (prev.count(vals[i]-1) > 0) {
			spot -= prev[vals[i]-1];
		}
		if (prev.count(vals[i]+1) > 0) {
			spot -= prev[vals[i]+1];
		}
		ansp += (spot+0LL)*(vals[i]+0LL);
		// cout << "spot   " << spot << "  " << vals[i] << endl;
		spot = n-i-1;
		spot -= aft[vals[i]];
		if (aft.count(vals[i]-1) > 0) {
			spot -= aft[vals[i]-1];
		}
		if (aft.count(vals[i]+1) > 0) {
			spot -= aft[vals[i]+1];
		}
		ansn += (spot+0LL)*(vals[i]+0LL);
		// cout << "second spot   " << spot << "  " << vals[i] << endl;
		prev[vals[i]]++;
	}

	if (ansp >= ansn) {
		ansp -= ansn;
		cout << ansp << endl;
	}
	else {
		ansn -= ansp;
		cout << "-" << ansn << endl;
	}
	cin >> ansp;
}