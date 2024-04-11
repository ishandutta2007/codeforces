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

char unko(char c1, char c2) {
	for (char c3 = 'a'; ; c3++)
		if (c1 != c3 && c2 != c3)
			return c3;
}

int main() {
	int n, t; cin >> n >> t;
	string s1, s2; cin >> s1 >> s2;
	int aa = 0, bc = 0;
	for (int i = 0; i < n; i++)
		if (s1[i] == s2[i]) aa++;
		else bc++;
	int x;
	for (x = 0; x <= bc; x += 2) {
		int lb = x / 2 + bc - x;
		int ub = x / 2 + n - x;
		if (lb <= t && t <= ub) break;
	}
	if (x > bc) {
		cout << -1 << endl;
		return 0;
	}
	int y = t - (x / 2 + bc - x);
	string s3(n, ' ');
	for (int i = 0; i < n; i++)
		if (s1[i] == s2[i]) {
			if (y) {
				s3[i] = unko(s1[i], s2[i]);
				y--;
			}
			else s3[i] = s1[i];
		}
		else {
			if (x) {
				s3[i] = (x % 2 ? s1[i] : s2[i]);
				x--;
			}
			else s3[i] = unko(s1[i], s2[i]);
		}
	cout << s3 << endl;
}