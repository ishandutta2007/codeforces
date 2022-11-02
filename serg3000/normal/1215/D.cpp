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
#define int long long
signed main() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	int c1 = 0, c2 = 0, s1 = 0, s2 = 0;
	for (int i = 0; i < n / 2; i++) {
		if (s[i] == '?') {
			c1++;
		}
		else {
			s1 += s[i] - '0';
		}
	}
	for (int i = n / 2; i < n; i++) {
		if (s[i] == '?') {
			c2++;
		}
		else {
			s2 += s[i] - '0';
		}
	}
	if ((c1 - c2) * 9 == (s2 - s1) * 2) {
		cout << "Bicarp";
	}
	else {
		cout << "Monocarp";
	}
	return 0;
}