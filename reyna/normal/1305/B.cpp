
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

const int N = (int) 1e5 + 5, mod = (int) 0;

int main() {
	string s;
	cin >> s;
	int n = (int) s.size();
	int mxp = -1, mx = -1;
	for (int j = 0; j < n; ++j) {
		int cntl = 0, cntr = 0;
		for (int i = 0; i <= j; ++i) cntl += (s[i] == '(');
		for (int i = j+1; i < n; ++i) cntr += (s[i] == ')');
		int cur = min(cntl, cntr);
		if (cur > mx)
			mx = cur, mxp = j;
	}
	if (mx <= 0) {
		cout << 0 << endl;
		return 0;
	}
	cout << 1 << '\n';
	cout << 2 * mx << '\n';
	vector<int> res;
	int tmp = mx;
	for (int i = 0; tmp && i < n; ++i) {
		if (s[i] == '(') {
			res.pb(i);
			--tmp;
		}
	}
	vector<int> all;
	tmp = mx;
	for (int i = n - 1; tmp && i >= 0; --i) {
		if (s[i] == ')') {
			all.pb(i);
			--tmp;
		}
	}
	for (int x : res) cout << x + 1 << ' ';
	reverse(ALL(all));
	for (int x : all) cout << x + 1 << ' ';
	
	
	
}