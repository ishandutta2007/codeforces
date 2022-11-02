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
int main() {
	int n, x, y, k;
	cin >> n >> k;
	vector<vector<int>>g(n);
	for (int i = 0; i < n - 1; i++) {
		cin >> x >> y;
		x--;
		y--;
		g[y].push_back(x);
		g[x].push_back(y);
	}
	vector<int>dist1(n, -1);
	queue<int>Q1;
	int c = 0;
	for (int i = 0; i < n; i++) {
		if ((int)g[i].size() == 1) {
			c = i;
			break;
		}
	}
	dist1[c] = 0;
	Q1.push(c);
	vector<int>par(n);
	while (!Q1.empty()) {
		int v = Q1.front();
		Q1.pop();
		for (auto u : g[v]) {
			if (dist1[u] == -1) {
				par[u] = v;
				dist1[u] = dist1[v] + 1;
				Q1.push(u);
			}
		}
	}
	
	int z = 0;
	int ser = 0;
	for (int i = 0; i < n; i++) {
		if (dist1[i] == k * 2) {
			if ((int)g[i].size() != 1) {
				cout << "No";
				return 0;
			}
			else {
				z = 1;
				for (int j = 0; j < k; j++) {
					i = par[i];
					ser = i;
				}
				break;
			}
		}
	}
	if (z == 0) {
		cout << "No";
		return 0;
	}
	vector<int>dist(n, -1);
	queue<int>Q;
	dist[ser] = 0;
	Q.push(ser);

	while (!Q.empty()) {
		int v = Q.front();
		Q.pop();
		for (auto u : g[v]) {
			if (dist[u] == -1) {
				dist[u] = dist[v] + 1;
				Q.push(u);
			}
		}
	}
	if ((int)g[ser].size() < 3) {
		cout << "No";
		return 0;
	}
	for (int i = 0; i < n; i++) {
		if (i != ser) {
			if ((int)g[i].size() == 3 || (int)g[i].size() == 2) {
				cout << "No";
				return 0;
			}
		}
		if ((int)g[i].size() == 1 && dist[i] != k) {
			cout << "No";
			return 0;
		}
	}
	cout << "Yes";
	return 0;
}