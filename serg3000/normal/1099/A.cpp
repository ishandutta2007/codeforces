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
	int w, h;
	cin >> w >> h;
	int u1, d1, u2, d2;
	cin >> u1 >> d1 >> u2 >> d2;
	int i = h;
	int ans = w;
	while (i > 0) {
		ans += i;
		if (d1 == i) {
			ans = max(0ll, ans - u1);
		}
		if (d2 == i) {
			ans = max(0ll, ans - u2);
		}
		i--;
	}
	cout << ans;
	return 0;
}