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
int mark[N], nxt[N], see[N], prv[N], used[N];
string s[N];
bool same(int x, int y) {
	if (y == -1 || x == -1) return 1;
	return x == y;
}
void add_link(int x, int y) {
	nxt[x] = y;
	prv[y] = x;
}
int main() {
	int n;
	cin >> n;
	memset(nxt, -1, sizeof nxt);
	memset(prv, -1, sizeof prv);
	for (int j = 0; j < n; ++j) {
		cin >> s[j];
		for (auto c : s[j]) mark[c]++, used[c] = 1;
		for (int j = 0; j < 256; ++j) if (mark[j] > 1) {
			cout << "NO\n";
			return 0;
		}
		for (auto c : s[j]) mark[c]--;
		
	}
	for (int j = 0; j < n; ++j)
		for (int i = 0; i < (int) s[j].size() - 1; ++i)
			add_link(s[j][i], s[j][i + 1]);
	for (int j = 0; j < n; ++j)
		for (int i = 0; i < (int) s[j].size() - 1; ++i) {
			if (!same(nxt[s[j][i]], s[j][i + 1])) {
				cout << "NO\n";
				return 0;
			}
			if (!same(s[j][i], prv[s[j][i + 1]])) {
				cout << "NO\n";
				return 0;
			}
		}
	for (int c = 'a'; c < 'z' + 1; ++c) if (used[c] && prv[c] == -1 && !mark[c]) {
		int cur = c;
		while (cur != -1) {
			mark[cur] = 1;
//			cout << char(cur);
			cur = nxt[cur];
		}
	}
	for (int c = 'a'; c < 'z' + 1; ++c) if (used[c] && !mark[c]) {
		cout << "NO\n";
		return 0;
	}
	memset(mark, 0, sizeof mark);
	for (int c = 'a'; c < 'z' + 1; ++c) if (used[c] && prv[c] == -1 && !mark[c]) {
		int cur = c;
		while (cur != -1) {
			mark[cur] = 1;
			cout << char(cur);
			cur = nxt[cur];
		}
	}
}