#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <queue>

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for (auto& i : a)
		cin >> i;
	vector<int> b;
	for (int i = 0; i < n; ++i) {
		bool tmp = true;
		for (auto j : b) {
			if (a[i] == a[j])
				tmp = false;
		}
		if (tmp && b.size() < k)
			b.push_back(i);
	}
	if (b.size() < k)
		cout << "NO";
	else {
		cout << "YES\n";
		for (auto i : b)
			cout << i + 1 << " ";
	}
}