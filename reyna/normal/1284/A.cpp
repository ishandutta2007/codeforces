
#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <deque>
#include <assert.h>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <stdio.h>
#include <string.h>
#include <utility>
#include <math.h>
#include <bitset>
#include <iomanip>
#include <complex>

using namespace std;

#define mp make_pair
#define x first
#define y second
#define pb push_back
#define ALL(x) (x).begin(), (x).end()

typedef long long LL;

const int N = (int) 2025, mod = (int) 0;
string s[N], t[N];
int main() {
	int n, m;
	cin >> n >> m;
	for (int j = 0; j < n; ++j) cin >> s[j];
	for (int j = 0; j < m; ++j) cin >> t[j];
	int q;
	cin >> q;
	while (q--) {
		int y;
		cin >> y;
		--y;
		string res = s[y % n];
		res += t[y % m];
		cout << res << '\n';
	}
}