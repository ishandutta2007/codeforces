#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <bitset>
#include <ctime>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 52;
int n, m, k;
char s[maxN][maxN];
int d[maxN][maxN];
char f[maxN][maxN];
int px[maxN][maxN], py[maxN][maxN];

bool allowed[maxN];

string res;
int length = 1000000;

int sx, sy;
int fx, fy;

bool isOk(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < m && (s[x][y] == 'S' || s[x][y] == 'T' || allowed[s[x][y] - 'a']);
}

int dx[] = {-1, 0, 0, 1};
int dy[] = { 0,-1, 1, 0};

void check() {
	queue < pair < int, int > > q;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			d[i][j] = 1000000000;
			f[i][j] = 'z';
		}
	}
	q.push(make_pair(fx, fy));
	d[fx][fy] = 0;
	while (!q.empty()) {
		pair < int, int > current = q.front();
		q.pop();
		int x = current.first;
		int y = current.second;
		for (int i = 0; i < 4; ++i) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (isOk(nx, ny) && d[nx][ny] > d[x][y] + 1) {
				d[nx][ny] = d[x][y] + 1;
				f[nx][ny] = s[x][y];
				px[nx][ny] = x;
				py[nx][ny] = y;
				q.push(make_pair(nx, ny));
			} else if (isOk(nx, ny) && d[nx][ny] == d[x][y] + 1) {
				if (s[x][y] < f[nx][ny]) {
					f[nx][ny] = s[x][y];
					px[nx][ny] = x;
					py[nx][ny] = y;
				}
			}
		}
	}
	if (d[sx][sy] - 1 > length) {
		return;
	}

	string current = "";
	int x = sx;
	int y = sy;
	vector < pair < int, int > > candidates;
	candidates.push_back(make_pair(x, y));
	int len = d[x][y];
	while (len > 1) {
		vector < pair < int, int > > ncandidates;
		char value = 'z';
		for (int i = 0; i < candidates.size(); ++i) {
			int cx = candidates[i].first;
			int cy = candidates[i].second;
			for (int j = 0; j < 4; ++j) {
				int nx = cx + dx[j];
				int ny = cy + dy[j];
				if (isOk(nx, ny) && d[nx][ny] + 1 == d[cx][cy]) {
					if (s[nx][ny] < value) {
						ncandidates.clear();
						ncandidates.push_back(make_pair(nx, ny));
						value = s[nx][ny];
					} else if (s[nx][ny] == value) {
						ncandidates.push_back(make_pair(nx, ny));
					}
				}
			}
		}
		current += value;
		sort(ncandidates.begin(), ncandidates.end());
		candidates = ncandidates;
		candidates.resize(unique(candidates.begin(), candidates.end()) - candidates.begin());
		--len;
	}
	if (current.size() < length || (current.size() == length && current < res)) {
		length = current.size();
		res = current;
	}
}

void rec(int index, int cnt) {
	if (cnt <= k) {
		check();
	}

	if (cnt == k) {
		return;
	}

	for (int i = index; i < 26; ++i) {
		allowed[i] = true;
		rec(i + 1, cnt + 1);
		allowed[i] = false;
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	cin >> n >> m >> k;
	for (int i = 0; i < n; ++i) {
		cin >> s[i];
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (s[i][j] == 'S') {
				sx = i;
				sy = j;
			}
			if (s[i][j] == 'T') {
				fx = i;
				fy = j;
			}
		}
	}

	rec(0, 0);
	if (length == 1000000) {
		cout << -1 << endl;
		return 0;
	}

	cout << res << endl;
	
	return 0;
}