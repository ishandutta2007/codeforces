#include <algorithm>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include <queue>
#include <ctime>
#include <cmath>
#include <set>
#include <map>

using namespace std;

typedef int_fast64_t ll;
typedef long double ld;

void start() {
	ios_base::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);
}

int main() {
	start();
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	for (int i = 1; i < n; ++i) {
		if (abs(a[i] - a[i - 1]) > 1) {
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";
	return 0;
}