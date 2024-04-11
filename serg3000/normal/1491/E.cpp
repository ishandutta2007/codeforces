#include <fstream>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <set>
#include <queue>
#include <deque>
#include <unordered_set>
#include <map>
#include<unordered_map>
#include <bitset>
#include <random>
#include <ctime>
#include <fstream>
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("fast-math")
#pragma GCC optimize("vpt")
#define ll long long
#define res resize
#define pb push_back
#define rall(v) v.rbegin(), v.rend()
#define forn(i, n) for (int i = 0; i < (int)n; i++)
#define firn(i, n) for (int i = 1; i < (int)n; i++)
#define all(v) v.begin(), v.end()
mt19937 rnd(time(nullptr));
//#define int long long
using namespace std;
vector<vector<int>>g, g2;
vector<int>used, c, dist, sz, par, used2;
vector<int>fi;
int fl1 = -1, fl2 = -5;
void dfs1(int v) {
	used2[v] = 1;
	for (auto u : g2[v]) {
		if (!used2[u]) {
			dfs1(u);
			par[u] = v;
		}
	}
}
void dfs(int v, int k) {
	sz[v] = 0;
	used[v] = 1;
	for (auto u : g[v]) {
		if (!used[u]) {
			dfs(u, k);
			sz[v] += sz[u];
		}
	}
	sz[v] += 1;
	if (k >= 1 && sz[v] == fi[k - 1]) {
		fl1 = k - 1;
		fl2 = v;
	}
	else {
		if (k >= 2 && sz[v] == fi[k - 2]) {
			fl1 = k - 2;
			fl2 = v;
		}
	}
	used[v] = 0;
}
int ser(int v, int k) {
	fl1 = -5;
	dfs(v, k);
	used[v] = 1;
	if (sz[v] == 1 || k == 0 || k == 1) {
		return 1;
	}
	
	if (fl1 == -5) {
		return 0;
	}
	else {
		int fl3 = fl1;
		int s1 = ser(fl2, fl1);
		int s2 = ser(v, k + k - 3 - fl3);
		return s1 * s2;
	}

}
signed main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	int n;
	cin >> n;
	g.resize(n);
	g2.resize(n);
	used.resize(n);
	used2.resize(n);
	par.resize(n);
	sz.resize(n);
	fi.resize(30);


	forn(i, n - 1) {
		int x, y;
		cin >> x >> y;
		x--; y--;
		g2[x].push_back(y);
		g2[y].push_back(x);
	}
	dfs1(0);
	forn(i, n) {
		for (auto u : g2[i]) {
			if (par[u] == i) {
				g[i].push_back(u);
			}
		}
	}
	fi[0] = 1;
	fi[1] = 1;
	for (int i = 2; i < 30; i++) {
		fi[i] = fi[i - 1] + fi[i - 2];
	}
	int fl = -1;
	forn(i, 30) {
		if (n == fi[i]) {
			fl = i;
		}
	}
	if (fl == -1) {
		cout << "NO";
		return 0;
	}
	if (ser(0, fl) == 1) {
		cout << "YES";
		return 0;
	}
	cout << "NO";
	return 0;
}