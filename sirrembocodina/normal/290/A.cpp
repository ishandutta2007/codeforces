#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define forv(i, a) forn (i, a.size())
#define mp make_pair
#define fs first
#define sc second
#define pb push_back
#define sqr(x) ((x) * (x))

typedef long long int64;
typedef long double ld;

string a[50];

int main() {
	int n;
	cin >> n;
	a[0] = "Washington";
	a[1] = "Adams";
	a[2] = "Jefferson";
	a[3] = "Madison";
	a[4] = "Monroe";
	a[5] = "Adams";
	a[6] = "Jackson";
	a[7] = "Van Buren";
	a[8] = "Harrison";
	a[9] = "Tyler";
	a[10] = "Polk";
	a[11] = "Taylor";
	a[12] = "Fillmore";
	a[13] = "Pierce";
	a[14] = "Buchanan";
	a[15] = "Lincoln";
	a[16] = "Johnson";
	a[17] = "Grant";
	a[18] = "Hayes";
	a[19] = "Garfield";
	a[20] = "Arthur";
	a[21] = "Cleveland";
	a[22] = "Harrison";
	a[23] = "Cleveland";
	a[24] = "McKinley";
	a[25] = "Roosevelt";
	a[26] = "Taft";
	a[27] = "Wilson";
	a[28] = "Harding";
	a[29] = "Coolidge";
	a[30] = "Hoover";
	a[31] = "Roosevelt";
	a[32] = "Truman";
	a[33] = "Eisenhower";
	a[34] = "Kennedy";
	a[35] = "Johnson";
	a[36] = "Nixon";
	a[37] = "Ford";
	a[38] = "Carter";
	a[39] = "Reagan";
	a[40] = "Bush";
	a[41] = "Clinton";
	a[42] = "Bush";
	cout << a[n - 1];
/*	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
	string s;
	int cur = 0;
	while (cin >> s) {
		if (s[s.size() - 1] == ',') {
			s = s.substr(0, s.size() - 1);
		} else {
			continue;
		}
		cout << "	a[" << cur++ << "] = \"" << s << "\";\n";
	}
*/}