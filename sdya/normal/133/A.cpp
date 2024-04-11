#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
using namespace std;

const int maxN = 110;
int n, m;
set < int > g[maxN];

int main() {
	string s;
	cin >> s;
	int t = count(s.begin(), s.end(), 'H') + count(s.begin(), s.end(), 'Q') + count(s.begin(), s.end(), '9');
	if (t > 0) {
		cout << "YES";
	} else {
		cout << "NO";
	}
	return 0;
}