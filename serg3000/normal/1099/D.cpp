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
using namespace std;
#define int long long
#pragma GCC optimize("Ofast")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,popcnt,abm,mmx,tune=native")
#pragma GCC optimize("fast-math")
#pragma comment(linker, "/STACK:256000000")
#pragma warning(disable:4996)
const int mod = 1e9 + 7;
signed main() {
	int n;
	cin >> n;
	vector<int>par(n);
	par[0] = 0;
	vector<vector<int>>g(n);
	for (int i = 0; i < n - 1; i++) {
		cin >> par[i + 1];
		par[i + 1]--;
		g[i + 1].push_back(par[i + 1]);
		g[par[i + 1]].push_back(i + 1);
	}
	vector<int>a(n);
	vector<int>ans(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	vector<int>dist(n, -1);
	queue<int> Q;
	Q.push(0);
	dist[0] = 1;
	ans[0] = a[0];
	while (!Q.empty()) {
		int k = Q.front();
		Q.pop();
		for (auto u : g[k]) {
			if (dist[u] == -1) {
				Q.push(u);
				dist[u] = dist[k] + 1;
				if (a[u] != -1) {
					ans[u] = a[u] - ans[par[u]] - a[par[par[u]]];
				}
				else {
					int mi = 1e17;
					for (auto w : g[u]) {
						if (dist[w] == -1) {
							mi = min(mi, a[w]);
						}
					}
					if (mi == 1e17) {
						ans[u] = 0;
					}
					else {
						ans[u] = mi - a[par[u]];
					}
				}
				if (ans[u] < 0) {
					cout << -1;
					return 0;
				}
			}
		}
	}
	int sss = 0;
	for (int i = 0; i < n; i++) {
		sss += ans[i];
	}
	cout << sss;
	return 0;
}