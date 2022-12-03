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
#include <random>
#include <fstream>
using namespace std;

#define rep(i, N) for (int i = 0; i < N; i++)
#define pb push_back

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> i_i;
typedef pair<ll, int> ll_i;
typedef pair<int, ll> i_ll;
typedef pair<double, int> d_i;
typedef pair<ll, ll> ll_ll;
typedef pair<double, double> d_d;
struct edge { int v; ll w; };

const int MOD = 1000000007;
const int _MOD = 1000000009;
double EPS = 1e-10;
const int INF = INT_MAX / 10;

vector<vector<int> > a[3];
int dp[80][80][80][2];

int main() {
	int N; cin >> N;
	string s; cin >> s;
	rep(i, N) {
		char c = s[i];
		if (c == 'V') s[i] = 'a';
		if (c == 'K') s[i] = 'b';
		if (c != 'V' && c != 'K') s[i] = 'c';
	}
	rep(i, N) {
		vector<int> b(3);
		rep(j, i) b[s[j] - 'a']++;
		a[s[i] - 'a'].pb(b);
	}
	int X = a[0].size(), Y = a[1].size(), Z = a[2].size();
	rep(x, X + 1) rep(y, Y + 1) rep(z, Z + 1) rep(t, 2)
		dp[x][y][z][t] = INF;
	dp[0][0][0][0] = 0;
	rep(x, N + 1) rep(y, N + 1) rep(z, N + 1) rep(t, 2) {
		if (dp[x][y][z][t] == INF) continue;
		if (x < X) {
			int inv = max(0, y - a[0][x][1]) + max(0, z - a[0][x][2]);
			dp[x + 1][y][z][1] = min(dp[x + 1][y][z][1], dp[x][y][z][t] + inv);
		}
		if (!t && y < Y) {
			int inv = max(0, x - a[1][y][0]) + max(0, z - a[1][y][2]);
			dp[x][y + 1][z][0] = min(dp[x][y + 1][z][0], dp[x][y][z][t] + inv);
		}
		if (z < Z) {
			int inv = max(0, x - a[2][z][0]) + max(0, y - a[2][z][1]);
			dp[x][y][z + 1][0] = min(dp[x][y][z + 1][0], dp[x][y][z][t] + inv);
		}
	}
	int ans = min(dp[X][Y][Z][0], dp[X][Y][Z][1]);
	cout << ans << endl;
}