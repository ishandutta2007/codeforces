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
int INF = INT_MAX / 10;
double EPS = 1e-10;

int N;
char s[200010];

struct unko;
vector<unko*> v;

struct unko {
	int l, r;
	unko *lch, *rch;
	int dp[5][5];
	unko(int _l, int _r) : l(_l), r(_r) {
		if (r - l == 1) {
			rep(x, 5) rep(y, 5) dp[x][y] = (x == y ? 0 : INF);
			if (s[l] == '2') dp[0][0] = 1, dp[0][1] = 0;
			if (s[l] == '0') dp[1][1] = 1, dp[1][2] = 0;
			if (s[l] == '1') dp[2][2] = 1, dp[2][3] = 0;
			if (s[l] == '6') dp[3][3] = dp[4][4] = 1;
			if (s[l] == '7') dp[3][4] = 0;
		}
		else {
			lch = new unko(l, (l + r) / 2);
			rch = new unko((l + r) / 2, r);
			rep(x, 5) rep(y, 5) dp[x][y] = INF;
			for (int x = 0; x < 5; x++)
				for (int y = x; y < 5; y++)
					for (int m = x; m <= y; m++)
						dp[x][y] = min(dp[x][y], lch->dp[x][m] + rch->dp[m][y]);
		}
	}
	void get(int a, int b) {
		if (r <= a || b <= l) return;
		if (a <= l && r <= b) {
			v.pb(this);
			return;
		}
		lch->get(a, b); rch->get(a, b);
	}
};

int main() {
	int Q; cin >> N >> Q;
	scanf("%s", s);
	unko* z = new unko(0, N);
	while (Q--) {
		int a, b; scanf("%d%d", &a, &b); a--;
		v.clear();
		z->get(a, b);
		vector<vector<int> > dp(5, vector<int>(5, INF));
		dp[0][0] = 0;
		vector<vector<int> > _dp(5, vector<int>(5));
		for (unko* z: v) {
			rep(x, 5) rep(y, 5) _dp[x][y] = INF;
			for (int x = 0; x < 5; x++)
				for (int y = x; y < 5; y++)
					for (int m = x; m <= y; m++)
						_dp[x][y] = min(_dp[x][y], dp[x][m] + z->dp[m][y]);
			dp = _dp;
		}
		int ans = dp[0][4];
		if (ans > INF / 2) ans = -1;
		printf("%d\n", ans);
	}
}