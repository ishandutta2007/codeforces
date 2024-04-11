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
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC optimize ("no-stack-protector")
#define int long long
signed main() {
	int a, b, c;
	cin >> a >> b >> c;
	if (a == b) {
		cout << c * 2 + 2 * min(a, b);
	}
	else {
		cout << c * 2 + 2 * min(a, b) + 1;
	}

	return 0;
}