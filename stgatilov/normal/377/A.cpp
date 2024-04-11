//#pragma comment(linker, "/STACK:20000000")
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

const int SIZE = 1<<10;

int n, m, k;
char matr[SIZE][SIZE];
int fcnt;
int sx, sy;

int rem;
bool vis[SIZE][SIZE];
void DFS(int x, int y) {
    vis[x][y] = true;
    rem--;

    static const int dir[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    for (int d = 0; rem && d<4; d++) {
        int nx = x + dir[d][0];
        int ny = y + dir[d][1];
        if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
        if (matr[nx][ny] != '.') continue;
        if (vis[nx][ny]) continue;

        DFS(nx, ny);
    }
}

int main() {
#ifdef HOME
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif	
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i<n; i++)
        scanf("%s", &matr[i]);

    for (int i = 0; i<n; i++)
        for (int j = 0; j<m; j++)
            if (matr[i][j] == '.') {
                sx = i;  sy = j;
                fcnt++;
            }

    rem = fcnt - k;
    DFS(sx, sy);

    for (int i = 0; i<n; i++)
        for (int j = 0; j<m; j++)
            if (matr[i][j] == '.' && !vis[i][j])
                matr[i][j] = 'X';

    for (int i = 0; i<n; i++)
        printf("%s\n", matr[i]);


	return 0;
}