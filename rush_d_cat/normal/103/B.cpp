#include <iostream>
using namespace std;
int par[102];

int find(int x) 
{
    if (par[x] == x) return x;
    return par[x] = find(par[x]);
}

void unite(int x, int y) 
{
    int cx = find(x);
    int cy = find(y);
    par[cx] = cy;
}


int n, m;
int x[10000], y[10000];

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; i ++) 
    {
        scanf("%d %d", &x[i], &y[i]);
    }

    if (n != m || n < 3) return 0 * printf("NO\n");

    int ok = 0;

    for (int i = 1; i <= m; i ++) {

        for (int j = 1; j <= n; j ++) par[j] = j;

        for (int j = 1; j <= m; j ++) 
        {
            if (j == i) continue;
            unite(x[j], y[j]);
        }

        int cnt = 0;
        for (int j = 1; j <= n; j ++) 
        {
            if (par[j] == j) cnt ++;
        }

        if (cnt == 1) ok ++;
    }

    if (ok >= 3) printf("FHTAGN!\n");
    else printf("NO\n");
}