#include <iostream>
using namespace std;
int vis[1<<5];
int n, k, x;
int main() {
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i ++) {
        int S = 0;
        for (int j = 1; j <= k; j ++) {
            scanf("%d", &x);
            if (x) S |= (1<<(j-1));
        }
        //printf("%d\n", S);
        vis[S] ++;
    }

    int ok = 0;
    if (vis[0]) ok = 1;

    for (int i = 0; i < (1<<4); i ++) if (vis[i])
        for (int j = 0; j < (1<<4); j ++) if (vis[j]) {
            if ( (i&j) == 0 )
                ok = 1;
        }

    printf("%s\n", ok ? "YES" : "NO");
}