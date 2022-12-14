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
map<string, int> rev, have;
vector<pair<string, string>> res;
int mark[N], tp[N];
string t[N], to_st[N];
void move(int v, string nw) {
	res.push_back(mp(t[v], nw));
	have[t[v]] = 0;
	t[v] = nw;
	have[nw] = 1;
}
int main() {
	srand(time(0));
	int n;
	cin >> n;
	int cnt = 0;
	for (int j = 0; j < n; ++j) {
		cin >> t[j] >> tp[j];	
		have[t[j]] = 1;
		cnt += tp[j];
	}
	for (int num = 1; num <= n; ++num) {
		stringstream ss;
		ss << num;
		string s;
		ss >> s;
		to_st[num] = s;
		rev[s] = num;
	}
	set<int> out[2], in[2], emp[2];
	for (int j = 0; j < n; ++j) {
		if (rev[t[j]] == 0) {
			out[tp[j]].insert(j);
		} else {
			int place = rev[t[j]] <= cnt ? 1 : 0;
			if (place != tp[j]) {
				in[place].insert(j);
			}
		}
		mark[rev[t[j]]] = 1;
	}
	for (int j = 1; j <= cnt; ++j) if (!mark[j]) emp[1].insert(j);
	for (int j = cnt + 1; j <= n; ++j) if (!mark[j]) emp[0].insert(j);
	while (true) {
		int c = 0;
		for (int j = 0; j < 2; ++j) {
			if (in[j].size()) c = 1;
			if (out[j].size()) c = 1;
		}
		if (!c) break;
		int vis = 0;
		for (int j = 0; j < 2; ++j) {
			if (in[j].size()) {
				int v = *(in[j].begin());
				if (emp[j ^ 1].size()) {
					int pos = rev[t[v]];
					emp[j].insert(pos);
					int x = *emp[j ^ 1].begin();
					emp[j ^ 1].erase(x);
					in[j].erase(v);
					move(v, to_st[x]);
					vis = 1;
				}
				c = 2;
			}
		}
		if (vis) continue;
		if (c == 2) {
			string rnd = "";
			while (true) {
				for (int j = 0; j < 6; ++j) {
					char ch = (rand() % 26) + 'a';
					rnd += ch;
				}
				if (have[rnd] || rev[rnd]) {
					rnd.clear();
					continue;	
				}
				break;
			}
			int x = *in[0].begin();
			emp[0].insert(rev[t[x]]);
			in[0].erase(x);
			out[1].insert(x);
			move(x, rnd);
			continue;
		}
		for (int j = 0; j < 2; ++j) {
			if ((int) out[j].size()) {
				int v = *(out[j].begin());
				int x = *(emp[j].begin());
				out[j].erase(v);
				emp[j].erase(x);
				move(v, to_st[x]);
			}
		}
	}
	cout << (int) res.size() << '\n';
	for (auto x : res)
		cout << "move " << x.first << ' ' << x.second << '\n';
}