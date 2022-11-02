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

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define range(i, n) for(ll i = 0; i < n; ++i)
#define FOR(i, a, b) for (ll i = a; i <= b; i++)
#define print(a) for (auto& i : a) cout << i << " ";
#define input(a) for (auto& i : a) cin >> i;

//#define _GLIBCXX_DEBUG
//#define DEBUG

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	vector<set<int>> g(n + 1, {0});
	int tmp = 0;
	range(i, m) {
		int u, v;
		cin >> u >> v;
		if (v > u)
			swap(u, v);
		if (*g[v].rbegin() < v)
			tmp++;
		g[v].insert(u);
		g[u].insert(v);
	}
	int q;
	cin >> q;
	range(i, q) {
		int t;
		cin >> t;
		if (t == 1) {
			int u, v;
			cin >> u >> v;
			if (v > u)
				swap(u, v);
			if (*g[v].rbegin() < v)
				tmp++;
			g[v].insert(u);
			g[u].insert(v);
		}
		if (t == 2) {
			int u, v;
			cin >> u >> v;
			if (v > u)
				swap(u, v);
			bool flag = false;
			if (*g[v].rbegin() > v)
				flag = true;
			g[v].erase(u);
			g[u].erase(v);
			if (*g[v].rbegin() < v && flag)
				tmp--;
		}
		if (t == 3) {
			cout << n - tmp << "\n";
		}
	}
	return 0;
}