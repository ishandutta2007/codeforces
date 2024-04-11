#include <bits/stdc++.h>\

using namespace std;

int main() {
	int x;
	cin >> x;
	while (x % 10 == 0 && x != 0) {
		x /= 10;
	}
	string line = to_string(x);
	bool ok = true;
	for (int i = 0; i < line.length(); i++) {
		if (line[i] != line[line.length()-i-1]) {
			ok = false;
		}
	}
	if (ok) cout << "YES\n";
	else cout << "NO\n";
	// cin >> x;
}