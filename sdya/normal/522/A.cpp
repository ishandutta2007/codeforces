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

map < string, int > M;

void toLower(string &s) {
	for (int i = 0; i < s.size(); ++i) {
		if (s[i] >= 'A' && s[i] <= 'Z') {
			s[i] = s[i] - 'A' + 'a';
		}
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	M["polycarp"] = 1;
	int n;
	cin >> n;
	int res = 1;
	for (int i = 0; i < n; ++i) {
		string s1, s2, s3;
		cin >> s1 >> s2 >> s3;
		toLower(s1);
		toLower(s3);
		M[s1] = M[s3] + 1;
		res = max(res, M[s1]);
	}

	cout << res << endl;

	return 0;
}