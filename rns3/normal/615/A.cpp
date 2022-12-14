#include <bits/stdc++.h>
using namespace std;
const int M = 201;
int l[M];
int a[M][M];

int main() {
   // freopen("1.in", "r", stdin);
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i ++) {
        scanf("%d", &l[i]);
        for(int j = 0; j < l[i]; j ++) {
            int x;
            scanf("%d", &x);
            a[i][x] = 1;
        }
    }
    for(int i = 1; i <= m; i ++) {
        int x = -1;
        for(int j = 1; j <= n; j ++) if(a[j][i]) {x = j; break;}
        if(x < 0) return puts("NO");
        for(int j = 1; j <= n; j ++) if(j !=x && a[j][i]) {
            for(int k = i + 1; k <= m; k ++) if(a[k][i]) a[k][i] = 0;
        }
    }
    return puts("YES");
}