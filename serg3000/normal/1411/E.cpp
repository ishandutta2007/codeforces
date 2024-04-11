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
	int n, t;
	cin >> n >> t;
	string s;
	cin >> s;
	vector<int>st(30);
	int z = 1;
	forn(i, 30) {
		st[i] = z;
		z *= 2;
	}
	vector<int>a(n);
	forn(i, n) {
		a[i] = st[s[i] - 'a'];
	}
	t += a[n - 2] - a[n - 1];
	a.pop_back();
	a.pop_back();
	int c = 0;
	forn(i, n - 2) {
		c += a[i];
		a[i] *= 2;
		
	}
	if (t < -c) {
		cout << "No";
		return 0;
	}
	t += c;
	vector<int>b(n - 2);
	vector<int>ch(63);
	forn(i, n - 2) {
		b[i] = s[i] - 'a' + 1;
		ch[b[i]]++;
	}
	vector<int>e(62);
	int t2 = t;
	forn(i, 62) {
		e[i] = t2 % 2;
		t2 /= 2;
	}
	forn(i, 62) {
		if (e[i] == 1) {
			ch[i]--;
			if (ch[i] < 0) {
				cout << "No";
				return 0;
			}
		}
		ch[i + 1] += ch[i] / 2;
	}
	cout << "Yes";
	return 0;
}