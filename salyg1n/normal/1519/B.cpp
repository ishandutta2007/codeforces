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
		ll n, m, k;
		cin >> n >> m >> k;
		if (n - 1 + (m - 1) * n == k)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	return 0;
}