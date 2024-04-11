#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <set>
#include <map>
#include <bitset>
#include <cmath>
#include <stack>
#include <ctime>
#include <unordered_map>
#include <unordered_set>
#include <list>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	long long n, k;
	cin >> n >> k;
	int cnt = 0;
	vector < long long > a;
	vector < long long > b;
	for (long long i = 1; i * i <= n; ++i) {
		if (n % i == 0) {
			a.push_back(i);
			if (i * i != n) {
				b.push_back(n / i);
			}
		}
	}
	reverse(b.begin(), b.end());
	vector < long long > c(a.size() + b.size());
	merge(a.begin(), a.end(), b.begin(), b.end(), c.begin());
	
	if (k - 1 < c.size()) {
		cout << c[k - 1] << endl;
	} else {
		cout << -1 << endl;
	}

	return 0;
}