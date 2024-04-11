#pragma comment(linker, "/STACK:100000000")
#define _CRT_SECURE_NO_DEPRECATE

#include<set>
#include<map>
#include<algorithm>
#include<cstdio>
#include<string>
#include<cstring>
#include<bitset>
#include<cmath>
#include<complex>
#include<ctime>
#include<iostream>
#include<sstream>
#include<vector>

#define next nexthui
#define prev prevhui
#define pb push_back
#define mp make_pair
#define forn(i,n) for (int i = 0; i < (int)(n); i++)
#define ford(i,n) for (int i = (int)(n)-1; i >= 0; i--)
#define fs first
#define sc second
#define all(x) x.begin(), x.end()
#define sqr(x) ((x)*(x))
#define last(x) ((int)x.size()-1)

using namespace std;

typedef long long int64;
typedef long double ldb;
typedef pair<int64, int64> pii64;

const int INF = (1 << 30) - 1;
const int64 INF64 = (1LL << 62) - 1;
const ldb EPS = 1e-9;

vector<pii64> a, b, p;
map<int64, int64> mm;

int upper(pii64 p1, pii64 p2, pii64 pp) {
	int64 res = (p2.fs - p1.fs) * (pp.sc - p1.sc) - (p2.sc - p1.sc) * (pp.fs - p1.fs);
	if (res > 0) return 1;
	if (res < 0) return -1;
	return 0;
}

vector<pii64> build(int n) {
	mm.clear();
	forn(i, n) {
		int aa, bb;
		scanf("%d%d", &aa, &bb);
		if (!mm.count(aa)) {
			mm[aa] = 0;
		}
		mm[aa] = max(mm[aa], (int64)bb);
	}
	p.clear();
	for (map<int64, int64> ::iterator it = mm.begin(); it != mm.end(); it++) {
		while (p.size() > 0 && it->sc > p[last(p)].sc) {
			p.pop_back();
		}
		while (p.size() > 1 && upper(p[last(p) - 1], p[last(p)], *it) >= 0) {
			p.pop_back();
		}
		p.push_back(*it);
	}
	int yy = p[0].sc;
	reverse(all(p));
	p.pb(pii64(0, yy));
	reverse(all(p));
	return p;
}

bool answer(string s) {
	cout << s << endl;
	exit(0);
}

int main() {
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	int n, m;
	scanf("%d%d", &n, &m);
	int nx, ny;
	scanf("%d%d", &nx, &ny);
	a = build(n);
	b = build(m);
	if (a[last(a)].fs >= b[last(b)].fs) answer("Max");
	if (a[0].sc >= b[0].sc) answer("Max");
	int ib = 1;
	forn(ia, a.size()) {
		while (a[ia].fs > b[ib].fs) ib++;
		if (upper(b[ib-1], b[ib], a[ia]) >= 0) answer("Max");
	}
	answer("Min");
}