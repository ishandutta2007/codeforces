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
int main() {
	long long n, m, k, l, x;
	cin >> n >> m >> k >> l;
	x = (l + k + m - 1) / m;
	if (x * m <= n) {
		cout << x;
	}
	else {
		cout << -1;
	}

	return 0;
}