#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <string>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <utility>

#define y1 yy1
#define ff first
#define ss second

typedef long long ll;
typedef long double ld;

using namespace std;

const ll N = 1e6 + 34;

int n, m, k;
char a[1000][1000];
bool u[1000][1000];

void dfs(int y, int x) {
    if (y < 0 || x < 0 || y >= n || x >= m) return;
    if (a[y][x] != '.' || u[y][x]) return;
    u[y][x] = true;
    dfs(y - 1, x);
    dfs(y + 1, x);
    dfs(y, x + 1);
    dfs(y, x - 1);
    if (k) {
        k--;
        a[y][x] = 'X';
    }
}

bool fail;

int main()
{
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    scanf("%d%d%d ", &n, &m, &k);
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) scanf("%c ", &a[i][j]);
    for (int i = 0; i < n && !fail; i++) for (int j = 0; j < m && !fail; j++) {
        if (a[i][j] == '.') {
            dfs(i, j);
            fail = true;
        }
    }
    for (int i = 0; i < n; i++, printf("\n")) for (int j = 0; j < m; j++) printf("%c", a[i][j]);
    return 0;
}