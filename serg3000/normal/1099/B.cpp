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
#pragma GCC optimize("Ofast")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,popcnt,abm,mmx,tune=native")
#pragma GCC optimize("fast-math")
#pragma comment(linker, "/STACK:256000000")
#pragma warning(disable:4996)
const int mod = 1e9 + 7;
signed main() {
	int n;
	cin >> n;
	int x = (int)sqrt(n);
	if (x * x >= n) {
		cout << 2 * x;
	}
	else {
		if (x * (x + 1) >= n) {
			cout << 2 * x + 1;
		}
		else {
			cout << 2 * x + 2;
		}
	}
	return 0;
}