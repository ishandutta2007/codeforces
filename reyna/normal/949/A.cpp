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

const int N = (int) 1e6 + 6, mod = (int) 0;
vector<int> all[N];
int cnt;
set<int> st[2];
int main() {
	string s;
	cin >> s;
	for (int j = 0; j < (int) s.size(); ++j) {
		int c = s[j] - '0';
		if (c == 0) {
			if (st[1].size() > 0) {
				int id = *(st[1].begin());
				st[1].erase(st[1].begin());
				all[id].pb(j);
				st[0].insert(id);
			} else {
				int id = cnt++;
				all[id].pb(j);
				st[0].insert(id);
			}
		} else {
			if (st[0].size() > 0) {
				int id = *(st[0].begin());
				st[0].erase(st[0].begin());
				all[id].pb(j);
				st[1].insert(id);
			} else {
				cout << -1 << endl;
				return 0;
			}
		}
	}
	if ((int) st[1].size() > 0) {
		cout << -1 << endl;
		return 0;
	}
	cout << cnt << endl;
	for (int j = 0; j < cnt; ++j) {
		cout << (int) all[j].size() << ' ';
		for (auto x : all[j]) cout << x + 1 << ' ';
		cout << '\n';
	}
}