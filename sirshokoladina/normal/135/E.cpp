#include <iostream>

using namespace std;

#define forn(i,n) for (int i = 0; i < int(n); i++)

typedef long long ll;

const int p = 1000000007;

int pow(int a, int n) {
	if (n == 0) {
		return 1;
	}
	int b = pow(a, n >> 1);
	b = ll(b) * b % p;
	if (n & 1) {
		b = ll(b) * a % p;
	}
	return b;
}

int k;
int ff[1000100];

int calc(int m) {
	int ans = ll(pow(k, m) + p - 1) * pow(k - 1, p - 2) % p;
	forn (i, k) {
		if (i + 1 <= m - 1) {
			ans = (ll(pow(k, m - i - 2)) * (ll(ff[i + 1]) * ff[i + 1] % p) + ans) % p;
		} else {
			ans = (ll(pow(ff[i - m + 2], p - 2)) * (ll(ff[i + 1]) * ff[i + 1] % p) + ans ) % p;
		}
	}
	return ans;
}

int main() {
	int m;
	cin >> k >> m;
	if (k == 1) {
		cout << 1;
		return 0;
	}
	ff[0] = 1;
	forn (i, k) {
		ff[i + 1] = ll(ff[i]) * (k - i) % p;
	}
	cout << (calc(m + 1) + p - calc(m)) % p << endl;
	return 0;
}