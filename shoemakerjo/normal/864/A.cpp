#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;
	int ct[101];
	for (int i = 0; i <= 100; i++) {
		ct[i] = 0;
	}
	int cur;
	for (int i = 0; i < n; i++) {
		cin >> cur;
		ct[cur]++;
	}
	int first = -1, second = -1;
	bool ok = true;
	for (int i = 1; i <= 100; i++) {
		if (ct[i] > 0) {
			if (first == -1) {
				first = i;
			}
			else if (second == -1) {
				second = i;
			}
			else ok = false;
		}
	}
	if (first == -1 || second == -1) {
		cout << "NO\n";
	}
	else if (!ok) {
		cout << "NO\n";
	}
	else if (ct[first] != ct[second]) {
		cout << "NO\n";
	}
	else {
		cout << "YES" << endl << first << " " << second << endl;
	}
	// cin >> n;
}