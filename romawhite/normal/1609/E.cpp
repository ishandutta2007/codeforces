#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/stack:16777216")
#include <string>
#include <vector>
#include <map>
#include <list>
#include <iterator>
#include <set>
#include <queue>
#include <iostream>
#include <sstream>
#include <stack>
#include <deque>
#include <cmath>  
#include <memory.h>
#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <algorithm>
#include <utility>
#include <time.h>
#include <bitset>
using namespace std;

#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define RFOR(i,b,a) for (int i = (b) - 1; i >= (a); i--)
#define ITER(it,a) for (__typeof(a.begin()) it = a.begin(); it != a.end(); it++)
#define FILL(a,value) memset(a, value, sizeof(a))
 
#define SZ(a) (int)a.size()
#define ALL(a) a.begin(), a.end()
#define PB push_back
#define MP make_pair
 
typedef long long Int;
typedef vector<int> VI;
typedef pair<int, int> PII;
 
const double PI = acos(-1.0);
const int INF = 1000 * 1000 * 1000;
const Int LINF = INF * (Int) INF;
const int MAX = 100007;
const int MOD = 1000000007;


int A[MAX];
int B[MAX];


int ta[4 * MAX];
int tb[4 * MAX];
int pa[4 * MAX];
int pb[4 * MAX];
int c[4 * MAX];

void Merge(int v, int l, int r) {
	ta[v] = min(ta[l], ta[r]);
	tb[v] = min(tb[l], tb[r]);
	c[v] = min(min(c[l], c[r]), ta[l] + tb[r]);
}

void Build(int v, int l, int r) {
	if (l == r) {
		ta[v] = A[l];
		tb[v] = B[l];
		c[v] = ta[v] + tb[v];
		return;
	}
	int m = (l + r) / 2;
	Build(2 * v + 1, l, m);
	Build(2 * v + 2, m + 1, r);
	Merge(v, 2 * v + 1, 2 * v + 2);
}

void push(int v) {
	if (pa[v] != 0) {
		pa[2 * v + 1] += pa[v];
		pa[2 * v + 2] += pa[v];
		ta[2 * v + 1] += pa[v];
		ta[2 * v + 2] += pa[v];
		c[2 * v + 1] += pa[v];
		c[2 * v + 2] += pa[v];
		pa[v] = 0;
	}
	if (pb[v] != 0) {
		pb[2 * v + 1] += pb[v];
		pb[2 * v + 2] += pb[v];
		tb[2 * v + 1] += pb[v];
		tb[2 * v + 2] += pb[v];
		c[2 * v + 1] += pb[v];
		c[2 * v + 2] += pb[v];
		pb[v] = 0;
	}
}

void addA(int v, int l, int r, int L, int R, int val) {
	if (L > R)
		return;
	if (l == L && r == R) {
		ta[v] += val;
		pa[v] += val;
		c[v] += val;
		return;
	}
	push(v);
	int m = (l + r) / 2;
	addA(2 * v + 1, l, m, L, min(R, m), val);
	addA(2 * v + 2, m + 1, r, max(L, m + 1), R, val);
	Merge(v, 2 * v + 1, 2 * v + 2);
}

void addB(int v, int l, int r, int L, int R, int val) {
	if (L > R)
		return;
	if (l == L && r == R) {
		tb[v] += val;
		pb[v] += val;
		c[v] += val;
		return;
	}
	push(v);
	int m = (l + r) / 2;
	addB(2 * v + 1, l, m, L, min(R, m), val);
	addB(2 * v + 2, m + 1, r, max(L, m + 1), R, val);
	Merge(v, 2 * v + 1, 2 * v + 2);
}


int main(int argc, char* argv[])
{
	ios::sync_with_stdio(false); cin.tie(0);
	
	int n, q;
	cin >> n >> q;

	string s;
	cin >> s;
	int ca = 0;
	int cb = 0;
	int cc = 0;
	FOR(i,0,SZ(s) + 1) {
		A[i] = ca - cb;
		B[i] = cb - cc;
		if (i < SZ(s)) {
			if (s[i] == 'a') ++ ca;
			if (s[i] == 'b') ++ cb;
			if (s[i] == 'c') ++ cc;
		}
	}
	n ++;

	Build(0, 0, n - 1);

	FOR(i,0,q) {
		int idx;
		char ch;
		cin >> idx >> ch;
		-- idx;
		if (s[idx] == 'a') {
			addA(0, 0, n - 1, idx + 1, n - 1, -1);
		}
		if (s[idx] == 'b') {
			addA(0, 0, n - 1, idx + 1, n - 1, 1);
			addB(0, 0, n - 1, idx + 1, n - 1, -1);
		}
		if (s[idx] == 'c') {
			addB(0, 0, n - 1, idx + 1, n - 1, 1);
			-- cc;
		}
		s[idx] = ch;
		if (s[idx] == 'a') {
			addA(0, 0, n - 1, idx + 1, n - 1, 1);
		}
		if (s[idx] == 'b') {
			addA(0, 0, n - 1, idx + 1, n - 1, -1);
			addB(0, 0, n - 1, idx + 1, n - 1, 1);
		}
		if (s[idx] == 'c') {
			addB(0, 0, n - 1, idx + 1, n - 1, -1);
			++ cc;
		}
		// cout << ta[0] << ' ' << tb[0] << ' ' << c[0] << ' ' << cc << endl;
		cout << c[0] + cc << endl;
	}
	

    cerr << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	return 0;
}