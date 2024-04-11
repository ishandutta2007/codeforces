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
#include <ctime>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;

	int current = 0;
	vector < int > operations;
	for (int step = 1; step <= k && step <= 2 * n; ++step) {
		for (int i = current - 1; i + 1 < n; ++i) {
			if (i >= 0 && s[i] == '4' && s[i + 1] == '7') {
				if (i % 2 == 0) {
					s[i + 1] = '4';
				} else {
					s[i] = '7';
				}
				current = i;
				operations.push_back(i);
				break;
			}
		}
	}

	if (operations.size() < k && operations.size() < 2 * n) {
		cout << s << endl;
		return 0;
	}

	if ((k + operations.size()) % 2 != 0) {
		for (int i = current - 1; i + 1 < n; ++i) {
			if (i >= 0 && s[i] == '4' && s[i + 1] == '7') {
				if (i % 2 == 0) {
					s[i + 1] = '4';
				} else {
					s[i] = '7';
				}
				current = i;
				operations.push_back(i);
				break;
			}
		}
	}
	cout << s << endl;

	return 0;
}