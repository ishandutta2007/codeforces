#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;
	set<int> in;
	int x[n];
	int y[n];
	for (int i = 0; i < n; i++) {
		cin >> x[i];
		in.insert(x[i]);
	}
	for (int i = 0; i < n; i++) {
		cin >> y[i];
		in.insert(y[i]);
	}
	int ct = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (in.count(x[i] ^ y[j]) > 0) {
				ct++;
			}
		}
	}
	// cout << ct << endl;
	if (ct%2 == 0) {
		cout << "Karen\n";
	}
	else cout << "Koyomi\n";
	// cin >> ct;
}