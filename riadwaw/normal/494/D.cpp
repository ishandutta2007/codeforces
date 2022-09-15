//MIPT Ababahalamaha
#pragma comment (linker, "/STACK:128000000")
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <queue>
#include <deque>
#include <cmath>
#include <ctime>
#include <stack>
#include <set>
#include <map>
#include <cassert>
#include <memory.h>
#include <sstream>
using namespace std;

#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

#define forn(i, n) for (int i = 0; i < (int)(n); ++i)

typedef long long li;
typedef long long i64;
typedef long double ld;
typedef vector<int> vi;
typedef pair <int, int> pi;

void solve();


int main() {
#ifdef YA
	//assert(!s.empty());
	freopen("/Users/riad/ClionProjects/for-jhelper/input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	clock_t start = clock();
#else
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	//freopen(FILENAME ".in", "r", stdin);
	//freopen(FILENAME ".out", "w", stdout); 
	cin.tie(0);
#endif
	cout.sync_with_stdio(0);
	cout.precision(10);
	cout << fixed;
	cin.tie(0);
	int t = 1;
	//cin >> t;
	while (t--) {
		//++timer;
		solve();
	}
#ifdef YA
	cerr<<"\n\n\n"<<(clock() - start) / 1.0 / CLOCKS_PER_SEC<<"\n\n\n";
#endif
	return 0;
}

int TIMER = 1;

vector<pair<li, li> > g[101010];
int tin[101010];
int tout[101010];
li depth[101010];
li cntDown[101010];
li sumDistDown[101010];
li sumSqrDistDown[101010];

li sumDist[101010];
li sumSqrDist[101010];
li sumDistUp[101010];
li sumSqrDistUp[101010];

const int MOD = 1000000007;
int n;
int l = 17;
vector<int> up[101010];

void dfs(int v, int p) {
	tin[v] = ++TIMER;
	cntDown[v] = 1;

	up[v][0] = p;
	for (int i = 1; i <= l; ++i)
		up[v][i] = up[up[v][i - 1]][i - 1];

	for (pi to: g[v]) {
		if (to.first == p)
			continue;
		depth[to.first] = depth[v] + to.second;
		depth[to.first] %= MOD;
		dfs(to.first, v);
		cntDown[v] += cntDown[to.first];
		sumDistDown[v] += sumDistDown[to.first] + cntDown[to.first] * to.second;
		sumDistDown[v] %= MOD;
		sumSqrDistDown[v] += sumSqrDistDown[to.first] +
		                     to.second * 2 * sumDistDown[to.first] % MOD +
		                     cntDown[to.first] * to.second % MOD * to.second;
		sumSqrDistDown[v] %= MOD;
	}
	tout[v] = ++TIMER;
}

void dfs2(int v, int p) {
	for(pi to: g[v]) {
		if(to.first == p)
			continue;

		sumDist[to.first] = sumDist[v] - to.second * cntDown[to.first] + to.second * (n - cntDown[to.first]);
		sumDist[to.first] %= MOD;
		sumDistUp[to.first] = (sumDist[to.first] - sumDistDown[to.first]) % MOD;
		sumSqrDist[to.first] = sumSqrDist[v] - 2 * to.second * (sumDistDown[to.first] + to.second * cntDown[to.first] % MOD) + cntDown[to.first] * to.second % MOD * to.second;
		sumSqrDist[to.first] += 2 * to.second * (sumDistUp[to.first] - to.second * (n - cntDown[to.first]) % MOD) + (n - cntDown[to.first]) * to.second % MOD * to.second;
		sumSqrDist[to.first] %= MOD;
		sumSqrDistUp[to.first] = (sumSqrDist[to.first] - sumSqrDistDown[to.first]) % MOD;
		dfs2(to.first, v);
	}
	tout[v] = ++TIMER;
}

bool upper(int v, int u) {
	return (tin[v] <= tin[u] && tout[v] >= tout[u]);
}




int lca (int a, int b) {
	if (upper (a, b))  return a;
	if (upper (b, a))  return b;
	for (int i=l; i>=0; --i)
		if (! upper (up[a][i], b))
			a = up[a][i];
	return up[a][0];
}

li dist(li u, li v) {
	li x = lca(u, v);

	return (depth[u] + depth[v] - 2 * depth[x]) % MOD;
}

void solve() {

	cin >> n;
	for(int i = 0; i < n - 1; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		--a, --b;
		g[a].pb(mp(b, c));
		g[b].pb(mp(a, c));
	}

	for (int i=0; i<n; ++i)
		up[i].resize (l+1);


	dfs(0, 0);

	sumDist[0] = sumDistDown[0];
	sumSqrDist[0] = sumSqrDistDown[0];

	dfs2(0, -1);




	int m;
	cin >> m;
	for(int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		--u, --v;
		li ans = 0;
		li d = dist(u, v);
		if(upper(v, u)) {
			//cout << "F";
			ans = sumSqrDist[u] - (sumSqrDistUp[v] + 2 * d * sumDistUp[v] + d * d % MOD * (n - cntDown[v]));
		}
		else {
			//cout << "S";
			ans = sumSqrDistDown[v] + 2 * d * sumDistDown[v] + cntDown[v] * d % MOD * d;

		}
		ans %= MOD;
		ans = 2 * ans - sumSqrDist[u];
		ans %= MOD;
		ans += MOD;
		ans %= MOD;
		cout << ans << "\n";
	}
}