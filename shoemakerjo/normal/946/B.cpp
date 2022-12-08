#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n, m;
	cin >> n >> m;
	ll a = n, b = m;
	while (true) {
		if (a == 0 || b == 0) break;
		else if (a >= 2*b) {
			a = a % (2*b);
			continue;
		}
		else if (b >= 2*a) {
			b  = b% (2*a);
			continue;
		}
		else break;
	}
	cout << a << " " << b << endl;
	cin >> n;
}