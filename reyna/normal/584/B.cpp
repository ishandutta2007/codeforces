//In the name of God
#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
long long pw(long long a, int b) {
	return b? (pw(a * a % mod, b >> 1) * (b & 1? a: 1)) % mod: 1;	
}
int main() {
	int n; cin >> n;
	cout << (pw(27, n) - pw(7, n) + mod) % mod;	
}