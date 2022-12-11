#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <cstdio>
using namespace std;

int gcd(int a, int b) {
	if (b > a) {
		return gcd(b, a);
	} // now WLOG a >= b
	if (b == 0) {
		return a;
	} else {
		return gcd(b, a%b);
	}
}

class sparsetable {
	vector<vector<int>> table;
	int n;
public:
	sparsetable(vector<int> arr) : table(log2(arr.size()) + 1, arr), n(arr.size()) {
		for (int i = 1; (1 << i) <= n; ++i) {
			// we check intervals of the form [j, j + (1 << i) - 1]
			for (int j = 0; j + (1 << i) - 1 < n; ++j) {
				table[i][j] = gcd(table[i-1][j], table[i-1][j + (1 << (i - 1))]);
			}
		}
	}
	int query(int i, int j) {
		int layerToCheck = log2(j - i + 1);
		// second interval to check is [k, k + (1 << ltc) - 1]; 
		return gcd(table[layerToCheck][i], table[layerToCheck][j - (1 << layerToCheck) + 1]);
	}
};


class occurrenceTree2 {
	vector<map<int, int>> occtree;
	vector<int> orig;
	int n;
public:
	occurrenceTree2(vector<int> arr) : orig(arr), n(arr.size()), occtree(2*arr.size(), map<int, int>()) {
		for (int i = n; i < 2*n; ++i) {
			++occtree[i][orig[i - n]];
		}
		for (int i = n - 1; i >= 0; --i) {
			for (auto kvp : occtree[i<<1]) {
				occtree[i][kvp.first] += kvp.second;
			}
			for (auto kvp : occtree[i<<1|1]) {
				occtree[i][kvp.first] += kvp.second;
			}
		}
	}
	int query(int i, int j, int x) {
		int res = 0;
		for (i += n, j += n + 1; i < j; i >>= 1, j >>= 1) {
			if (i&1) {res += occtree[i++][x];}
			if (j&1) {res += occtree[--j][x];}
		}
		return res;
	}
};

int main() {
	int n; scanf("%d", &n);
	vector<int> arr(n, 0);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &arr[i]);
	}
	sparsetable ultima(arr);
	occurrenceTree2 atlan(arr);
	int t; scanf("%d", &t);
	for (int q = 0; q < t; ++q) {
		int l, r;
		scanf("%d %d", &l, &r); --l; --r;
		int intervalgcd = ultima.query(l, r);
		int ict = atlan.query(l, r, intervalgcd);
		printf("%d\n", r - l + 1 - ict);
	}
	return 0;
}