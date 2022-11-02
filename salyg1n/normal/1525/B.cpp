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
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> a(n);
		for (auto& i : a)
			cin >> i;
		bool sorted = true;
		for (int i = 0; i < n - 1; ++i) {
			if (a[i] >= a[i + 1])
				sorted = false;
		}
		if (sorted)
			cout << 0 << "\n";
		else {
			if (a[0] == n && a[n - 1] == 1)
				cout << 3 << "\n";
			else if (a[0] == 1 || a[n - 1] == n)
				cout << 1 << "\n";
			else
				cout << 2 << "\n";
		}
	}
	return 0;
}