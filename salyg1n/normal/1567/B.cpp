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

//#define _GLIBCXX_DEBUG
//#define DEBUG

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	vector<ll> xr(3e5 + 1, 0);
	for (int i = 1; i <= 3e5; ++i) {
		xr[i] = (xr[i - 1] ^ i);
	}
	int t;
	cin >> t;
	while (t--) {
		ll a, b;
		cin >> a >> b;
		if (xr[a - 1] == b) {
			cout << a << "\n";
			continue;
		}
		if ((xr[a - 1] ^ b) == a)
			cout << a + 2 << "\n";
		else
			cout << a + 1 << "\n";
	}
	return 0;
}