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

	unordered_set < long long > S;
	long long n;
	cin >> n;
	for (int a = 0; a < 10; ++a) {
		for (int b = a; b < 10; ++b) {
			for (int length = 1; length <= 10; ++length) {
				for (int i = 0; i < (1 << length); ++i) {
					long long value = 0;
					for (int j = 0; j < length; ++j) {
						value *= 10LL;
						if (i & (1 << j)) {
							value += a;
						} else {
							value += b;
						}
					}
					if (value <= n) {
						S.insert(value);
					}
				}
			}
		}
	}
	cout << S.size() - 1;

	return 0;
}