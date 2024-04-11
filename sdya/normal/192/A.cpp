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
#pragma comment (linker, "/STACK:256000000")

using namespace std;

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	set < long long > S;
	for (long long i = 1; i <= 100000; ++i) {
		S.insert(i * (i + 1) / 2);
	}

	long long n;
	cin >> n;
	for (long long i = 1; i <= 100000; ++i) {
		if (S.count(n - i * (i + 1) / 2)) {
			cout << "YES";
			return 0;
		}
	}
	cout << "NO";

	return 0;
}