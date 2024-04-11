#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <unordered_map>

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		int n, k1, k2, w, b;
		cin >> n >> k1 >> k2 >> w >> b;
		int white = k1 + k2;
		int black = n * 2 - k1 - k2;
		if (w * 2 <= white && b * 2 <= black)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
}