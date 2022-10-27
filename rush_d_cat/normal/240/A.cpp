#include <iostream>
using namespace std;
char s[102];
int m, k, a[102], b[102], vis[102];
int mx[102], mn[102];
int n;

int main() {
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
    scanf("%d %d", &m, &k);
    for (int i = 1; i <= k; i ++) {
        scanf("%d", &a[i]);
        vis[a[i]] = 1;
    }
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++) {
        scanf("%s", s);
        int x;
        scanf("%d", &x);
        int zero = 0, fav = 0;
        for (int j = 1; j <= x; j ++) {
            scanf("%d", &b[i]);
            if (vis[b[i]]) 
                fav ++;

            if (b[i] == 0)
                zero ++;
        }
        mx[i] = fav + min(zero, k - fav);
        mn[i] = fav + max(0, zero - ((m-k)-(x-fav-zero)) );
    }
    for (int i = 1; i <= n; i ++) {
        bool fg1 = 1, fg2 = 1;
        for (int j = 1; j <= n; j ++) if (i != j) {
            if (mn[i] < mx[j]) fg1 = 0;
            if (mx[i] < mn[j]) fg2 = 0;
        }
        if (fg1) printf("0\n");
        else if (!fg2) printf("1\n");
        else printf("2\n");
    }
}