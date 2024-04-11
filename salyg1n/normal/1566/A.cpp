//#define _GLIBCXX_DEBUG
#include <iostream>
#include <iomanip>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include <deque>
#include <string>
#include <cmath>
#include <bitset>
#include <unordered_set>
#include <unordered_map>
#include <fstream>
//#include <bits/stdc++.h>

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#pragma GCC optimize("O3")

#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define print(a) for (auto& i : a) cout << i << " ";
#define input(a) for (auto& i : a) cin >> i;

//#define int long long
//#define DEBUG

using namespace std;

signed main() {
	int t;
	cin >> t;
	while (t--) {
		ll n, s;
		cin >> n >> s;
		cout << s / (n / 2 + 1) << "\n";
	}

	return 0;
}