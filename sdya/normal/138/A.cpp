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

bool isOk(char c) {
	return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

string build(string a, int k) {
	int cnt = 0;
	for (int i = (int)(a.size()) - 1; i >= 0; --i) {
		if (isOk(a[i])) {
			++cnt;
			if (cnt == k) {
				return a.substr(i);
			}
		}
	}
	return "";
}

bool isOk(string a, string b, int k) {
	string u = build(a, k);
	string v = build(b, k);
	if (u == "" || v == "") {
		return false;
	}
	return u == v;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int n, k;
	cin >> n >> k;
	set < string > allowed;
	allowed.insert("aabb");
	allowed.insert("abab");
	allowed.insert("abba");
	for (int i = 0; i < n; ++i) {
		string s[4];
		cin >> s[0] >> s[1] >> s[2] >> s[3];

		if (!isOk(s[0], s[1], k) || !isOk(s[2], s[3], k)) {
			allowed.erase("aabb");
		}
		if (!isOk(s[0], s[2], k) || !isOk(s[1], s[3], k)) {
			allowed.erase("abab");
		}
		if (!isOk(s[0], s[3], k) || !isOk(s[1], s[2], k)) {
			allowed.erase("abba");
		}
	}

	if (allowed.size() == 0) {
		cout << "NO" << endl;
		return 0;
	}
	if (allowed.size() == 3) {
		cout << "aaaa" << endl;
	} else {
		cout << *allowed.begin() << endl;
	}

	return 0;
}