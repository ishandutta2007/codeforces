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


	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;

	string t;
	int balance = 0, fake = 0;
	for (int i = 0; i < n; ++i) {
		if (s[i] == '(') {
			if (t.size() + balance + 2 <= k) {
				t += s[i];
				++balance;
			} else {
				++fake;
			}
		} else {
			if (fake > 0) {
				--fake;
			} else {
				--balance;
				t += s[i];
			}
		}
	}
	cout << t << endl;



	return 0;
}