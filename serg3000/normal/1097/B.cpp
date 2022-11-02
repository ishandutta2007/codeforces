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
signed main() {
	int n;
	cin >> n;
	vector<int>a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int z = 1;
	for (int i = 0; i < n; i++) {
		z *= 2;
	}
	for (int i = 0; i < z; i++) {
		int ans = 0;
		int i2 = i;
		for (int j = 0; j < n; j++) {
			if (i2 % 2 == 1) {
				ans += a[j];
			}
			else {
				ans -= a[j];
			}
			i2 /= 2;
		}
		if ((ans + 360000) % 360 == 0) {
			cout << "YES";
			return 0;
		}
	}
	cout << "NO";
	return 0;
}