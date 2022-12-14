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
string f[256], e[256], t[256];
int bg, ed, inq[3][256];
pair<int, int> q[N];
void call_f(int);
void call_t(int);
void call_e(int);
string better(string x, string y) {
	if (x.size() == 0) return y;
	if (y.size() == 0) return x;
	if (x.size() > y.size()) return y;
	if (x.size() < y.size()) return x;
	if (x < y) return x;
	return y;
}
void add_e(int pos) {
	int id = 0;
	if (!inq[id][pos]) {
		inq[id][pos] = 1;
		q[ed++] = mp(id, pos);
	}
}

void add_t(int pos) {
	int id = 1;
	if (!inq[id][pos]) {
		inq[id][pos] = 1;
		q[ed++] = mp(id, pos);
	}
}
void add_f(int pos) {
	int id = 2;
	if (!inq[id][pos]) {
		inq[id][pos] = 1;
		q[ed++] = mp(id, pos);
	}
}
void call_f(int pos) {
	{
		string nxt = "!";
		nxt += f[pos];
		if (better(nxt, f[pos ^ 255]) != f[pos ^ 255]) {
			f[pos ^ 255] = nxt;
			add_f(pos ^ 255);
		//	call_f(pos ^ 255);
		}
	}
	{
		string nxt = f[pos];
		if (better(nxt, t[pos]) != t[pos]) {
			t[pos] = nxt;
			add_t(pos);
//			call_t(pos);
		}
	}
	{
		for (int mask = 0; mask < 256; ++mask) if (t[mask] != "") {
			string nxt = t[mask];
			nxt += '&';
			nxt += f[pos];
			if (better(nxt, t[mask & pos]) != t[mask & pos]) {
				t[mask & pos] = nxt;
				add_t(mask & pos);
		//		call_t(mask & pos);
			}
		}
	}
}
void call_e(int pos) {
	{
		string nxt = "(";
		nxt += e[pos];
		nxt += ')';
		if (better(nxt, f[pos]) != f[pos]) {
			f[pos] = nxt;
			add_f(pos);
		//	call_f(pos);
		}
	}
	{
		for (int mask = 0; mask < 256; ++mask) if (t[mask] != "") {
			string nxt = e[pos];	
			nxt += '|';
			nxt += t[mask];
			if (better(nxt, e[mask | pos]) != e[mask | pos]) {
				e[mask | pos] = nxt;
				add_e(mask | pos);
	//			call_e(mask | pos);
			}
		}
	}
}
void call_t(int pos) {
	{
		string nxt = t[pos];
		if (better(nxt, e[pos]) != e[pos]) {
			e[pos] = t[pos];
			add_e(pos);
		//	call_e(pos);
		}
	}
	{
		for (int mask = 0; mask < 256; ++mask) if (f[mask] != "") {
			string nxt = t[pos];
			nxt += '&';
			nxt += f[mask];
			if (better(nxt, t[mask & pos]) != t[mask & pos]) {
				t[mask & pos] = nxt;
				add_t(mask & pos);
		//		call_t(mask & pos);
			}
		}
	}
	{
		for (int mask = 0; mask < 256; ++mask) if (e[mask] != "") {
			string nxt = e[mask];
			nxt += '|';
			nxt += t[pos];
			if (better(nxt, e[pos | mask]) != e[pos | mask]) {
				e[pos | mask] = nxt;
				add_e(pos | mask);
		//		call_e(pos | mask);
			}
		}
	}
}
int main() {
	for (int add = 0; add <= 2; ++add) {
		int cmask = 0;
		for (int mask = 0; mask < 8; ++mask) if (mask >> add & 1) {
			cmask |= 1 << mask;	
		}
		f[cmask] = char('x' + (2 - add));
		add_f(cmask);
	}
	while (bg != ed) {
		auto x = q[bg++];
		int id = x.first, pos = x.second;
		inq[id][pos] = 0;
		if (id == 0) {
			call_e(pos);
		} else if (id == 1) {
			call_t(pos);
		} else {
			call_f(pos);
		}
	}
	for (int mask = 0; mask < 256; ++mask) {
		string res = f[mask];
		res = better(res, t[mask]);
		res = better(res, e[mask]);
		if (res.size() == 0) {
			assert(0);	
		}
	}
	int n;
	cin >> n;
	while (n--) {
		string s;
		cin >> s;
		int mask = 0;
		for (int j = 0; j < 8; ++j) mask |= (s[j] - '0') << j;
		string res = f[mask];
		res = better(res, t[mask]);
		res = better(res, e[mask]);
		cout << res << '\n';
	}
}