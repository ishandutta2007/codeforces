#include <cstdio>

using namespace std;

int deg[100005];

int main()
{
    int n, s;
    scanf("%d%d", &n, &s);
    for (int i = 1; i < n; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        deg[u]++, deg[v]++;
    }
    int leafcnt = 0;
    for (int i = 1; i <= n; i++) if (deg[i] == 1) leafcnt++;
    if (n == 2) {
        printf("%d", s);
    } else {
        printf("%.14f", (2.0 * (double)s) / (double)leafcnt);
    }
    return 0;
}