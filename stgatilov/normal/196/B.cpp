#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cassert>
#include <cstdlib>
#include <ctime>

using namespace std;
typedef long long int64;
#ifdef HOME
	#define E(c) cerr<<#c
	#define Eo(x) cerr<<#x<<" = "<<(x)<<endl
	#define Ef(...) fprintf(stderr, __VA_ARGS__)
#else
	#define E(c) ((void)0)
	#define Eo(x) ((void)0)
	#define Ef(...) ((void)0)
#endif

const int dir[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};

const int SIZE = 1520;

int n, m;
char matr[SIZE][SIZE];
int qs;
int qarr[SIZE*SIZE][2];
bool vis[SIZE][SIZE];
int world[SIZE][SIZE][2];

int main() {
#ifdef HOME
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif	
	scanf("%d%d", &n, &m);
	for (int i = 0; i<n; i++) scanf("%s", matr[i]);

	memset(vis, 0, sizeof(vis));
	for (int i = 0; i<n; i++)
		for (int j = 0; j<m; j++) if (matr[i][j] == 'S') {
			qarr[qs][0] = i;
			qarr[qs][1] = j;
			world[i][j][0] = 0;
			world[i][j][1] = 0;
			qs++;
			vis[i][j] = true;
		}

	bool ans = false;
    for (int i = 0; i<qs; i++) {
		const int *curr = qarr[i];
		for (int d = 0; d<4; d++) {
			int next[4];
			next[0] = curr[0] + dir[d][0];
			next[1] = curr[1] + dir[d][1];
			next[2] = world[curr[0]][curr[1]][0];
			next[3] = world[curr[0]][curr[1]][1];
			if (next[0] < 0) {
				next[0] += n;
				next[2]--;
			}
			if (next[0] >= n) {
				next[0] -= n;
				next[2]++;
			}
			if (next[1] < 0) {
				next[1] += m;
				next[3]--;
			}
			if (next[1] >= m) {
				next[1] -= m;
				next[3]++;
			}

			if (matr[next[0]][next[1]] == '#') continue;

			if (!vis[next[0]][next[1]]) {
				vis[next[0]][next[1]] = true;
				memcpy(qarr[qs], next, sizeof(qarr[qs]));
				world[next[0]][next[1]][0] = next[2];
				world[next[0]][next[1]][1] = next[3];
				qs++;
			}
			else {
				const int *q = world[next[0]][next[1]];
				if (next[2] == q[0] && next[3] == q[1]);
			   	else {
/*			   		Eo(next[0]);
			   		Eo(next[1]);
			   		Eo(next[2]);
			   		Eo(next[3]);
			   		Eo(q[0]);
			   		Eo(q[1]);*/
				   	ans = true;
			   	}
			}
		}
    }

    printf("%s\n", ans ? "Yes" : "No");

	return 0;
}