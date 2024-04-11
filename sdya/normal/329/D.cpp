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
#include <queue>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxMoves = 10000000;

int calculate(vector < string > s, int x, int y) {
	int moves = 0;
	int res = 0;
	int n = s.size();
	while (moves < maxMoves) {
		if (x < 0 || y < 0 || x >= n || y >= n) {
			break;
		}
		++moves;
		if (s[x][y] == '>') {
			int ending = -1;
			for (int j = y + 1; j < n; ++j) {
				if (s[x][j] != '.') {
					ending = j - 1;
					break;
				}
			}
			if (ending > y) {
				++res;
			}
			if (ending == -1) {
				ending = n - 1;
			}
			swap(s[x][y], s[x][ending]);
			y = ending + 1;
		} else if (s[x][y] == '<') {
			int ending = n + 1;
			for (int j = y - 1; j >= 0; --j) {
				if (s[x][j] != '.') {
					ending = j + 1;
					break;
				}
			}
			if (ending < y) {
				++res;
			}
			if (ending == n + 1) {
				ending = 0;
			}
			swap(s[x][y], s[x][ending]);
			y = ending - 1;
		} else if (s[x][y] == '^') {
			int ending = n + 1;
			for (int j = x - 1; j >= 0; --j) {
				if (s[j][y] != '.') {
					ending = j + 1;
					break;
				}
			}
			if (ending < x) {
				++res;
			}
			if (ending == n + 1) {
				ending = 0;
			}
			swap(s[x][y], s[ending][y]);
			x = ending - 1;
		} else {
			int ending = -1;
			for (int j = x + 1; j < n; ++j) {
				if (s[j][y] != '.') {
					ending = j - 1;
					break;
				}
			}
			if (ending > x) {
				++res;
			}
			if (ending == -1) {
				ending = n - 1;
			}
			swap(s[x][y], s[ending][y]);
			x = ending + 1;
		}
	}
	return res;
}

const int maxN = 110;
char s[maxN][maxN];
int n;

string t = ">v<^";

int add = 0;

bool valid(int x, int y) {
	return add <= x && x + add < n && add <= y && y + add < n;
}

int dx[] = { 0, 1, 0,-1};
int dy[] = { 1, 0,-1, 0};

void gen(int x, int y, int dir, int iters = 0) {
	if (iters > 3000) {
		return;
	}
	s[x][y] = t[dir];
	int moves = 1 + rand() % 3;
	int ny = y + dy[dir] * moves;
	int nx = x + dx[dir] * moves;
	if (valid(nx, ny)) {
		if (s[nx][ny] != '.') {
			nx = x + dx[dir] * (moves - 1);
			ny = y + dy[dir] * (moves - 1);
		}
		s[nx][ny] = t[dir];
		gen(nx, ny, dir, iters + 1);
	} else {
		if (dir + 1 >= 4) {
			++add;
			nx = min(max(nx, add), n - 1 - add);
			ny = min(max(ny, add - 1), n - add);
		} else {
			nx = min(max(nx, add), n - 1 - add);
			ny = min(max(ny, add), n - 1 - add);
		}
		
		s[nx][ny] = t[(dir + 1) % 4];
		gen(nx, ny, (dir + 1) % 4, iters + 1);
	}
}

vector < string > build() {
	vector < string > res;
	for (int i = 0; i < n; ++i) {
		string cur = "";
		for (int j = 0; j < n; ++j) {
			cur += s[i][j];
		}
		res.push_back(cur);
	}
	return res;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	cin >> n;
	if (n == 5) {
		cout <<
			">...v\n"
			"v.<..\n"
			"..^..\n"
			">....\n"
			"..^.<\n"
			"1 1\n";
	} else if (n == 3) {
		cout <<
			">vv\n"
			"^<.\n"
			"^.<\n"
			"1 3\n";
	} else {
		string a = 
			"v<.<.<.<.<.<.<.<.<.<.<.<.<.<.<.<.<.<.<.<.<.<.<.<.<.<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n"
			">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>.>^\n";
		for (int i = 0; i < 50; ++i) {
			cout << a;
		}
		cout << "1 1\n";
	}

	//gen(0, 0, 0);
	/*for (int i = 0; i < n; ++i) {
		puts(s[i]);
	}*/
	//cout << calculate(build(), 1, 0) << endl;
	return 0;
}