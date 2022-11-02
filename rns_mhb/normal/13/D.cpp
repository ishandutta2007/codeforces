#include<bits/stdc++.h>
using namespace std;

#define N 505

int f[N][N];

struct pnt{
    int x, y;
    bool operator < (const pnt &A) const {return y < A.y;}
    void in(){scanf("%d%d", &x, &y);}
} Red[N], Blue[N];

bool func(pnt A, pnt B, pnt C) {
    if(C.y <= A.y || C.y > B.y) return 0;
    if(1ll*(B.y-A.y)*C.x < 1ll*(B.y-C.y)*A.x + 1ll*(C.y-A.y)*B.x) return 1;
    return 0;
}

int main() {
    int n, m, i, j, k, rlt = 0;
    scanf("%d%d", &n, &m);
    for(i = 1; i <= n; i ++) Red[i].in();
    for(i = 1; i <= m; i ++) Blue[i].in();
    sort(Red + 1, Red + n + 1);
    for(i=1;i<n;i++)for(j=i+1;j<=n;j++)for(k=1;k<=m;k++)if(func(Red[i],Red[j],Blue[k])) f[i][j] ++;
    for(i=1;i<n;i++)for(j=i+1;j<n;j++)for(k=j+1;k<=n;k++)if(f[i][j]+f[j][k]==f[i][k]) rlt ++;
    printf("%d\n", rlt);
}