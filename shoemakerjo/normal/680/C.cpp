#include <bits/stdc++.h>

using namespace std;

bool isprime(int u) {
	for (int i = 2; i <= sqrt(u); i++) {
		if (u%i == 0) return false;
	}
	return true;
}

int main() {
	// ios_base::sync_with_stdio(false);
	// cin.tie(NULL);
	vector<int> div;
	string cur;
	for (int i = 2; i <= 50; i++) {
		if (isprime(i)) {
			cout << i << endl;
			fflush(stdout);
		}
		else continue;
		cin >> cur;
		if (cur == "yes") {
			div.push_back(i);
		}

	}
	if (div.size() == 0) {
		cout << "prime" << endl;
	}
	else if (div.size() > 1) {
		cout << "composite" << endl;
	}
	else {
		bool ok = true;
		for (int i = div[0]*div[0]; i <= 100; i*=div[0]) {
			cout << i << endl;
			fflush(stdout);
			cin >> cur;
			if (cur == "yes") {
				ok = false;
				break;
			}
		}
		if (ok) cout << "prime" << endl;
		else cout << "composite" << endl;
	}
}