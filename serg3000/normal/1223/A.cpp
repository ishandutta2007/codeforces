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
	int q;
	cin >> q;
	for (int i = 0; i < q; i++) {
		int n;
		cin >> n;
		if (n <= 4) {
			cout << 4 - n << '\n';
		}
		else {
			cout << n % 2 << '\n';
		}
	}

	return 0;
}