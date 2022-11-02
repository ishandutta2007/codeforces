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
	int n, t;
	cin >> n >> t;
	int k;
	cin >> k;
	int l = 1, r = n;
	while (r - l > 0) {
		int m = (r + l) / 2;
		cout << '?' << l << " " << m << endl;
		int c;
		cin >> c;
		c = m - l + 1 - c;
		if (c >= k) {
			r = m;
		}
		else {
			k -= c;
			l = m + 1;
		}
	}
	cout << "! " << r;
	return 0;
}