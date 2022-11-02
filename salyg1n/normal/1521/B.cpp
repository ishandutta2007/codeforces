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
		int n;
		cin >> n;
		vector<int> a(n);
		for (auto& i : a)
			cin >> i;
		int mn = 0;
		for (int i = 0; i < n; ++i) {
			if (a[i] < a[mn])
				mn = i;
		}
		cout << n - 1 << "\n";
		for (int i = 0; i < n; ++i) {
			if (i == mn)
				continue;
			if (i % 2 == 0)
				cout << i + 1 << " " << mn + 1 << " " << 1000000007 << " " << a[mn] << "\n";
			if (i % 2 == 1)
				cout << i + 1 << " " << mn + 1 << " " << 1000000009 << " " << a[mn] << "\n";
		}
	}
	return 0;
}