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

const int maxN = 11000;
set < string > d[maxN];

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	string s;
	cin >> s;
	int n = s.size();

	set < string > res;

	d[n].insert("");
	for (int i = n - 1; i >= 5; --i) {
		for (int l = 2; l <= 3; ++l) {
			string t = s.substr(i, l);
			if (t.size() != l) {
				continue;
			}

			for (set < string > ::iterator it = d[i + l].begin(); it != d[i + l].end(); ++it) {
				if (*it != t) {
					d[i].insert(t);
					res.insert(t);
					break;
				}
			}
		}
	}

	printf("%d\n", res.size());
	for (set < string > ::iterator it = res.begin(); it != res.end(); ++it) {
		puts(it->c_str());
	}

	return 0;
}