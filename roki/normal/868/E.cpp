#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<vector>
#include<set>
#include<algorithm>
#include<iostream>
#include<ctime>
#include<iomanip>
#include<cassert>
#include<memory>
#include<string>
#include<string.h>
#include<math.h>

using namespace std;

typedef double ld;
typedef long long li;
typedef pair<int, int> pt;

const int N = 55;

vector<pt> g[N];
int n;

int init[N];
int s, m;

void read() {
	cin >> n;
	for (int i = 0; i < n - 1; ++i) {
		int a, b, w;
		cin >> a >> b >> w;
		a--, b--;
		g[a].push_back(make_pair(b, w));
		g[b].push_back(make_pair(a, w));
	}
	cin >> s;
	s--;
	cin >> m;
	for (int i = 0; i < m; ++i) {
		int v;
		cin >> v;
		v--;
		init[v]++;
	}
	m -= init[s];
	init[s] = 0;
}

int tsz[N];

int dfs(int v, int p = -1) {
	tsz[v] = init[v];
	for (pt to : g[v])
		if (to.first != p)
			tsz[v] += dfs(to.first, v);
	return tsz[v];
}

int dp[N][N][N][N];

int calc(int v, int u, int front, int back) {
	int & res = dp[v][u][front][back];
	if (res != -1)
		return res;
	if (front + back == 0)
		return res = 0;
	if (front == 0)
		return res = 1e9;
	if (g[v].size() == 1) 
		return res = calc(u, v, back, 0) + (back ? g[v][0].second : 0);

	int l = 0, r = 1e9;
	while (r - l > 1) {
		int mid = (l + r) >> 1;
		int sum = 0;
		for (pt to : g[v]) {
			if (to.first == u)
				continue;
			int lf = 0, rf = front + 1;
			while (rf - lf > 1) {
				int mf = (lf + rf) >> 1;
				if (calc(to.first, v, mf, front + back - mf) + to.second > mid)
					lf = mf;
				else
					rf = mf;
			}
			sum += lf;
		}
		if (sum >= front)
			l = mid;
		else
			r = mid;
	}
	return res = r;
}

void solve() {
	dfs(s);
	memset(dp, -1, sizeof dp);
	int ans = 1e9;
	for (pt to : g[s]) {
		ans = min(ans, calc(to.first, s, tsz[to.first], m - tsz[to.first]) + to.second);
	}
	cout << ans << endl;
}

int main() {

	srand(time(NULL));

	read();
	solve();

	return 0;
}