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
#include <list>
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
struct edge { ll B, T, F, P; };

unsigned MOD = 1234567891;
ll _MOD = 1000000009;
double EPS = 1e-10;
int UNKO = INT_MAX;

void rotate(vector<string>& a) {
	int n = a.size(), m = a[0].length();
	vector<string> b(m, string(n, ' '));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			b[j][n - 1 - i] = a[i][j];
	a = b;
}

void turn(vector<string>& a) {
	int n = a.size(), m = a[0].length();
	vector<string> b(n, string(m, ' '));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			b[n - 1 - i][j] = a[i][j];
	a = b;
}

ll I(vector<string>& a) {
	int n = a.size(), m = a[0].length();
	ll cnt = 0;
	for (int i = 1; i <= n - 2; i++) {
		bool ok = true;
		for (int j = 0; j < m; j++)
			if (a[i][j] == '#')
				ok = false;
		if (ok) cnt++;
	}
	return cnt;
}

ll L(vector<string>& a) {
	int n = a.size(), m = a[0].length();
	vector<vector<bool> > up(n, vector<bool>(m, true)), left = up;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			if (a[i][j] == '#')
				up[i][j] = left[i][j] = false;
			if (i - 1 >= 0 && !up[i - 1][j]) up[i][j] = false;
			if (j - 1 >= 0 && !left[i][j - 1]) left[i][j] = false;
		}
	ll cnt = 0;
	for (int i = 1; i <= n - 2; i++)
		for (int j = 1; j <= m - 2; j++)
			if (up[i][j] && left[i][j]) cnt++;
	return cnt;
}

ll Z(vector<string>& a) {
	int n = a.size(), m = a[0].length();
	vector<vector<bool> > up(n, vector<bool>(m, true)), down = up;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			if (a[i][j] == '#')
				up[i][j] = false;
			if (i - 1 >= 0 && !up[i - 1][j]) up[i][j] = false;
		}
	for (int i = n - 1; i >= 0; i--)
		for (int j = 0; j < m; j++) {
			if (a[i][j] == '#')
				down[i][j] = false;
			if (i + 1 < n && !down[i + 1][j]) down[i][j] = false;
		}
	ll cnt = 0;
	for (int i = 1; i <= n - 2; i++) {
		int x = 0, y = 0;
		for (int j = 1; j <= m - 2; j++) {
			if (down[i][j]) cnt += x;
			if (up[i][j]) x++;
			if (a[i][j] == '#') x = 0;
		}
	}
	return cnt;
}

ll U(vector<string>& a) {
	int n = a.size(), m = a[0].length();
	vector<vector<bool> > up(n, vector<bool>(m, true));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			if (a[i][j] == '#')
				up[i][j] = false;
			if (i - 1 >= 0 && !up[i - 1][j]) up[i][j] = false;
		}
	ll cnt = 0;
	for (int i = 1; i <= n - 2; i++) {
		int x = 0, y = 0;
		for (int j = 1; j <= m - 2; j++) {
			if (up[i][j]) cnt += y;
			y = x;
			if (up[i][j]) x++;
			if (a[i][j] == '#') x = y = 0;
		}
	}
	return cnt;
}

void f(vector<string>& a) {
	int n = a.size(), m = a[0].length();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cout << a[i][j];
		cout << endl;
	}
}

int main() {
	int n, m; cin >> n >> m;
	vector<string> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	ll ans = 0;
	ans += I(a) + L(a) + Z(a) + U(a);
	rotate(a);
	ans += I(a) + L(a) + Z(a) + U(a);
	rotate(a);
	ans += L(a) + U(a);
	rotate(a);
	ans += L(a) + U(a);
	rotate(a); turn(a);
	ans += Z(a);
	rotate(a);
	ans += Z(a);
	cout << ans << endl;
}