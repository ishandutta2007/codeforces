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
vector<int> probs[N];
int maxp[N], t[N];
int main() {
	int n, max_len;
	cin >> n >> max_len;
	set<pair<int, int>> st;
	for (int j = 0; j < n; ++j) {
		cin >> maxp[j] >> t[j];	
		probs[maxp[j]].push_back(j);
	}
	long long cur_t = 0;
	int res = 0;
	for (int j = n; j >= 1; --j) {
		for (int i : probs[j]) {
			st.insert(mp(-t[i], i));
			cur_t += t[i];
		}
		while (cur_t > max_len || (int) st.size() > j) {
			auto cur = *(st.begin());
			st.erase(st.begin());
			cur_t += cur.first;
		}
		res = max(res, (int) st.size());
	}
	cur_t = 0;
	st.clear();
	
	for (int j = n; j >= 1; --j) {
		for (int i : probs[j]) {
			st.insert(mp(-t[i], i));
			cur_t += t[i];
		}
		while (cur_t > max_len || (int) st.size() > j) {
			auto cur = *(st.begin());
			st.erase(st.begin());
			cur_t += cur.first;
		}
		if (res == (int) st.size()) {
			cout << res << '\n' << res << '\n';
			for (auto x : st) {
				cout << x.second + 1 << ' ';
			}
			return 0;
		}
	}
}