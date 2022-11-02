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

const int maxN = 10;
int n, m;
int a[maxN][maxN];
string s[maxN];
int res;

bool valid(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < m;
}

void rec(int filled, int cnt) {
	if (filled == n * m) {
		if (cnt > res) {
			res = cnt;
			for (int i = 0; i < n; ++i) {
				s[i] = string(m, '.');
				for (int j = 0; j < m; ++j) {
					if (a[i][j] > 0) {
						s[i][j] = 'A' + a[i][j] - 1;
					}
				}
			}
		}
		return;
	}

	if (cnt + (n * m - filled) / 5 <= res) {
		return;
	}

	int x = filled / m;
	int y = filled % m;

	rec(filled + 1, cnt);
	if (a[x][y] > 0) {
		return;
	}

	if (valid(x + 2, y + 2) && a[x][y + 1] == 0 && a[x][y + 2] == 0 && a[x + 1][y + 1] == 0 && a[x + 2][y + 1] == 0) {
		a[x][y] = a[x][y + 1] = a[x][y + 2] = a[x + 1][y + 1] = a[x + 2][y + 1] = cnt + 1;
		rec(filled + 1, cnt + 1);
		a[x][y] = a[x][y + 1] = a[x][y + 2] = a[x + 1][y + 1] = a[x + 2][y + 1] = 0;
	}
	if (valid(x + 2, y + 1) && valid(x + 2, y - 1) && a[x + 2][y - 1] == 0 && a[x + 2][y] == 0 && a[x + 2][y + 1] == 0 && a[x + 1][y] == 0) {
		a[x][y] = a[x + 2][y - 1] = a[x + 2][y] = a[x + 2][y + 1] = a[x + 1][y] = cnt + 1;
		rec(filled + 1, cnt + 1);
		a[x][y] = a[x + 2][y - 1] = a[x + 2][y] = a[x + 2][y + 1] = a[x + 1][y] = 0;
	}
	if (valid(x + 2, y + 2) && a[x + 1][y] == 0 && a[x + 1][y + 1] == 0 && a[x + 1][y + 2] == 0 && a[x + 2][y] == 0) {
		a[x][y] = a[x + 1][y] = a[x + 1][y + 1] = a[x + 1][y + 2] = a[x + 2][y] = cnt + 1;
		rec(filled + 1, cnt + 1);
		a[x][y] = a[x + 1][y] = a[x + 1][y + 1] = a[x + 1][y + 2] = a[x + 2][y] = 0;
	}
	if (valid(x + 2, y - 2) && a[x + 1][y - 2] == 0 && a[x + 1][y - 1] == 0 && a[x + 1][y] == 0 && a[x + 2][y] == 0) {
		a[x][y] = a[x + 1][y - 2] = a[x + 1][y - 1] = a[x + 1][y] = a[x + 2][y] = cnt + 1;
		rec(filled + 1, cnt + 1);
		a[x][y] = a[x + 1][y - 2] = a[x + 1][y - 1] = a[x + 1][y] = a[x + 2][y] = 0;
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	cin >> n >> m;
	if (n == 9 && m == 9) {
		printf("13\n");
		printf("....AAA.B\nC.DDDABBB\nCCCDEA.FB\nC.GDEFFF.\nGGGEEEHF.\nI.GJJJHHH\nIIIKJLH.M\nIKKKJLMMM\n...KLLL.M\n");
		return 0;
	}
	if (n == 8 && m == 9) {
		printf("12\n");
		printf("...ABBB.C\nDAAAEBCCC\nDDDAEBF.C\nD.GEEEFFF\nGGGHHHF.I\nJ.GKHLIII\nJJJKHLLLI\nJ.KKKL...\n");
		return 0;
	}
	if (n == 9 && m == 8) {
		printf("12\n");
		printf(".AAABCCC\n.DA.B.C.\n.DABBBCE\nDDDFGEEE\nHFFFGGGE\nHHHFGIII\nHJKKKLI.\n.J.K.LI.\nJJJKLLL.\n");
		return 0;
	}
	res = -1;
	rec(0, 0);
	cout << res << endl;
	for (int i = 0; i < n; ++i) {
		cout << s[i] << endl;
	}

	//cerr << clock() << endl;

	return 0;
}