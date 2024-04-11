#define _CRT_SECURE_NO_WARNINGS
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
#include <stack>
#include <ctime>
#include <unordered_map>
#include <unordered_set>
#include <list>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 2100;
char s[maxN][maxN];
int n, m;

vector < int > g[maxN][maxN];
int d[maxN][maxN];

bool valid(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < m && s[x][y] == '.';
}

int dx[] = {-1, 0, 0, 1};
int dy[] = { 0,-1, 1, 0};

bool used[maxN][maxN];

pair < int, int > scores[maxN * maxN / 2];
int cnts = 0;

int S[maxN * maxN * 2];
int ss = 0, sf = 0;

void gen() {
	printf("2000 2000\n");
	for (int i = 0; i < 2000; ++i) {
		for (int j = 0; j < 2000; ++j) {
			if (rand() % 2 == 1) {
				printf(".");
			} else {
				printf("*");
			}
		}
		printf("\n");
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	//gen();
	//return 0;

	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i) {
		scanf("%s", &s[i]);
	}

	int odd = 0, even = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (!valid(i, j)) {
				continue;
			}
			for (int k = 0; k < 4; ++k) {
				if (valid(i + dx[k], j + dy[k])) {
					g[i][j].push_back((i + dx[k]) * m + j + dy[k]);
					++d[i][j];
				}
			}
			if (d[i][j] == 0) {
				printf("Not unique\n");
				return 0;
			}
			if ((i + j) % 2 == 0) {
				++even;
			} else {
				++odd;
			}
		}
	}

	if (even != odd) {
		printf("Not unique\n");
		return 0;
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (valid(i, j)) {
				if (d[i][j] == 1) {
					S[sf++] = i * m + j;
				}
			}
		}
	}
	
	while (ss < sf) {
		pair < int, int > p;
		p.second = S[ss++];
		int x = p.second / m;
		int y = p.second % m;
		p.first = d[x][y];
		if (used[x][y]) {
			continue;
		}
		if (p.first == 0 || p.first > 1) {
			printf("Not unique\n");
			return 0;
		}

		int px, py;
		for (int i = 0; i < g[x][y].size(); ++i) {
			int u = g[x][y][i] / m;
			int v = g[x][y][i] % m;
			if (!used[u][v]) {
				px = u;
				py = v;
			}
		}
		
		scores[cnts++] = make_pair(p.second, px * m + py);
		used[px][py] = true;

		for (int i = 0; i < g[px][py].size(); ++i) {
			int cx = g[px][py][i] / m;
			int cy = g[px][py][i] % m;
			if (cx == x && cy == y) {
				continue;
			}
			if (used[cx][cy]) {
				continue;
			}
			--d[cx][cy];
			if (d[cx][cy] == 0) {
				printf("Not unique\n");
				return 0;
			}
			if (d[cx][cy] == 1) {
				S[sf++] = cx * m + cy;
			}
		}
	}

	if (cnts != odd) {
		printf("Not unique\n");
		return 0;
	}

	for (int i = 0; i < cnts; ++i) {
		int ux = scores[i].first / m;
		int uy = scores[i].first % m;

		int vx = scores[i].second / m;
		int vy = scores[i].second % m;

		if (ux == vx) {
			if (uy > vy) {
				swap(uy, vy);
			}
			s[ux][uy] = '<';
			s[vx][vy] = '>';
		} else {
			if (ux > vx) {
				swap(ux, vx);
			}
			s[ux][uy] = '^';
			s[vx][vy] = 'v';
		}
	}

	for (int i = 0; i < n; ++i) {
		puts(s[i]);
	}

	cerr << clock() << endl;


	return 0;
}