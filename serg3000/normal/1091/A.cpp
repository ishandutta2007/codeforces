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
	int a, b, c;
	cin >> a >> b >> c;
	for (int i = c; i > -1; i--) {
		if (b >= i - 1 && a >= i - 2) {
			cout << i * 3 - 3;
			return 0;
		}
	}

	return 0;
}