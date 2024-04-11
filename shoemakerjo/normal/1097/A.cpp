#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string as;
	cin >> as;
	bool ok = false;
	string cur;
	for (int i = 0; i< 5; i++) {
		cin >> cur;
		if (cur[0] == as[0] || cur[1] == as[1]) ok = true;
	}
	if (ok) cout << "YES" << endl;
	else cout << "NO" << endl;
}