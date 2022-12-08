#include <bits/stdc++.h>

using namespace std;

int p, y;

bool isprime(int u) {
	for (int i = 2; i <= sqrt(u) && i <= p; i++) {
		if (u%i == 0) return false;
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> p >> y;
	int cur = y;
	while (cur > p) {
		if (isprime(cur)) {
			cout << cur << endl;
			break;
		}
		cur--;
	}
	if (cur == p) cout << -1 << endl;
	cin >> p;
}