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
using namespace std;

#define rep(i, N) for (int i = 0; i < N; i++)
#define pb push_back

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
int INF = INT_MAX / 10;

int main() {
	int N, T; cin >> N >> T;
	N += 2;
	vector<vector<int> > a(N, vector<int>(N, INF));
	for (int i = 1; i < N - 1; i++) a[0][i] = 0;
	int M; cin >> M;
	while (M--) {
		int i, j, x; scanf("%d%d%d", &i, &j, &x);
		a[i][j] = min(a[i][j], x);
	}
	vector<vector<vector<int> > > dpl(T + 1, vector<vector<int> >(N, vector<int>(N, INF))), dpr = dpl;
	rep(l, N) for (int r = l + 1; r < N; r++) dpl[0][l][r] = dpr[0][l][r] = 0;
	for (int t = 1; t <= T; t++)
		rep(l, N)
			for (int r = l + 1; r < N; r++)
				for (int m = l + 1; m <= r - 1; m++) {
					dpl[t][l][r] = min(dpl[t][l][r], min(dpr[t - 1][l][m], dpl[t - 1][m][r]) + a[l][m]);
					dpr[t][l][r] = min(dpr[t][l][r], min(dpl[t - 1][m][r], dpr[t - 1][l][m]) + a[r][m]);
				}
	int ans = min(dpl[T][0][N - 1], dpr[T][0][N - 1]);
	if (ans == INF) ans = -1;
	cout << ans << endl;
}