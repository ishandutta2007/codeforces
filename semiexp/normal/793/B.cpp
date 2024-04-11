#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <stack>
#include <queue>
#include <set>
#include <map>
using namespace std;
#define MOD
#define ADD(X,Y) ((X) = ((X) + (Y)%MOD) % MOD)
typedef long long i64; typedef vector<int> ivec; typedef vector<string> svec;

int H, W;
char S[1010][1010];

void app(int y, int x, int dy, int dx, vector<pair<int, int>> &res)
{
	y += dy; x += dx;
	for (;;) {
		if (!(0 <= y && y < H && 0 <= x && x < W && S[y][x] != '*')) break;
		res.push_back({y, x});
		y += dy; x += dx;
	}
}
vector<pair<int, int>> reachable(int y, int x)
{
	vector<pair<int, int>> res;
	app(y, x, 1, 0, res);
	app(y, x, -1, 0, res);
	app(y, x, 0, 1, res);
	app(y, x, 0, -1, res);
	return res;
}

bool flg1[1010][1010], flg2[1010][1010];

int main()
{
	scanf("%d%d", &H, &W);
	for (int i = 0; i < H; ++i) scanf("%s", S[i]);

	int sy, sx, ty, tx;
	for (int i = 0; i < H; ++i) {
		for (int j = 0; j < W; ++j) {
			if (S[i][j] == 'S') {
				sy = i; sx = j;
			} else if (S[i][j] == 'T') {
				ty = i; tx = j;
			}
		}
	}
	flg1[sy][sx] = true;
	for (auto p : reachable(sy, sx)) {
		int y = p.first, x = p.second;
		flg1[y][x] = true;
		for (auto q : reachable(y, x)) {
			flg1[q.first][q.second] = true;
		}
	}
	if (flg1[ty][tx]) {
		puts("YES");
		return 0;
	}
	for (auto q : reachable(ty, tx)) {
		if (flg1[q.first][q.second]) {
			puts("YES");
			return 0;
		}
	}
	puts("NO");
	return 0;
}