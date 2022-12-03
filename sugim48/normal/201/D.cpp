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

ll MOD = 1000000007;
ll _MOD = 1000000009;
int INF = INT_MAX / 10;
double EPS = 1e-10;

int main() {
	int N; cin >> N;
	int L = N * (N - 1) / 2;
	vector<vector<int> > unko(1<<N, vector<int>(N));
	rep(S, 1<<N) rep(i, N) if (!(S>>i & 1))
		for (int _i = i + 1; _i < N; _i++)
			unko[S][i] += S>>_i & 1;
	vector<string> word(N);
	rep(i, N) cin >> word[i];
	int T; cin >> T;
	int mi = INF, t0;
	rep(t, T) {
		int M; cin >> M;
		vector<vector<bool> > a(M, vector<bool>(N));
		rep(j, M) {
			string s; cin >> s;
			rep(i, N) a[j][i] = (word[i] == s);
		}
		vector<vector<int> > nxt(M + 2, vector<int>(N, M + 1));
		for (int j = M - 1; j >= 0; j--)
			rep(i, N) {
				nxt[j][i] = nxt[j + 1][i];
				if (a[j][i]) nxt[j][i] = j + 1;
			}
		vector<vector<int> > dp(1<<N, vector<int>(L + 1, M + 1));
		dp[0][0] = 0;
		rep(S, 1<<N) rep(x, L + 1) {
			if (dp[S][x] == M + 1) continue;
			rep(i, N) if (!(S>>i & 1)) {
				int _S = S | 1<<i, _x = x + unko[S][i];
				dp[_S][_x] = min(dp[_S][_x], nxt[dp[S][x]][i]);
			}
		}
		int ans = INF;
		rep(x, L + 1) if (dp.back()[x] != M + 1) ans = min(ans, x);
		if (ans < mi) mi = ans, t0 = t;
	}
	if (mi == INF) {
		cout << "Brand new problem!" << endl;
		return 0;
	}
	cout << t0 + 1 << endl;
	cout << "[:";
	rep(t, L - mi + 1) cout << '|';
	cout << ":]" << endl;
}