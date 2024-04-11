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
	int n;
	cin >> n;
	if (n % 2 == 1) {
		cout << 0;
	}
	else {
		int x = 1;
		for (int i = 0; i < n / 2; i++) {
			x *= 2;
		}
		cout << x;
	}




	return 0;
}