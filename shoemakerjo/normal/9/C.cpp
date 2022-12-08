#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string n;
	cin >> n;
	int ans = 0;
	int pows[11];
	pows[0] = 1;
	for (int i = 1; i <= 10; i++) {
		pows[i] = pows[i-1]*2;
	}
	int nl = n.length();
	for (int i = 0; i < n.length(); i++) {
		if (n[i] > '0') { //then we can fix it like a zero
			ans += pows[nl-i-1];
		}
		if (n[i] > '1') { //then we can fix it as a one
			ans += pows[nl-i-1];
			break; //everything afterwards is already covered
		}
	}
	bool ok = true;
	for (int i = 0; i < nl; i++) {
		if (n[i] != '0' && n[i] != '1') ok = false;
	}
	if (ok) ans++;
	ans--; //subtract out 0
	cout << ans << endl;
	cin >> n;
}