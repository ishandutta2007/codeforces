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
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 310000;
int n;
int a[maxN];

long long solveSmart() {
	multiset < long long > S;
	multiset < long long > used;
	long long res = 0;
	for (int i = 0; i < n; ++i) {
		long long value = a[i];
		S.insert(value);
		multiset < long long > ::iterator it = S.begin();
		if ((*it) < value) {
			res += (value - (*it));
			if (used.find(*it) == used.end()) {
				S.erase(it);
			} else {
				used.erase(used.find(*it));
			}
			used.insert(value);
		}
	}
	return res;
}


int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}

	cout << solveSmart() << endl;

	return 0;
}