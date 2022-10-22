#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <list>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
//#pragma comment(linker, "/STACK:16777216")
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define N 1005
bool vis[N][N];
void work()
{
    int n, m;
    int i, j, k;
    scanf ("%d %d", &n, &m);
    while (m--) {
        scanf ("%d %d", &i, &j);
        vis[i][j] = 1;
        vis[j][i] = 1;
    }

    for (i=1; i<=n; i++) {
        for (j=1; j<=n; j++) {
            if (vis[i][j]) break;
        }
        if (j > n) break;
    }

    printf ("%d\n", n-1);
    for (j=1; j<=n; j++) {
        if (j == i) continue;
        printf ("%d %d\n", i, j);
    }
}

int main()
{
  std::ios::sync_with_stdio(false);
    work();
  return 0;
}