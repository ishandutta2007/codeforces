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
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 110000;
const long long P = 1000000007LL;

string s;
int m;
string q[maxN];

long long a[maxN], b[maxN];

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	for (int i = 0; i < 10; ++i) {
		a[i] = 10LL;
		b[i] = i;
	}
	cin >> s;
	cin >> m;
	for (int i = 0; i < m; ++i) {
		cin >> q[i];
	}

	for (int i = m - 1; i >= 0; --i) {
		long long x = 1, y = 0;
		for (int j = 3; j < q[i].size(); ++j) {
			x *= a[q[i][j] - '0'];
			x %= P;
			y = y * a[q[i][j] - '0'] + b[q[i][j] - '0'];
			y %= P;
		}
		a[q[i][0] - '0'] = x;
		b[q[i][0] - '0'] = y;
	}

	long long x = 1, y = 0;
	for (int i = 0; i < s.size(); ++i) {
		x *= a[s[i] - '0'];
		x %= P;
		y = y * a[s[i] - '0'] + b[s[i] - '0'];
		y %= P;
	}

	cout << y << endl;

	return 0;
}