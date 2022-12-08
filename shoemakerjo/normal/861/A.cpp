#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll gcd(ll a, ll b) {
	if (a%b == 0) return b;
	if (b%a == 0) return a;
	if (a > b) return gcd(a%b, b);
	return gcd(a, b%a);
}

int main() {
	ll start = 1LL;
	ll n;
	int k;
	cin >> n >> k;
	for (int i = 1; i <= k; i++) {
		start *= 10LL;
	}
	start *= n/(gcd(n, start));
	cout << start << endl;
	// cin >> n;
}