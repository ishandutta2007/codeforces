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

	string s, t;
	cin >> s >> t;
	int best = 0;
	for (int i = 0; i < s.size(); ++i) {
		int current = 0;
		for (int j = 0; j < t.size() && i + j < s.size(); ++j) {
			if (s[i + j] == t[j]) {
				++current;
			}
		}
		best = max(best, current);
	}
	for (int i = 0; i < t.size(); ++i) {
		int current = 0;
		for (int j = 0; j < s.size() && i + j < t.size(); ++j) {
			if (t[i + j] == s[j]) {
				++current;
			}
		}
		best = max(best, current);
	}
	cout << (t.size() - best) << endl;

	return 0;
}