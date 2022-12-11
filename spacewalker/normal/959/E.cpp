#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

ll ans(ll n) {
	if (n == 1) {
		return 0;
	} else if (n % 2 == 0) {
		// kruskal's will pick edges of weight 1 first...
		// meaning we have (0, 1), (2, 3), ..., (n-2, n-1) as edges
		// there are (n-2)/2 + 1 such edges
		return (n-2)/2 + 1 + 2*ans(n/2);
	} else {
		// same as above...
		// edges are (0, 1), (2, 3), ..., (n-3, n-2) as edges
		// there are (n-3)/2 + 1 added edges
		return (n-3)/2 + 1 + 2*ans(n/2 + 1);
	}
}

int main() {
	ll n; cin >> n; cout << ans(n) << endl;
	return 0;
}