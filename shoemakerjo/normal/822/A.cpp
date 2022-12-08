#include <iostream>
#include <cmath>
#define ll long long
using namespace std;

int main() {
	ll A, B;
	cin >> A >> B;
	ll ans = 1;
	ll low = min(A,B);
	for (ll i = 1; i <= low; i++) {
		ans*=i;
	}
	cout << ans << endl;
	// cin >> A;
}