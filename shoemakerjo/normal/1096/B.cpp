#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int maxn = 200010;
const int mod = 998244353;
int n;
string s;

int main() {
	cin >> n >> s;
	s = " " + s;


	int nfront = 1;
	int nback = 1;

	for (int i = 2; i <= n; i++) {
		if (s[i] == s[1]) {

			nfront++;
		}
		else break;
	}
	for (int i = n-1; i >= 1; i--) {
		if  (s[i] == s[n]) {
			nback++;
		}
		else break;
	}

	if (nfront == n) {
		ll ans = (n)*(n-1)/2;
		ans = (ans%mod);
		ans = (ans + n)%mod;
		cout << ans << endl;
		return 0;
	}
	if (s[1] == s[n]) {
		cout << (nfront + 1LL) * (nback + 1LL) %mod << endl;
		return 0;
	}

	cout << nfront + nback + 1LL << endl;


}