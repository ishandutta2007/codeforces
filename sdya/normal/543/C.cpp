#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <set>
#include <map>
#include <bitset>
#include <cmath>
#include <ctime>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 20;
const int inf = 1000000000;
int d[1 << maxN];
string s[maxN];
int a[maxN][maxN];
int n, m;

int price[maxN];

vector < pair < int, int > > moves;

void setInf(int d[]) {
	for (int i = 0; i < (1 << n); ++i) {
		d[i] = inf;
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		cin >> s[i];
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> a[i][j];
		}
	}

	for (int i = 0; i < n; ++i) {
		price[i] = inf;
		for (int j = 0; j < m; ++j) {
			price[i] = min(price[i], a[i][j]);
		}

		for (int j = 0; j < m; ++j) {
			bool isOk = true;
			for (int k = 0; k < n; ++k) {
				if (k == i) {
					continue;
				}
				if (s[k][j] == s[i][j]) {
					isOk = false;
				}
			}
			if (isOk) {
				price[i] = 0;
			}
		}
	}
	
	for (int i = 0; i < m; ++i) {
		for (int j = 'a'; j <= 'z'; ++j) {
			int mask = 0;
			int cost = 0, mx = 0;
			int cnt = 0;
			for (int k = 0; k < n; ++k) {
				if (s[k][i] == j) {
					mask |= (1 << k);
					cost += a[k][i];
					mx = max(mx, a[k][i]);
					++cnt;
				}
			}
			if (cnt > 1) {
				moves.push_back(make_pair(mask, cost - mx));
			}
		}
	}

	setInf(d);
	d[0] = 0;
	for (int step = 0; step < moves.size(); ++step) {
		int mask = moves[step].first;
		int cost = moves[step].second;
		for (int i = 0; i < (1 << n); ++i) {
			if (d[i] == inf) {
				continue;
			}
			d[i | mask] = min(d[i | mask], d[i] + cost);
		}
	}

	int res = inf;
	for (int i = 0; i < (1 << n); ++i) {
		int cost = d[i];
		for (int j = 0; j < n; ++j) {
			if ((i & (1 << j)) == 0) {
				cost += price[j];
			}
		}
		res = min(res, cost);
	}
	cout << res << endl;

	return 0;
}