#define _USE_MATH_DEFINES
#include <algorithm>
#include <cstdio>
#include <functional>
#include <iostream>
#include <cfloat>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <map>
#include <queue>
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

int N;

int f(int y1, int x1, int y2, int x2) {
	if (y1 >= y2 || x1 >= x2) return 0;
	cout << '?' << ' ' << y1 + 1 << ' ' << x1 + 1 << ' ' << y2 << ' ' << x2 << endl;
	int ans; cin >> ans;
	return ans;
}

vector<int> solve(int Y1, int X1, int Y2, int X2) {
	vector<int> a(4);
	{
		int lb = Y1, ub = Y2;
		while (ub - lb > 1) {
			int mid = (lb + ub) / 2;
			if (f(mid, X1, Y2, X2)) lb = mid;
			else ub = mid;
		}
		a[0] = lb;
	}
	{
		int lb = X1, ub = X2;
		while (ub - lb > 1) {
			int mid = (lb + ub) / 2;
			if (f(Y1, mid, Y2, X2)) lb = mid;
			else ub = mid;
		}
		a[1] = lb;
	}
	{
		int lb = Y1, ub = Y2;
		while (ub - lb > 1) {
			int mid = (lb + ub) / 2;
			if (f(Y1, X1, mid, X2)) ub = mid;
			else lb = mid;
		}
		a[2] = ub;
	}
	{
		int lb = X1, ub = X2;
		while (ub - lb > 1) {
			int mid = (lb + ub) / 2;
			if (f(Y1, X1, Y2, mid)) ub = mid;
			else lb = mid;
		}
		a[3] = ub;
	}
	return a;
}

int main() {
	cin >> N;
	{
		int lb = 0, ub = N;
		while (ub - lb > 1) {
			int mid = (lb + ub) / 2;
			if (f(0, 0, mid, N)) ub = mid;
			else lb = mid;
		}
		if (f(0, 0, ub, N) == 1 && f(ub, 0, N, N) == 1) {
			vector<int> a = solve(0, 0, ub, N);
			vector<int> b = solve(ub, 0, N, N);
			cout << '!' << ' ';
			cout << a[0] + 1 << ' ' << a[1] + 1 << ' ' << a[2] << ' ' << a[3] << ' ';
			cout << b[0] + 1 << ' ' << b[1] + 1 << ' ' << b[2] << ' ' << b[3] << endl;
			return 0;
		}
	}
	{
		int lb = 0, ub = N;
		while (ub - lb > 1) {
			int mid = (lb + ub) / 2;
			if (f(0, 0, N, mid)) ub = mid;
			else lb = mid;
		}
		if (f(0, 0, N, ub) == 1 && f(0, ub, N, N) == 1) {
			vector<int> a = solve(0, 0, N, ub);
			vector<int> b = solve(0, ub, N, N);
			cout << '!' << ' ';
			cout << a[0] + 1 << ' ' << a[1] + 1 << ' ' << a[2] << ' ' << a[3] << ' ';
			cout << b[0] + 1 << ' ' << b[1] + 1 << ' ' << b[2] << ' ' << b[3] << endl;
			return 0;
		}
	}
}