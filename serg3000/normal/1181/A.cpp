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
mt19937 rnd(time(NULL));
#define int long long

signed main() {
	int z, x, y;
	cin >> x >> y >> z;
	cout << (x + y) / z << " ";
	if (x / z + y / z == (x + y) / z) {
		cout << 0;
	}
	else {
		cout << min(z - x % z, z - y % z);
			
	}
	return 0;
}