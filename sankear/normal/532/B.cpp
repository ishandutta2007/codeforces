#include <iostream>
#include <fstream>
#include <sstream>

#include <vector>
#include <set>
#include <bitset>
#include <map>
#include <deque>
#include <string>

#include <algorithm>
#include <numeric>

#include <cstdio>
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>

#define pb push_back
#define pbk pop_back
#define mp make_pair
#define fs first
#define sc second
#define all(x) (x).begin(), (x).end()
#define foreach(i, a) for (__typeof((a).begin()) i = (a).begin(); i != (a).end(); ++i)
#define len(a) ((int) (a).size())

#ifdef CUTEBMAING
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define eprintf(...) 42
#endif

using namespace std;

typedef long long int64;
typedef long double ld;
typedef unsigned long long lint;

const int inf = (1 << 30) - 1;
const int64 linf = (1ll << 62) - 1;
const int N = 1e6 + 100;

int n;
int a[N];
vector<int> g[N];
int64 dp[N][2], cdp[N][2];

void dfs(int v) {
	for (int to : g[v]) {
		dfs(to);
	}
	int len = len(g[v]);
	for (int j = 0; j <= len; j++) {
		for (int z = 0; z < 2; z++) {
			cdp[j][z] = -inf;
		}
	}
	cdp[0][0] = 0;
	for (int i = 0; i < len; i++) {
		for (int j = 0; j < 2; j++) {
			for (int z = 0; z < 2; z++) {
				cdp[i + 1][j ^ z] = max(cdp[i + 1][j ^ z], cdp[i][j] + dp[g[v][i]][z]);
			}
		}
	}
	for (int i = 0; i < 2; i++) {
		dp[v][i] = cdp[len][i];
	}
	dp[v][1] = max(dp[v][1], dp[v][0] + a[v]);
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int v; scanf("%d%d", &v, &a[i]); v--;
		if (v != -2) {
			g[v].pb(i);
		}
	}
	dfs(0);
	cout << max(dp[0][0], dp[0][1]) << endl;
    return 0;
}