#define _USE_MATH_DEFINES
#include <algorithm>
#include <bitset>
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
typedef pair<int, ll> i_ll;
typedef pair<ll, int> ll_i;
typedef pair<double, int> d_i;
typedef pair<ll, ll> ll_ll;
typedef pair<double, double> d_d;
struct edge { int u, v; ll w; };
typedef bitset<400> bs;

ll MOD = 1000000007;
ll _MOD = 1000000009;
int INF = INT_MAX / 10;
double EPS = 1e-10;

char A[410][410], a[410][410];

int main() {
	int H, W; cin >> H >> W;
	rep(Y, H) scanf("%s", A[Y]);
	int h, w; cin >> h >> w;
	rep(y, h) scanf("%s", a[y]);
	vector<vector<vector<bool> > > match(h, vector<vector<bool> >(H, vector<bool>(W)));
	rep(Y, H) {
		vector<vector<bs> > b(w, vector<bs>(26));
		rep(X, W) rep(x, w) {
			int k = A[Y][(X + x) % W] - 'a';
			b[x][k][X] = true;
		}
		rep(y, h) {
			bs bb; bb = ~bb;
			rep(x, w) {
				if (a[y][x] == '?') continue;
				int k = a[y][x] - 'a';
				bb &= b[x][k];
			}
			rep(X, W) match[y][Y][X] = bb[X];
		}
	}
	vector<vector<bool> > ans(H, vector<bool>(W));
	rep(Y, H) rep(X, W) {
		bool ok = true;
		rep(y, h) if (!match[y][(Y + y) % H][X]) ok = false;
		if (ok) ans[Y][X] = true;
	}
	rep(Y, H) {
		rep(X, W) printf("%d", (int)ans[Y][X]);
		cout << endl;
	}
}