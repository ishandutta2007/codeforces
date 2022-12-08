#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <bits/stdc++.h>
#define ll long long
#define bil 1000000000l
using namespace std;


ll gcd(ll n, ll m) {
	ll a;
	while (n != 0) {
		a = m;
		m = n;
		n = a%n;
	}
	return m;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	ll a, b;

	for (int q = 0; q < n; q++) {
		cin >> a >> b;
		ll gc = gcd(a, b);
		// a = a/gc;
		// b = b/gc;
		ll cbr = round(cbrt(a*b));
		bool ok = true;
		if (cbr*cbr*cbr != a*b) ok = false;
		if (a % cbr != 0 || b %cbr !=0) ok = false;
		if (ok) {
			cout << "Yes\n";
			
		}
		else cout << "No\n";
	
	}
	// cout << primes.size() << endl;
	cin >> n;
}