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

int n, k;
vector<int> g[N];
int cnt[N][5];
int64 totalSum[N][5];
int64 ans[N];

void dfs(int v, int p = -1) {
	for (int to : g[v]) {
		if (to != p) {
			dfs(to, v);
		}
	}
	static int curCnt[5];
	static int64 curSum[5];
	fill_n(curCnt, 5, 0);
	fill_n(curSum, 5, 0);
	curCnt[0]++;
	for (int to : g[v]) {
		if (p == to) {
			continue;
		}
		static int nextCnt[5];
		static int64 nextTotalSum[5];
		fill_n(nextCnt, 5, 0);
		fill_n(nextTotalSum, 5, 0);
		for (int i = 0; i < k; i++) {
			nextCnt[(i + 1) % k] = cnt[to][i];
			nextTotalSum[(i + 1) % k] = totalSum[to][i] + 1ll * cnt[to][i] * ((i + 1) / k);
		}
		for (int i = 0; i < k; i++) {
			for (int j = 0; j < k; j++) {
				ans[v] += 1ll * curSum[i] * nextCnt[j] + 1ll * curCnt[i] * nextTotalSum[j] + 1ll * curCnt[i] * nextCnt[j] * ((i + j + k - 1) / k);
			}
		}
		for (int i = 0; i < k; i++) {
			curCnt[i] += nextCnt[i];
			curSum[i] += nextTotalSum[i];
		}
	}
	memcpy(cnt[v], curCnt, sizeof(curCnt));
	memcpy(totalSum[v], curSum, sizeof(curSum));
}

int main() {
	cin >> n >> k;
	for (int i = 0; i < n - 1; i++) {
		int u, v; scanf("%d%d", &u, &v), u--, v--;
		g[u].pb(v);
		g[v].pb(u);
	}
	dfs(0);
	int64 ans = 0;
	for (int i = 0; i < n; i++) {
		ans += ::ans[i];
	}
	cout << ans << endl;
    return 0;
}