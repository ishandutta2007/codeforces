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
#pragma comment (linker, "/STACK:256000000")

using namespace std;

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	string s;
	cin >> s;
	for (int i = 0; i < s.size(); ++i) {
		if (s[i] == '0') {
			string res = "";
			for (int j = 0; j < s.size(); ++j) {
				if (i != j) {
					res += s[j];
				}
			}
			puts(res.c_str());
			return 0;
		}
	}

	puts(s.substr(1).c_str());

	return 0;
}