// In the name of God

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

#define rep(i, a, b) for (int i = (a), i##_end_ = (b); i < i##_end_; ++i)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define mp make_pair
#define x first
#define y second
#define pb push_back
#define SZ(x) (int((x).size()))
#define ALL(x) (x).begin(), (x).end()

template<typename T> inline bool chkmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
template<typename T> inline bool chkmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }
template<typename T> inline bool smin(T &a, const T &b)   { return a > b ? a = b : a;    }
template<typename T> inline bool smax(T &a, const T &b)   { return a < b ? a = b : a;    }

typedef long long LL;

const int N = (int) 1e3 + 3, mod = (int) 0;
string f[N], s[N], res[N];
map<string, vector<int>> fn;
int q[N], mark[N], t;
int main() {
	int n;
	cin >> n;
	for (int j = 0; j < n; ++j) {
		cin >> f[j] >> s[j];
		string name = "";
		name += f[j][0]; name += f[j][1];
		string tmp = name;
		f[j] = (name += f[j][2]);
		s[j] = (tmp += s[j][0]);
		fn[f[j]].push_back(j);
	}
	for (int j = 0; j < n; ++j) {
		if (fn[f[j]].size() > 1)
			q[t++] = j, mark[j] = 1;
	}
	int h = 0;
	while (h != t) {
		int v = q[h++];
		for (int x : fn[s[v]])
			if (!mark[x]) {
				mark[x] = 1;
				q[t++] = x;
			}
	}
	for (int j = 0; j < n; ++j)
		res[j] = (mark[j] ? s[j] : f[j]);
	for (int x = 0; x < n; ++x)
		for (int y = x + 1; y < n; ++y) {
			if (res[x] == res[y]) {
				cout << "NO\n";
				return 0;
			}
		}
	cout << "YES\n";
	for (int x = 0; x < n; ++x)
		cout << res[x] << '\n';
}