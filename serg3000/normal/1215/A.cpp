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
#define int long long
signed main() {
	int a1, a2, k1, k2;
	cin >> a1 >> a2 >> k1 >> k2;
	int n;
	cin >> n;
	int x;
	x = a1 * (k1 - 1) + a2 * (k2 - 1);
	cout << max(0ll, n - x) << " ";
	if (k1 > k2) {
		swap(k1, k2);
		swap(a1, a2);
	}
	int z;
	if (n <= a1 * k1) {
		cout << n / k1;
	}
	else {
		cout << a1 + (n - a1 * k1) / k2;
	}
	return 0;
}