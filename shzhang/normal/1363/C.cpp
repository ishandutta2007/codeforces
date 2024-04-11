#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <cstdlib>
#include <utility>
#include <cmath>
#include <queue>
#include <stack>
#include <cstring>

using namespace std;

#define ll long long

int t;
int deg[1005];

void work(void)
{
    int n, x; scanf("%d%d", &n, &x);
    for (int i = 1; i <= n; i++) deg[i] = 0;
    for (int i = 1; i < n; i++) {
        int u, v; scanf("%d%d", &u, &v);
        deg[u]++; deg[v]++;
    }
    if (deg[x] == 1 || n == 1) {
        printf("Ayush\n"); return;
    } else {
        printf("%s\n", n % 2 ? "Ashish" : "Ayush");
    }
}

int main()
{
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) work();
    return 0;
}