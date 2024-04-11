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

const int N = (int) 2e6 + 6, mod = (int) 0;
set<int> st;
int res[N];
int main() {
	ios_base::sync_with_stdio(0);
	for (int j = 0; j < N; ++j) st.insert(j);
	memset(res, -1, sizeof res);
	int n;
	cin >> n;
	for (int j = 0; j < n; ++j) {
		string s;
		cin >> s;
		int k = (int) s.size();
		int m;
		cin >> m;
		for (int i = 0; i < m; ++i) {
			int pos;
			cin >> pos;
			--pos;
			while (true) {
				auto it = st.lower_bound(pos);
				if (it == st.end()) break;
				int x = *it;
				if (x >= pos + k) break;
				res[x] = s[x - pos] - 'a';
				st.erase(it);
			}
		}
	}
	int most = 0;
	for (int j = 0; j < N; ++j)
		if (res[j] >= 0)
			most = j + 1;
	for (int j = 0; j < most; ++j) {
		cout << (res[j] == -1 ? 'a' : char(res[j] + 'a'));	
	}
	cout << endl;
	
}