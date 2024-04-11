#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
#define repi(i, a) for(typeof((a).begin()) i = (a).begin(), _##i = (a).end(); i != _##i; ++i)

const int lim = 100100;
const int MAXQ = 10010000;

ll N;

int ans = 0;

void check(ll p, ll q, ll r) {
	ll a = p + r - q;
	ll b = p + q - r;
	ll c = q + r - p;
	if (a > 0 && b > 0 && c > 0 && a % 2 == 0) {
		int num = 3;
		if (a == b) --num;
		if (b == c) --num;
		if (a == c) --num;
		if (num == 0) ++num;
		if (num == 1) {
			ans += 1;
		} else if (num == 2) {
			ans += 3;
		} else if (num == 3) {
			ans += 6;
		}
	}
}

int nxt[MAXQ];
int main() {
	cin >> N;
	if (N % 3) {
		cout << "0\n";
		return 0;
	}
	N /= 3;

	int prv = 0;
	for(ll q = 1; q * q <= N; ++q) {
		if (N % q == 0) {
			nxt[prv] = q;
			prv = q;
		}
	}
	nxt[prv] = N;

	for(int p = 1; p <= lim; ++p) {
		if (N % p == 0) {
			ll m = N / p;
			for (ll q = p; q * q <= m; q = nxt[q]) {
				if (m % q == 0) {
					ll r = N / p / q;
					check(p, q, r);
				}
			}
		}
	}

	cout << ans << "\n";
}