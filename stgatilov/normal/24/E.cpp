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
#define E(c) cerr<<#c
#define Eo(x) cerr<<#x<<" = "<<(x)<<endl

const int SIZE = 500<<10;

int n;
int k;
double sx[SIZE], st[SIZE];
int vel[SIZE];

void Cross(int cx, int cv, int t, double &rt, double &rx) {
	double mx = cx + cv * st[t];
	double addt = (mx - sx[t]) / (vel[t] - cv);
	rt = st[t] + addt;
	rx = cx + cv * rt;
}

void Add(int cx, int cv) {
	sx[k] = cx;
	st[k] = 0;
	vel[k] = cv;
	k++;
}

int Find(int cx, int cv) {
	if (cv >= vel[0]) return -1;
	int left = -1;
	int right = k-1;
	int m;
	while (right - left > 1) {
		m = (left + right) / 2;
		if (sx[m] < cx + cv * st[m]) right = m;
		else left = m;
	}
	return right;
}

int main() {
#ifdef _CRT_SECURE_NO_DEPRECATE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif	
	scanf("%d", &n);
	k = 0;
	double ans = 1e+50;
	for (int i = 0; i<n; i++) {
		int cx, cv;
		scanf("%d%d", &cx, &cv);
		if (cv > 0) {
			if (k == 0) Add(cx, cv);
			else {
				int t = Find(cx, cv);
				if (t < 0) {
					k = 0;
					Add(cx, cv);
				}
				else {
					double rt, rx;
					Cross(cx, cv, t, rt, rx);
					st[t] = rt;
					sx[t] = rx;
					k = t + 1;
					Add(cx, cv);
				}
			}
		}
		if (cv < 0) {
			if (k == 0);
			else {
				int t = Find(cx, cv);
				double rt, rx;
				Cross(cx, cv, t, rt, rx);
				if (ans > rt) ans = rt;
			}
		}
	}
	if (ans < 1e+49) printf("%0.20lf\n", ans);
	else printf("-1\n");
	return 0;
}