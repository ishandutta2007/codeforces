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
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxD = 4;
vector < pair < int, int > > p;

double dist(pair < int, int > p, pair < int, int > q) {
	double dx = p.first - q.first;
	double dy = p.second - q.second;
	return sqrt(dx * dx + dy * dy);
}

vector < vector < double > > d;

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j <= m; ++j) {
			if (min(i, n - i) <= maxD && min(j, m - j) <= maxD) {
				p.push_back(make_pair(i, j));
			}
		}
	}

	int r = p.size();
	d.assign(r, vector < double > (r, 0.0));
	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < r; ++j) {
			d[i][j] = dist(p[i], p[j]);
		}
	}
	double best = -1;
	int ni = -1, nj = -1, nk = -1, nl = -1;
	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < r; ++j) {
			for (int k = 0; k < r; ++k) {
				for (int l = 0; l < r; ++l) {
					if (i == j || i == k || i == l || j == k || j == l || k == l) {
						continue;
					}
					double w = d[i][j] + d[j][k] + d[k][l];
					if (w > best) {
						best = w;
						ni = i;
						nj = j;
						nk = k;
						nl = l;
					}
				}
			}
		}
	}

	printf("%d %d\n", p[ni].first, p[ni].second);
	printf("%d %d\n", p[nj].first, p[nj].second);
	printf("%d %d\n", p[nk].first, p[nk].second);
	printf("%d %d\n", p[nl].first, p[nl].second);

	return 0;
}