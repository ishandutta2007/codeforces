//#define _GLIBCXX_DEBUG
#include <iostream>
#include <iomanip>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include <deque>
#include <string>
#include <cmath>
#include <bitset>
#include <unordered_set>
#include <unordered_map>
#include <fstream>
//#include <bits/stdc++.h>

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#pragma GCC optimize("O3")

#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define print(a) for (auto& _ : a) cout << _ << " ";
#define input(a) for (auto& _ : a) cin >> _;
#define mp make_pair
#define lb lower_bound
#define ub upper_bound

//#define ll long long
//#define DEBUG

using namespace std;

vector<ll> cmp0, cmp1, num;

struct com {
	int u;
	string s;
};

vector<vector<com>> g;
bool flag = true;

void dfs(int v) {
	for (auto [u, s] : g[v]) {
		if (num[u] == -1) {
			if (s == "imposter") {
				num[u] = (num[v] + 1) % 2;
				if (num[u])
					cmp1.back()++;
				else
					cmp0.back()++;
				dfs(u);
			}
			else {
				num[u] = num[v];
				if (num[u])
					cmp1.back()++;
				else
					cmp0.back()++;
				dfs(u);
			}
		}
		else {
			int tmp;
			if (s == "imposter")
				tmp = (num[v] + 1) % 2;
			else
				tmp = num[v];
			if (tmp != num[u])
				flag = false;
		}
	}
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	ll t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		cmp0.clear();
		cmp1.clear();
		num.assign(n + 1, -1);
		g.clear();
		g.resize(n + 1);
		flag = true;
		for (int i = 0; i < m; ++i) {
			int x, y;
			string s;
			cin >> x >> y >> s;
			g[x].push_back({ y, s });
			g[y].push_back({ x, s });
		}
		for (int i = 1; i <= n; ++i) {
			if (num[i] == -1) {
				cmp0.push_back(1);
				cmp1.push_back(0);
				num[i] = 0;
				dfs(i);
			}
		}
		if (!flag) {
			cout << "-1\n";
			continue;
		}
		int res = 0;
		for (int i = 0; i < cmp0.size(); ++i)
			res += max(cmp0[i], cmp1[i]);
		cout << res << "\n";
	}
	return 0;
}