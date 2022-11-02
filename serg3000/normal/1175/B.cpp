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
	vector<int>a;
	vector<pair<int, int>>b;
	int pr = 1;
	int ans = 0;
	int z = 1;
	for (int i = 0; i < 32; i++) {
		z *= 2;
	}
	for (int q = 0; q < n; q++) {
		string s;
		cin >> s;
		if (s == "add") {
			pr = 1;
			for (auto v2 : b) {
				int v = v2.first;
				pr *= v;
				if (pr >= z) {
					cout << "OVERFLOW!!!";
					return 0;
				}
			}
			ans += pr;
		}
		if (s == "for") {
			int x;
			cin >> x;
			a.push_back(x);
			if (x != 1) {
				b.push_back({ x, (int)a.size() - 1 });
			}
		}
		if (s == "end") {
			int x = a.back();
			a.pop_back();
			if ((int)b.size() != 0 && b.back().second == (int)a.size()) {
				b.pop_back();
			}
		}
		if (ans >= z) {
			cout << "OVERFLOW!!!";
			return 0;
		}
	}
	cout << ans;
	return 0;
}