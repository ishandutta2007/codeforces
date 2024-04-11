#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cassert>
#include <cstdlib>
#include <ctime>

using namespace std;
typedef long long int64;
#ifdef HOME
	#define E(c) cerr<<#c
	#define Eo(x) cerr<<#x<<" = "<<(x)<<endl
	#define Ef(...) fprintf(stderr, __VA_ARGS__)
#else
	#define E(c) ((void)0)
	#define Eo(x) ((void)0)
	#define Ef(...) ((void)0)
#endif

const int SIZE = 100<<10;
const int LOGS = 17;
const int CHARS = 26;

struct Oper {
	int t, f, c;
};
int n;
Oper opers[SIZE];

struct Tree {
	int v;
	int born[SIZE];
	int father[SIZE], fchar[SIZE];
	int hgt[SIZE];

	int fstep[LOGS+1][SIZE];

	void Add(int f, int c, int now) {
		hgt[v] = (f<0 ? 0 : hgt[f] + 1);
		born[v] = now;
		father[v] = f;
		fchar[v] = c;
		v++;
	}
	void BuildStep() {
		memcpy(fstep[0], father, sizeof(father));
		for (int i = 1; i<=LOGS; i++)
			for (int j = 0; j<v; j++) {
				int t = fstep[i-1][j];
				if (t >= 0) t = fstep[i-1][t];
				fstep[i][j] = t;
			}
	}

	int Lift(int vert, int s) {
		int curr = vert;
		for (int lvl = LOGS; lvl>=0; lvl--) {
			if (curr < 0) return curr;
			if (s >= (1<<lvl)) {
				curr = fstep[lvl][curr];
				s -= (1<<lvl);
			}
		}
		assert(s == 0);
		return curr;
	}
};
Tree trees[2];

struct Str {
	int col[2];
	int vert;
	Str(int _c0 = 0, int _c1 = 0, int _v = 0) {
		col[0] = _c0;
		col[1] = _c1;
		vert = _v;
	}
	inline bool operator< (const Str &b) const {
		if (col[0] != b.col[0]) return col[0] < b.col[0];
		if (col[1] != b.col[1]) return col[1] < b.col[1];
		return vert < b.vert;
	}
};

int k;
int suff2vert[SIZE], news2v[SIZE];
int vert2suff[SIZE];
Str sarr[SIZE];
int color[SIZE], nxtcol[SIZE], newcol[SIZE];
int ccnt[SIZE], cptr[SIZE];

void ReverseSuffixSort(const Tree &tree) {
	k = tree.v;

	int cols = CHARS + 1;
	for (int i = 0; i<k; i++) color[i] = 1 + tree.fchar[i];
//	for (int i = 0; i<k; i++) printf("%d ", color[i]); printf("\n");

	for (int lvl = 0; lvl < LOGS; lvl++) {
		for (int i = 0; i<k; i++) {
			int t = i;
			int f = tree.fstep[lvl][i];
			sarr[t] = Str(color[t], (f<0 ? -1 : color[f]), i);
		}

		sort(sarr, sarr+k);

		color[sarr[0].vert] = 0;
		cols = 1;
		for (int i = 1; i<k; i++) {
			int t = sarr[i].vert;
			if (sarr[i-1].col[0] != sarr[i].col[0] || sarr[i-1].col[1] != sarr[i].col[1])
				cols++;
			color[t] = cols-1;

			suff2vert[i] = t;
			vert2suff[t] = i;
		}
/*		for (int i = 0; i<k; i++) printf("%d ", color[i]); printf("\n");
		printf("\n");*/
	}
}

int BinSearchChar(int left, int right, int hgt, int ch) {
	if (left == right) return left;
	left--; right;
	int middle;
	while (right - left > 1) {
		middle = (left + right) >> 1;
		int mid = suff2vert[middle];
		int mv = trees[1].Lift(mid, hgt);
		int mch = (mv<0 ? -1 : trees[1].fchar[mv]);
		if (mch < ch)
			left = middle;
		else
			right = middle;
	}
	return right;
}

int sleft[SIZE], sright[SIZE];

int fenw[2][SIZE];
inline int FH(int x) { return ((x ^ (x+1)) + 1) >> 1; }
void FenwAdd(int idx, int p, int val) {
	for (int i = p; i<k; i+=FH(i))
		fenw[idx][i] += val;
}
int FenwSum(int idx, int p) {
	int res = 0;
	for (int i = p - 1; i>=0; i-=FH(i))
		res += fenw[idx][i];
	return res;
}

string TracePath(const Tree &t, int curr) {
	string s;
	while (curr > 0) {
		s += char('a' + t.fchar[curr]);
		curr = t.father[curr];
	}
	return s;
}

int main() {
#ifdef HOME
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif	

	scanf("%d", &n);
	for (int i = 0; i<n; i++) {
		Oper o;
		char ch;
		scanf(" %d %d %c", &o.t, &o.f, &ch);
		o.t--;  o.f--;
		o.c = ch - 'a';
		opers[i] = o;
	}

	for (int t = 0; t<2; t++)
		trees[t].Add(-1, -1, -1);
	for (int i = 0; i<n; i++)
		trees[opers[i].t].Add(opers[i].f, opers[i].c, i);

	for (int t = 0; t<2; t++)
		trees[t].BuildStep();

	ReverseSuffixSort(trees[1]);
/*	for (int i = 0; i<k; i++)
		printf("%s\n", TracePath(trees[1], suff2vert[i]).c_str());*/

	sleft[0] = 0;
	sright[0] = k;
	for (int x = 1; x<trees[0].v; x++) {
		int fv = trees[0].father[x];
		int fc = trees[0].fchar[x];
		int fh = trees[0].hgt[fv];

		sleft[x] = BinSearchChar(sleft[fv], sright[fv], fh, fc);
		sright[x] = BinSearchChar(sleft[fv], sright[fv], fh, fc + 1);
	}
/*	for (int i = 0; i<trees[0].v; i++) {
		printf("%d: [%d %d] ", i, sleft[i], sright[i]);
		if (sleft[i] < sright[i]) {
			printf("{%s} {%s}",
				TracePath(trees[1], suff2vert[sleft[i]]).c_str(),
				TracePath(trees[1], suff2vert[sright[i] - 1]).c_str()
			);
		}
		printf(" \n");
	}*/

	int64 ans = 1;
	int cv[2] = {1, 1};
	for (int i = 0; i<n; i++) {
		Oper o = opers[i];

		if (o.t == 0) {
			int u0 = cv[0];
			int cnt = FenwSum(0, sright[u0]) - FenwSum(0, sleft[u0]);
			ans += cnt;
			FenwAdd(1, sleft[u0], 1);
			FenwAdd(1, sright[u0], -1);
		}
		else {
			int u1 = cv[1];
			FenwAdd(0, vert2suff[u1], 1);
			int eql = FenwSum(1, vert2suff[u1] + 1);
			ans += (eql + 1);
		}

		cv[o.t]++;
		printf("%I64d\n", ans);
	}

	return 0;
}