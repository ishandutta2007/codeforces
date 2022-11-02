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

const int maxN = 110000;
const int maxK = 26;

int d[maxN][maxK + 1];
bool g[maxK + 1][maxK + 1];

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	string s;
	cin >> s;
	int m;
	cin >> m;
	set < int > a;
	for (int i = 0; i < m; ++i) {
		string b;
		cin >> b;
		g[b[0] - 'a'][b[1] - 'a'] = 1;
		g[b[1] - 'a'][b[0] - 'a'] = 1;
	}

	d[0][maxK] = 0;
	int n = s.size();
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j <= maxK; ++j) {
			d[i][j] = d[i - 1][j];
		}
		for (int j = 0; j <= maxK; ++j) {
			if (!g[j][s[i - 1] - 'a']) {
				int t = s[i - 1] - 'a';
				d[i][t] = max(d[i][t], d[i - 1][j] + 1);
			}
		}
	}

	int res = *max_element(d[n], d[n] + maxK + 1);
	cout << n - res << endl;


	return 0;
}