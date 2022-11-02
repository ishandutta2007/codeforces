#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
#include <queue>
#include <deque>
#include <set>

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

int main() {
	int t;
	cin >> t;
	for (int T = 0; T < t; ++T) {
		ll r, b, d;
		cin >> r >> b >> d;
		ll k = (r + b - 1) / min(r, b);
		if (k - 1 <= d)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	return 0;
}