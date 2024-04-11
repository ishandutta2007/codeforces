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

const int N = (int) 4e6 + 5, mod = (int) 1e9 + 7;
int cnt[N], mx[N], pr[N], mark[N];
int use[N];
int main() {
	for (int j = 2; j < N; ++j)
		if (pr[j] == 0)
			for (int i = j; i < N; i += j)
				pr[i] = j;
	int n;
	cin >> n;
	set<int> st;
	int add = 0;
	for (int j = 0; j < n; ++j) {
		int x;
		cin >> x;
		cnt[x]++;
		mx[x] = 1;
		use[x]++;
		if (cnt[x] > 1) {
			if (cnt[x] > 2) add = 1;
			mark[x] = 1;
			st.insert(-x);
		}
	}
	set<int> all;
	for (int j = 0; j < N; ++j) if (cnt[j])
		all.insert(j);
	while ((int) st.size()) {
		int cur = -(*(st.begin()));
		st.erase(-cur);
		mark[cur] = 1;
		if (mx[cur] == 1) use[cur]--;
		cur--;
		all.insert(cur);
		int used = 0;
		while (cur != 1) {
			int p = pr[cur], cnt = 0;
			while (cur % p == 0) cur /= p, ++cnt;
			
			if (cnt >= 1) {
				if (cnt > mx[p]) used = 1;
				if (cnt > mx[p])
					use[p] = 0;
				mx[p] = max(mx[p], cnt);
				if (cnt == mx[p])
				use[p]++;
				if (::cnt[p] >= 1) {
					if (!mark[p]++) st.insert(-p);	
				}
			}
		}
	}
	for (int j : all) {
		int cur = j;
		int used = 0;
		while (cur != 1) {
			int p = pr[cur], cnt = 0;
			while (cur % p == 0) cur /= p, ++cnt;
			if (cnt == mx[p] && use[p] == 1) used = 1;
		}
		if (!used) add = 1;
	}
	for (int j = 2; j < N; ++j)
		if (cnt[j] >= 1)
			mx[j] = max(mx[j], 1);
	int res = 1;
	for (int j = 1; j < N; ++j)
		while (mx[j]--)
			res = (LL) res * j % mod;
	cout << (add + res) % mod << endl;
	
}