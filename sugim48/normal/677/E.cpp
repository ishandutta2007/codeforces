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
struct edge { int v; ll w; };

ll MOD = 1000000007;
ll _MOD = 1000000009;
int INF = INT_MAX / 3;
double EPS = 1e-10;

int dy[8] = {0, -1, -1, -1, 0, 1, 1, 1};
int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};

char s[1010];

int N;
char a[1010][1010];
short b[1010][1010][8];
short c[1010][1010][8][2];
bool vis[1010][1010][8];

void f(int y, int x, int k) {
	if (vis[y][x][k]) return;
	vis[y][x][k] = true;
	int _y = y + dy[k], _x = x + dx[k];
	b[y][x][k] = !!a[y][x];
	if (0 <= _y && _y < N && 0 <= _x && _x < N) {
		f(_y, _x, k);
		if (a[y][x]) b[y][x][k] += b[_y][_x][k];
		for (int z = 0; z < 2; z++)
			c[y][x][k][z] = c[_y][_x][k][z] + (a[_y][_x] == z + 2);
	}
}

bool compare(int x2, int x3, int y2, int y3) {
	int k2 = min(x2, y2), k3 = min(x3, y3);
	x2 -= k2; y2 -= k2;
	x3 -= k3; y3 -= k3;
	return log(2)*x2 + log(3)*x3 > log(2)*y2 + log(3)*y3;
}

int main() {
	cin >> N;
	for (int y = 0; y < N; y++) {
		scanf("%s", s);
		for (int x = 0; x < N; x++)
			a[y][x] = s[x] - '0';
	}
	for (int y = 0; y < N; y++)
		for (int x = 0; x < N; x++)
			for (int k = 0; k < 8; k++)
				f(y, x, k);
	bool ok = false;
	int ans2 = 0, ans3 = 0;
	for (int y = 0; y < N; y++)
		for (int x = 0; x < N; x++) {
			for (int t = 0; t < 2; t++) {
				int r = INF;
				for (int k = t; k < 8; k += 2)
					r = min(r, (int)b[y][x][k]);
				if (!r) continue;
				ok = true;
				r--;
				vector<int> num(2);
				for (int k = t; k < 8; k += 2)
					for (int z = 0; z < 2; z++)
						num[z] += c[y][x][k][z] - c[y + dy[k] * r][x + dx[k] * r][k][z];
				if (a[y][x] == 2) num[0]++;
				if (a[y][x] == 3) num[1]++;
				if (compare(num[0], num[1], ans2, ans3))
					ans2 = num[0], ans3 = num[1];
			}
		}
	if (!ok) {
		cout << 0 << endl;
		return 0;
	}
	ll ans = 1;
	while (ans2--) ans = ans * 2 % MOD;
	while (ans3--) ans = ans * 3 % MOD;
	cout << ans << endl;
}