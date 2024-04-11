#include<bits/stdc++.h>
using namespace std;

typedef pair <int, int> pii;

#define N 1010

int a[N][N], c[N][N], d[N][N], cntr[N], cntc[N];
pii b[N];

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i ++) for(int j = 1; j <= m; j ++) scanf("%d", a[i] + j);
    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= m; j ++) b[j] = pii(a[i][j], j);
        sort(b + 1, b + m + 1);
        cntr[i] = 1;
        c[i][b[1].second] = 1;
        for(int j = 2; j <= m; j ++) {
            if(b[j].first != b[j-1].first) cntr[i] ++;
            c[i][b[j].second] = cntr[i];
        }
    }
    for(int i = 1; i <= m; i ++) {
        for(int j = 1; j <= n; j ++) b[j] = pii(a[j][i], j);
        sort(b + 1, b + n + 1);
        cntc[i] = 1;
        d[b[1].second][i] = 1;
        for(int j = 2; j <= n; j ++) {
            if(b[j].first != b[j-1].first) cntc[i] ++;
            d[b[j].second][i] = cntc[i];
        }
    }
    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= m; j ++) {
            if(c[i][j] > d[i][j]) printf("%d ", max(cntr[i], cntc[j] + c[i][j] - d[i][j]));
            else printf("%d ", max(cntr[i] + d[i][j] - c[i][j], cntc[j]));
        }
        puts("");
    }
}