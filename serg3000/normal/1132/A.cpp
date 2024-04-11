#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <string>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <deque>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("no-stack-protector")
#pragma GGC optimize("fast-math")
#pragma GCC optimize("unroll-loops")
using namespace std;
//#define int long long
signed main() {
	
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	if (a - d  != 0 || a == 0 && c!= 0) {
		cout << 0;
	}
	else {
		cout << 1;
	}
	return 0;
}