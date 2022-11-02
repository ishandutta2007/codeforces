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
	string s1;
	cin >> s1;
	vector<string>a(5);
	for (int i = 0; i < 5; i++) {
		cin >> a[i];
		if (a[i][1] == s1[1] || a[i][0] == s1[0]) {
			cout << "YES";
			return 0;
		}
	}
	cout << "NO";


	return 0;
}