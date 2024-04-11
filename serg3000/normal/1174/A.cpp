#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <set>
#include <queue>
#include <deque>
#include <unordered_set>
#include <map>
#include<unordered_map>
#include <bitset>
#include <random>
#include <ctime>
using namespace std;
struct ooo {
	int f, s, d;
};
int main() {
	int n;
	cin >> n;
	vector<int>a(2 * n);
	for (int i = 0; i < 2 * n; i++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	if (a[0] != a[2 * n - 1]) {
		for (int i = 0; i < 2 * n; i++) {
			cout << a[i] << " ";
		}
	}
	else {
		cout << -1;
	}
	return 0;
}