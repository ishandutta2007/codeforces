#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <random>
using namespace std;
#define MOD
#define ADD(X,Y) ((X) = ((X) + (Y)%MOD) % MOD)
typedef long long i64; typedef vector<int> ivec; typedef vector<string> svec;

const int low = -100000000, high = 100000000;
const bool enable_test = false;
vector<int> evert, ehori;
int n_asked = 0;

int ask(int x, int y)
{
	++n_asked;

	if (enable_test) {
		int ret = high - low;
		for (int x2 : evert) ret = min(ret, abs(x - x2));
		for (int y2 : ehori) ret = min(ret, abs(y - y2));
		return ret;
	}

	printf("0 %d %d\n", x, y);
	fflush(stdout);

	int ans;
	scanf("%d", &ans);
	return ans;
}

mt19937 rnd;

bool has_horiz(int y)
{
	for (int i = 0; i < 3; ++i) {
		int x = uniform_int_distribution<int>(low, high)(rnd);
		if (ask(x, y) != 0) return false;
	}
	return true;
}
bool has_vert(int x)
{
	for (int i = 0; i < 3; ++i) {
		int y = uniform_int_distribution<int>(low, high)(rnd);
		if (ask(x, y) != 0) return false;
	}
	return true;
}

vector<int> vert, hori;
int gaps[31];

void smaller(int st, int &x, int &y, bool &fin)
{
	for (int i = st; i < 31; ++i) {
		int g = gaps[i];
		if (x + g > high) {
			fin = true;
			return;
		}

		int dd = ask(x + g, y + g);
		if (dd == 0) {
			if (has_horiz(y + g)) hori.push_back(y + g);
			if (has_vert(x + g)) vert.push_back(x + g);
			x += g;
			y += g;
			break;
		} else if (dd < g) {
			if (ask(x + g + dd, y + g) == 0) {
				vert.push_back(x + g + dd);
				if (ask(x + g, y + g + dd) == 0) hori.push_back(y + g + dd);
			} else {
				hori.push_back(y + g + dd);
			}
			x += g + dd;
			y += g + dd;
			break;
		}
	}
}

int main()
{
	if (enable_test) {
		int n, m;
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; ++i) {
			int v;
			scanf("%d", &v);
			evert.push_back(v);
		}
		for (int i = 0; i < m; ++i) {
			int v;
			scanf("%d", &v);
			ehori.push_back(v);
		}
	}
	random_device dev;
	rnd = mt19937(dev());

	int x = low, y = low;

	int init = ask(x, y);
	if (init == 0) {
		if (has_horiz(y)) hori.push_back(y);
		if (has_vert(x)) vert.push_back(x);
	} else {
		if (ask(x + init, y) == 0) vert.push_back(x + init);
		if (ask(x, y + init) == 0) hori.push_back(y + init);
		x += init;
		y += init;
	}

	gaps[0] = 1;
	gaps[1] = 2;
	for (int i = 2; i < 31; ++i) gaps[i] = gaps[i - 1] * 2 - 1;

	for (;;) {
		bool fin = false;
		if (x + gaps[10] > high) {
			smaller(0, x, y, fin);
		} else {
			if (ask(x + gaps[10], y + gaps[10]) == gaps[10]) {
				smaller(11, x, y, fin);
			} else {
				smaller(0, x, y, fin);
			}
		}

		if (fin) break;
	}

fin:
	printf("1 %d %d\n", vert.size(), hori.size());
	for (int i = 0; i < vert.size(); ++i) printf("%d%c", vert[i], i == vert.size() - 1 ? '\n' : ' ');
	for (int i = 0; i < hori.size(); ++i) printf("%d%c", hori[i], i == hori.size() - 1 ? '\n' : ' ');
	fflush(stdout);

	if (enable_test) fprintf(stderr, "%d\n", n_asked);

	return 0;
}