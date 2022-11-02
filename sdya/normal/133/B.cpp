#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
using namespace std;

map < char, int > M;

int main() {
	M['>'] = 8;
	M['<'] = 9;
	M['+'] = 10;
	M['-'] = 11;
	M['.'] = 12;
	M[','] = 13;
	M['['] = 14;
	M[']'] = 15;
	string s;
	cin >> s;
	long long res = 0;
	for (int i = 0; i < s.size(); ++i) {
		res = res * 16 + M[s[i]];
		res %= 1000003;
	}
	cout << res << endl;
	return 0;
}