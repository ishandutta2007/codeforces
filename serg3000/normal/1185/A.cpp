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
#pragma GCC optimize("Ofast")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,popcnt,abm,mmx,tune=native")
#pragma GCC optimize("fast-math")
#pragma comment(linker, "/STACK:256000000")
#pragma warning(disable:4996)
using namespace std;
mt19937 rnd(time(NULL));
#define int long long
signed main() {
	vector<int>a(3);
	cin >> a[0] >> a[1] >> a[2];
	int d;
	cin >> d;
	sort(a.begin(), a.end());
	cout << max(d + a[0] - a[1], 0ll) + max(d + a[1] - a[2], 0ll);


	
	return 0;
}