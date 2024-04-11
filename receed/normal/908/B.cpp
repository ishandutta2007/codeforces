#include <cstdio>
#include <vector>   
#include <string>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <iomanip>
#include <cstring>

using namespace std;

typedef long long ll;

char a[101][101];
char s[101];
int w[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int n, m, x, y;

int main() {
	//ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	scanf("%d%d", &n, &m);
	int ax, ay, bx, by, f, ans = 0;
	for (int i = 0; i < n; i++) {
		scanf("%s", &a[i]);
		for (int j = 0; j < m; j++) {
			if (a[i][j] == 	'S') {
				ax = i;
				ay = j;
			}
			/*else if (a[i][j] == 'E') {
				bx = i;
				by = j;
			}*/
		}
	}
	scanf("%s", &s);
	int l = strlen(s);
	vector<int> q = {0, 1, 2, 3};
	do {
		x = ax;
		y = ay;
		f = 1;
		for (int i = 0; i < l; i++) {
			x += w[q[s[i] - '0']][0];
			y += w[q[s[i] - '0']][1];
			if (x < 0 || y < 0 || x >= n || y >= m || a[x][y] == '#') {
				f = 0;
				break;
			}
			if (a[x][y] == 'E')
				break;
		}
		if (f && a[x][y] == 'E')
			ans++;
	} while (next_permutation(q.begin(), q.end()));
	printf("%d", ans);
}