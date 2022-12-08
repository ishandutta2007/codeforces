#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	set<int> diff;
	for (int i = 1; i < n; i++) {
		diff.insert(abs(a[i-1]-a[i]));
	}
	if (diff.count(1) > 0) {
		diff.erase(diff.find(1));
	}
	if (diff.size() > 1) {
		// cout << "wierd  " << *diff.begin() << endl;
		cout << "NO" << endl;
	}
	// cout <<"here " << diff.size() << endl
	else {
		int y = diff.size() > 0 ? *diff.rbegin() : 1000000000;
		if (y == 0) {
			cout << "NO" << endl;
			return 0;
		}
		bool ok = true;
		for (int i = 1; i < n; i++) {
			if (a[i] == a[i-1]+1 && a[i]%y == 1) ok = false;
			if (a[i] == a[i-1]-1 && a[i-1]%y == 1) ok = false;
		}
		if (!ok) {
			cout << "NO" << endl;
			return 0;
		}
		int x = 1;
		for (int i = 0; i < n; i++) {
			if (a[i] % y != 0) x = max(x, (a[i]-(a[i]%y))/y + 1);
			else x = max(x, a[i]/y);
		}
		x = min(x, 1000000000);
		cout << "YES" << endl << x << " " << y << endl;
	}
	cin >> n;
}