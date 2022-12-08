#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n;
	cin >> n;
	int q;
	cin >> q;
	ll x;
	while (q--) {
		cin >> x;
		ll spot = x;
		while (x% 2 != 1) {
			x = n + x/2;
		}
		// cout << "ans:  "; //just to make printout clear, comment out later
		cout << (x+1)/2 << endl;
	}
	cin >> n;
}