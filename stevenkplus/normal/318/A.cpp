#include <cstdio>
#include <iostream>

using namespace std;

typedef long long ll;

ll N, K;
ll go() {
	cin >> N >> K;
	ll numodds = (N + 1) / 2;
	if (K <= numodds) {
		return 2 * K - 1;
	} else {
		K -= numodds;
		return K * 2;
	}
}

int main() {
	ll ans = go();
	cout << ans << endl;
	return 0;
}