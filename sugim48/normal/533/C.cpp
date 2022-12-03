#define _USE_MATH_DEFINES
#include <algorithm>
#include <cstdio>
#include <functional>
#include <iostream>
#include <cfloat>
#include <climits>
#include <cstring>
#include <cmath>
#include <fstream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <time.h>
#include <vector>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> i_i;
typedef pair<ll, int> ll_i;
typedef pair<double, int> d_i;
typedef pair<ll, ll> ll_ll;
typedef pair<double, double> d_d;
struct edge { int u, v; ll w; };

ll MOD = 1000000007;
ll _MOD = 1000000009;
double EPS = 1e-10;

int a[3][20][20][20][20];

int f(int t, int xp, int yp, int xv, int yv) {
	int& z = a[t][xp][yp][xv][yv];
	if (z) return z;
	if (!xp && !yp) return z = 1;
	if (!xv && !yv) return z = 2;
	if (xp == xv && yp == yv) return z = t;
	if (t == 1) {
		if (xp && f(2, xp - 1, yp, xv, yv) == 1)
			return z = 1;
		if (yp && f(2, xp, yp - 1, xv, yv) == 1)
			return z = 1;
		return z = 2;
	}
	if (t == 2) {
		if (xv && f(1, xp, yp, xv - 1, yv) == 2)
			return z = 2;
		if (yv && f(1, xp, yp, xv, yv - 1) == 2)
			return z = 2;
		if (xv && yv && f(1, xp, yp, xv - 1, yv - 1) == 2)
			return z = 2;
		return z = 1;
	}
}

int g(int xp, int yp, int xv, int yv) {
	if (xv >= xp && yv >= yp) return 1;
	if (xv >= xp + yp && yv < yp) return 1;
	if (xv < xp && yv >= xp + yp) return 1;
	return 2;
}

int main() {
	/*for (int xp = 0; xp < 20; xp++)
		for (int yp = 0; yp < 20; yp++)
			for (int xv = 0; xv < 20; xv++)
				for (int yv = 0; yv < 20; yv++)
					if (f(1, xp, yp, xv, yv) != g(xp, yp, xv, yv))
						cout << "err" << endl;*/
	int xp, yp, xv, yv;
	cin >> xp >> yp >> xv >> yv;
	cout << (g(xp, yp, xv, yv) == 1 ? "Polycarp" : "Vasiliy") << endl;
}