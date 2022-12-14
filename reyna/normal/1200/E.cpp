
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

const int N = (int) 2e6 + 6, L = 62, mod = (int) 0;
int f[N];
int common(string x, string y) {
	x += '#';
	x += '$';
	x += y;
	f[0] = f[1] = 0;
	for (int j = 2; j <= (int) x.size(); ++j) {
		int cur = f[j - 1];
		while (true) {
			if (x[cur] == x[j - 1]) {
				f[j] = cur + 1; break;
			}
			if (cur == 0) { f[j] = 0; break; }
			cur = f[cur];
		}
	}
	return f[(int) x.size()];
}
int main() {
	ios_base::sync_with_stdio(0);
	int n;
	cin >> n;
	string res = "";
	for (int j = 0; j < n; ++j) {
		string s, t;
		cin >> s;
		int m = (res.size() >= s.size() ? res.size() - s.size() : 0);
		if (m >= (int) res.size()) m = 0;
		else m = max(m - 10, 0);
		for (int j = m; j < (int) res.size(); ++j)
			t += res[j];
		int start = common(s, t);
		for (int j = start; j < (int) s.size(); ++j)
			res += s[j];
	}
	cout << res << '\n';

}