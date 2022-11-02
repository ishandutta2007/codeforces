//#define _GLIBCXX_DEBUG
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <string>
#include <cmath>
#include <bitset>
#include <unordered_set>
#include <unordered_map>
#include <fstream>
#include <cassert>
#include <random>
#include <cstring>
#include <climits>
#include <time.h>
#include <chrono>
#include <fstream>
//#include <bits/stdc++.h>

typedef int_fast64_t ll;
typedef unsigned long long ull;
typedef long double ld;

#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define print(a) for (auto& _ : a) cout << _ << " ";
#define input(a) for (auto& _ : a) cin >> _;
#define mp make_pair
#define mt make_tuple
#define lb lower_bound
#define ub upper_bound
#define umap unordered_map
#define uset unordered_set
#define mset multiset
#define umset unordered_multiset
#define vll __int128

//#define x first
//#define y second

#define int int_fast64_t
//#define int ll
#define DEBUG

//std::mt19937 rnd(time(0));
std::mt19937 rnd(time(0));
using namespace std;

const int MAXN = 510;

bool used[MAXN][MAXN];
vector<vector<char>> a;
int r1, c1, r, c;

vector<int> di = { 1,-1,0,0 };
vector<int> dj = { 0,0,1,-1 };

void dfs(int i, int j) {
	used[i][j] = true;
	for (int k = 0; k < 4; ++k) {
		int x = i + di[k];
		int y = j + dj[k];
		if (x == r && y == c)
			used[r][c] = true;
		else if (a[x][y] == '.' && !used[x][y])
			dfs(x, y);
	}
}

void solve() {
	int n, m;
	cin >> n >> m;
	a.assign(n + 2, vector<char>(m + 2, 'X'));
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			cin >> a[i][j];
		}
	}
	cin >> r1 >> c1 >> r >> c;
	if ((r1 == r && c1 == c)) {
		cout << (((int)(a[r + 1][c] == '.') + (int)(a[r - 1][c] == '.') + (int)(a[r][c + 1] == '.') + (int)(a[r][c - 1] == '.') >= 1) ? "YES" : "NO");
		return;
	}
	if (abs(r1 - r) + abs(c1 - c) == 1 && a[r][c] == '.') {
		cout << (((int)(a[r + 1][c] == '.') + (int)(a[r - 1][c] == '.') + (int)(a[r][c + 1] == '.') + (int)(a[r][c - 1] == '.') >= 1) ? "YES" : "NO");
		return;
	}
	dfs(r1, c1);
	if (!used[r][c])
		cout << "NO";
	else if (a[r][c] == 'X')
		cout << "YES";
	else
		cout << (((int)(a[r + 1][c] == '.') + (int)(a[r - 1][c] == '.') + (int)(a[r][c + 1] == '.') + (int)(a[r][c - 1] == '.') >= 2) ? "YES" : "NO");
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t = 1;
	//cin >> t;
	while (t--)
		solve();
	return 0;
}