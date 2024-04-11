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
	int n, l, a;
	cin >> n;
	if (n == 3) {
		cout << 1 << " " << 1 << " " << 3;
		return 0;
	}
	int x = (n + 1) / 2;
	int c = 1;
	int z = 0;
	int k = n;
	while (z != n) {
		if (z == n - 3) {
			cout << c << " " << c << " " << c * 3;
			return 0;
		}
		for (int i = 0; i < x; i++) {
			cout << c << " ";
		}
		z += x;
		k -= x;
		x = ((k) + 1) / 2;
		
		
		c *= 2;
	}
	return 0;
}