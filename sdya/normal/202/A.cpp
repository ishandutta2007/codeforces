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

	string s;
	cin >> s;
	int n = s.size();
	string res = "";
	for (int i = 0; i < (1 << n); ++i) {
		string A;
		for (int j = 0; j < n; ++j) {
			if (i & (1 << j)) {
				A += s[j];
			}
		}
		string B = A;
		reverse(B.begin(), B.end());
		if (A == B) {
			res = max(res, A);
		}
	}
	cout << res << endl;

	return 0;
}