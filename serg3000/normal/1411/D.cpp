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
	string s;
	cin >> s;
	int x, y;
	cin >> x >> y;
	int n = s.size();
	vector<int>a(n);
	forn(i, n) {
		if (s[i] != '?') {
			a[i] = s[i] - '0';
		}
		else {
			a[i] = 2;
		}
	}
	if (y > x) {
		forn(i, n) {
			if (a[i] != 2) {
				a[i] = 1 - a[i];
			}
		}
		swap(x, y);
	}
	int ans = 0;
	int cnt = 0;
	int c1 = 0, c2 = 0;
	int d1 = 0, d2 = 0;
	vector<int>b(n);
	forn(i, n) {
		b[i] = a[i];
		if (b[i] == 2) {
			b[i] = 0;
		}
		if (b[i] == 0) {
			d1++;
		}
		else {
			d2++;
		}
	}
	forn(i, n) {
		
		if (b[i] == 0) {
			cnt += y * c2 + (d2 - c2) * x;
			c1++;
		}
		else {
			cnt += x * c1 + (d1 - c1) * y;
			c2++;
		}
		
	}
	c1 = 0;
	c2 = 0;
	ans = cnt / 2;
	cnt /= 2;
	forn(i, n) {
		if (a[i] == 2) {
			cnt += c1 * x - c2 * y - (d2 - c2) * x + (d1 - c1 - 1) * y;
			ans = min(ans, cnt);
			d1--;
			d2++;
			c2++;
		}
		else {
			if (b[i] == 0) {
				c1++;
			}
			else {
				c2++;
			}
		}
		
	}
	cout << ans;
	return 0;
}