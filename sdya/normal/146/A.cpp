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
	int n;
	cin >> n;
	string s;
	cin >> s;
	bool isGood = true;
	int sum = 0;
	for (int i = 0; i < n; ++i) {
		if (s[i] != '4' && s[i] != '7') {
			isGood = false;
		}
		if (i < n / 2) {
			sum += s[i];
		} else {
			sum -= s[i];
		}
	}
	if (sum == 0 && isGood) {
		cout << "YES";
	} else {
		cout << "NO";
	}

	return 0;
}