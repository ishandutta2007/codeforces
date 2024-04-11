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
#define x first
#define y second
#define res resize
#define pb push_back
#define rall(v) v.rbegin(), v.rend()
#define forn(i, n) for (int i = 0; i < (int)n; i++)
#define firn(i, n) for (int i = 1; i < (int)n; i++)
#define all(v) v.begin(), v.end()
mt19937 rnd(time(nullptr));
#define int long long
using namespace std;
vector<vector<int>>g;
vector<int>used;
int vv = 0;
void dfs(int v, int pred) {
	used[v] = 1;
	int cnt = 0;
	for (auto u : g[v]) {
		if (!used[u]) {
			if (v == pred) {
				cnt++;
			}
			dfs(u, pred);
			
		}
	}
	if (v == pred && cnt < 2) {
		vv = 1;
	}
}
signed main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	int t;
	cin >> t;
	forn(w, t) {
		int n, m;
		cin >> n >> m;
		used.clear();
		g.clear();
		used.resize(n);
		g.resize(n);
		int c = 0;
		forn(i, m) {
			int x, y;
			map<pair<int, int>, int>mp;
			cin >> x >> y;
			x--; y--;

			if (x == y) {
				c++;
			}
			else {
				g[x].push_back(y);
				g[y].push_back(x);
			}
		}
		forn(i, n) {
			used[i] = 0;
		}
		forn(i, n) {
			vv = 0;
			if (!used[i] && g[i].size() > 1) {
				dfs(i, i);
			}
			if (vv == 1) {
				c--;
			}
		}
		cout << m - c << '\n';
	}
	
	return 0;
}