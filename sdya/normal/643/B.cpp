#include <iostream>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#pragma comment(linker, "/STACK:256000000")

using namespace std;

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int n, k;
	int a, b, c, d;

	cin >> n >> k;

	if (n == 4) {
		cout << "-1" << endl;
		return 0;
	}

	if (k < n + 1) {
		cout << "-1" << endl;
		return 0;
	}

	cin >> a >> b >> c >> d;

	vector<int> tot;

	for (int i = 1; i <= n; ++i) {
		if (i != a && i != b && i != c && i != d) {
			tot.push_back(i);
		}
	}

	int x = tot.back();
	tot.pop_back();
	tot.push_back(c);
	tot.push_back(x);
	tot.push_back(d);

	cout << a;
	for (int i = 0; i < tot.size(); ++i) {
		cout << " " << tot[i];
	}
	cout << " " << b << endl;

	for (int i = (int)(tot.size()) - 3; i >= 0; --i) {
		cout << tot[i] << " ";
	}
	cout << a << " ";

	cout << x << " ";
	cout << b << " ";

	cout << d << endl;

	return 0;
}