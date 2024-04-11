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

const int maxN = 1100000;
bool used[maxN];

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int n;
	cin >> n;
	vector < int > a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		used[a[i]] = true;
	}

	int rem = 25 - n;
	for (int i = 1; i < maxN && rem > 0; ++i) {
		if (!used[i]) {
			used[i] = true;
			--rem;
		}
	}

	sort(a.begin(), a.end());
	int total = 0;
	for (int i = 1; i < a.back(); ++i) {
		if (!used[i]) {
			++total;
		}
	}
	cout << total << endl;



	return 0;
}