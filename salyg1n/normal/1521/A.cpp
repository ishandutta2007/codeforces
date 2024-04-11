#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <deque>
#include <unordered_map>
#include <time.h>
#include <set>
#include <cmath>

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); 


	int t;
	cin >> t;
	for (int T = 0; T < t; ++T) {
		ll a, b;
		cin >> a >> b;
		if (b == 1) {
			cout << "NO\n";
		}
		else {
			cout << "YES\n";
			cout << a << " " << a * (2 * b - 1) << " " << a * b * 2 << "\n";
		}
	}
	return 0;
}