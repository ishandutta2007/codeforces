#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll Mod = (ll)1e9 + 7;

int magic[] = {2, 3, 5, 7, 13, 17, 19, 31, 61, 89, 107, 127, 521, 607, 1279, 2203, 2281, 3217, 4253, 4423, 9689, 9941, 11213, 19937, 21701, 23209, 44497, 86243, 110503, 132049, 216091, 756839, 859433, 1257787, 1398269, 2976221, 3021377, 6972593, 13466917, 20996011, 24036583, 25964951, 30402457, 32582657};

ll qpow(ll a, ll b) {
	ll r = 1;
	for(; b > 0; b /= 2) {
		if(b & 1)
			r = r * a % Mod;
		a = a * a % Mod;
	}
	return r;
}

int main() {
	ios :: sync_with_stdio(false);
	int n; cin >> n;
	cout << qpow(2, magic[n - 1] - 1) - 1 << '\n';
}