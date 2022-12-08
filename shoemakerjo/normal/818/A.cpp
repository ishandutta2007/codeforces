#include <iostream>
#define ll long long
using namespace std;

int main() {
	ll n, k;
	cin >> n >> k;
	ll ans = (n/2)/(k+1);
	cout << ans << " " << ans*k << " " << n-ans*(k+1) << endl;
	// cin >> n;
}