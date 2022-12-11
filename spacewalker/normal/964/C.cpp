#include <vector>
#include <algorithm>
#include <iostream>
#include <utility>
#define MOD 1000000009

using namespace std;
typedef long long ll;

ll FMD(ll x) {
	return ((x % MOD) + MOD) % MOD;
}

ll modexp(ll b, ll e) {
	if (e == 0) {
		return 1;
	} else {
		return FMD((e % 2 == 1 ? b : 1) * modexp(FMD(b*b), e/2));
	}
}

ll modinv(ll x) {
	return modexp(x, MOD - 2);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n, a, b, k; cin >> n >> a >> b >> k;
	string sFor; cin >> sFor;
	vector<int> s(k, 0);
	for (int i = 0; i < k; ++i) {
		s[i] = (sFor[i] == '+' ? 1 : -1);
	}
	ll blockSum = 0;
	for (int i = 0; i < k; ++i) {
		ll cTerm = FMD(s[i] * modexp(a, n - i) * modexp(b, i));
		blockSum = FMD(cTerm + blockSum);
	}
	//cout << blockSum << endl;
	ll interBlockRatio = FMD(modexp(b, k) * modinv(modexp(a, k)));
	ll blockCount = (n+1)/k;
	ll geoSum = 0;
	if (interBlockRatio == 1) {
		geoSum = FMD(blockCount);
	} else {
		geoSum = FMD(FMD(modexp(interBlockRatio, blockCount) - 1) * modinv(FMD(interBlockRatio - 1)));
	}
	//cout << "gsvalue: " << geoSum << endl;
	ll ans = FMD(geoSum * blockSum);
	printf("%lld\n", ans);
	return 0;
}