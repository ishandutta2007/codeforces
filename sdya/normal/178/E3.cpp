#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <bitset>
#include <cstring>
#include <string>
#include <cmath>
#include <queue>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 2100;

int n;
int a[maxN][maxN], used[maxN][maxN], s[maxN][maxN];

bool val(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < n;
}

vector < pair < int, int > > component;

void dfs(int x, int y) {
	if (used[x][y]) return ;
	used[x][y] = true;
	component.push_back(make_pair(x, y));

	for (int i = -1; i <= 1; ++i)
		for (int j = -1; j <= 1; ++j)
			if (val(x + i, y + j) && a[x + i][y + j] == 1)
				dfs(x + i, y + j);
}

int sum(int x, int y) {
	return (x >= 0 && y >= 0) ? s[x][y] : 0;
}

int sum(int lx, int ly, int rx, int ry) {
	return sum(rx, ry) - sum(rx, ly - 1) - sum(lx - 1, ry) + sum(lx - 1, ly - 1);
}

void calc_circles() {
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			used[i][j] = 0;

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j) {
			s[i][j] = a[i][j];
			if (val(i, j - 1)) s[i][j] += s[i][j - 1];
			if (val(i - 1, j)) s[i][j] += s[i - 1][j];
			if (val(i - 1, j - 1)) s[i][j] -= s[i - 1][j - 1];
		}

	int diff = 5;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j) {
			int have = sum(i - diff, j - diff, i + diff, j + diff);
			int total = (min(n - 1, i + diff) - max(0, i - diff) + 1) * (min(n - 1, j + diff) - max(0, j - diff) + 1);
			if ((double)(have) / (double)(total) > 0.6) a[i][j] = 1;
		}

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j) {
			int have = sum(i - diff, j - diff, i + diff, j + diff);
			int total = (min(n - 1, i + diff) - max(0, i - diff) + 1) * (min(n - 1, j + diff) - max(0, j - diff) + 1);
			if ((double)(have) / (double)(total) < 0.3) a[i][j] = 0;
		}

	/*for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j) {
			int have = 0, total = 0;
			for (int k = -5; k <= 5; ++k)
				for (int l = -5; l <= 5; ++l)
					if (val(i + k, j + l)) {
						if (a[i + k][j + l] == 1) ++have;
						++total;
					}
			
		}*/

	int circles = 0, squares = 0;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			if (a[i][j] == 1 && !used[i][j]) {
				component.clear();
				dfs(i, j);
				if (component.size() < 150) continue;
				pair < int, int > mn = make_pair(n, n), mx = make_pair(0, 0);
				for (int k = 0; k < component.size(); ++k) {
					if (component[k].first < mn.first) mn = component[k]; else
						if (component[k].first == mn.first && component[k].second < mn.second) mn = component[k];
					if (component[k].first > mx.first) mx = component[k]; else
						if (component[k].first == mx.first && component[k].second > mx.second) mx = component[k];
				}
				double dx = mn.first - mx.first;
				double dy = mn.second - mx.second;
				double dist = dx * dx + dy * dy;

				int cx = (mn.first + mx.first) / 2;
				int cy = (mn.second + mx.second) / 2;

				int r = (int)(sqrt(dist / 4.0));

				int sum1 = 0, sum2 = 0;
				for (int k = cx - r; k <= cx + r; ++k)
					for (int l = cy - r; l <= cy + r; ++l) {
						if (val(k, l)) {
							int dx = cx - k;
							int dy = cy - l;
							if (dx * dx + dy * dy <= r * r) {
								if (a[k][l] == 1) sum1 ++;
								sum2 ++;
							}
						}
					}


				//fprintf(stderr, "%.10lf\n", (double)(component.size()) / dist);
				fprintf(stderr, "%.10lf\n", (double)(sum1) / (double)(sum2));
				if ((double)(sum1) / (double)(sum2) > 0.8) {
					++circles;
				} else {
					++squares;
				}
				/*if ((double)(component.size()) > 0.65 * dist) {
					++circles;
				} else {
					++squares;
				}*/
			}
	printf("%d %d\n", circles, squares);
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			scanf("%d", &a[i][j]);

	calc_circles();

	return 0;
}