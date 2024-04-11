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

const int N = (int) 1e5 + 5, mod = (int) 0, sq = 317;
int last[N], mark[N], a[N], b[N], qc[N], qx[N], qy[N];
long long res[N], f[N];
set<int> pl[N];
pair<int, int> sr[N];
void fen_update(int m, int x) { ++m;
	while (m < N)
		f[m] += x, m += m & -m;
}
long long fen_query(int m) { ++m;
	long long res = 0;
	while (m > 0)
		res += f[m], m -= m & -m;
	return res;
}
int main() {
	ios_base::sync_with_stdio(0);
	int n, q;
	cin >> n >> q;
	for (int j = 0; j < n; ++j) {
		cin >> a[j];
		--a[j];
	}
	for (int j = 0; j < q; ++j) {
		cin >> qc[j] >> qx[j] >> qy[j];
		if (qc[j] == 1) {
			qx[j]--;
			qy[j]--;
		} else {
			qx[j]--;
		}
	}
	for (int j = 0; j < n; ++j) pl[a[j]].insert(j);
	for (int pile = 0; pile < q; pile += sq) {
		memcpy(b, a, sizeof b);
		memset(f, 0, sizeof f);
		memset(mark, 0, sizeof mark);
		int bg = pile, ed = min(q, pile + sq), t = 0;
		for (int j = bg; j < ed; ++j)
			if (qc[j] == 1) {
				mark[b[qx[j]]] = 1;	
				b[qx[j]] = qy[j];
				mark[b[qx[j]]] = 1;
			} else {
				sr[t++] = mp(qy[j], j);
			}
		vector<int> marked;
		for (int j = 0; j < n; ++j) if (mark[j]) marked.push_back(j);
		sort(sr, sr + t);
		memset(last, -1, sizeof last);
		int pt = 0;
		for (int j = 0; j < n; ++j) {
			int x = a[j];
			if (last[x] != -1) {
				if (!mark[x]) fen_update(last[x], j - last[x]);	
			}
			last[x] = j;
			while (pt < t && sr[pt].first == j + 1) {
				int id = sr[pt].second;
				res[id] = fen_query(qy[id]) - fen_query(qx[id] - 1);
				++pt;
			}
		}
		for (int j = bg; j < ed; ++j) {
			if (qc[j] == 1) {
				pl[a[qx[j]]].erase(qx[j]);
				a[qx[j]] = qy[j];	
				pl[a[qx[j]]].insert(qx[j]);
			} else {
				int l = qx[j], r = qy[j];
				for (int p : marked) {
					auto fst = pl[p].lower_bound(l);
					auto lst = pl[p].lower_bound(r);
					if (lst == pl[p].begin()) continue;
					--lst;
					if (fst == pl[p].end()) continue;
					if (*lst > *fst) {
						res[j] += *lst - *fst;
					}
				}
			}
		}		
	}
	for (int j = 0; j < q; ++j) if (qc[j] == 2) cout << res[j] << '\n';
}