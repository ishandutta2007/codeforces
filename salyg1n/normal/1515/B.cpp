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

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	for (int T = 0; T < t; ++T) {
		ll n;
		cin >> n;
		ll a = sqrt(n / 2);
		ll b = sqrt(n / 4);
		if (a * a * 2 == n || b * b * 4 == n)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	return 0;
}