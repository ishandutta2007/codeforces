#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <set>
#include <map>
#include <bitset>
#include <cmath>
#include <stack>
#include <ctime>
#include <unordered_map>
#include <unordered_set>
#include <list>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 30;
int n;
int a[maxN], b[maxN], c[maxN];

const int maxL = 2000000;

struct State {
	int da, db, t;
	int mask;
	State() {
		da = db = t = 0;
		mask = 0;
	}
	State(int da, int db, int t, int mask) : da(da), db(db), t(t), mask(mask) {}
	bool operator < (const State &other) const {
		return make_pair(da, make_pair(db, -t)) < make_pair(other.da, make_pair(other.db, -other.t));
	}

	State neg() {
		return State(-da, -db, 1000000000, mask);
	}
};

State u[maxL], v[maxL];
int lu, lv;
int p[30];

void rec(int m, int a[], int b[], int c[], int n, int x, int y, int z, int mask, State u[], int &k) {
	if (m == n) {
		u[k++] = State(y - x, z - x, x, mask);
		return;
	}

	rec(m + 1, a, b, c, n, x, y + b[m], z + c[m], mask, u, k);
	rec(m + 1, a, b, c, n, x + a[m], y, z + c[m], mask + p[m], u, k);
	rec(m + 1, a, b, c, n, x + a[m], y + b[m], z, mask + p[m] + p[m], u, k);
}

void gen(int l, int r, State u[], int &k) {
	int aa[maxN], bb[maxN], cc[maxN];
	int nn = 0;
	for (int i = l; i <= r; ++i) {
		aa[nn] = a[i];
		bb[nn] = b[i];
		cc[nn] = c[i];
		++nn;
	}
	k = 0;
	rec(0, aa, bb, cc, nn, 0, 0, 0, 0, u, k);
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	p[0] = 1;
	for (int i = 1; i < 30; ++i) {
		p[i] = p[i - 1] * 3;
	}

	scanf("%d", &n);
	int n1 = n / 2;
	int n2 = n - n1;

	for (int i = 0; i < n; ++i) {
		scanf("%d%d%d", &a[i], &b[i], &c[i]);
	}

	gen(0, n1 - 1, u, lu);
	gen(n1, n - 1, v, lv);

	sort(v, v + lv);

	vector < string > res;
	int s = -1000000000;

	string f[3] = {"MW", "LW", "LM"};
	for (int i = 0; i < lu; ++i) {		
		int index = lower_bound(v, v + lv, u[i].neg()) - v;
		if (index < lv && v[index].da + u[i].da == 0 && v[index].db + u[i].db == 0) {
			if (u[i].t + v[index].t > s) {
				s = u[i].t + v[index].t;
				int m1 = u[i].mask;
				int m2 = v[index].mask;
				
				res.clear();
				for (int j = 0; j < n1; ++j) {
					res.push_back(f[m1 % 3]);
					m1 /= 3;
				}
				for (int j = 0; j < n2; ++j) {
					res.push_back(f[m2 % 3]);
					m2 /= 3;
				}
			}
		}
	}

	if (s == -1000000000) {
		printf("Impossible\n");
	} else {
		for (int i = 0; i < res.size(); ++i) {
			printf("%s\n", res[i].c_str());
		}
	}



	return 0;
}