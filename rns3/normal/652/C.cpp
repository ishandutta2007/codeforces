#include <bits/stdc++.h>
using namespace std;

#define M 1000001

int nxt[M], p[M], pos[M];

int main() {
    ///freopen("c.in", "r", stdin);
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i ++) {
        scanf("%d", &p[i]);
        pos[p[i]] = i;
    }
    for(int i = 1; i <= n; i ++) nxt[i] = n + 1;
    while(m --) {
        int x, y;
        scanf("%d %d", &x, &y);
        int xx = pos[x];
        int yy = pos[y];

        if(xx > yy) swap(xx, yy);
        nxt[xx] = min(nxt[xx], yy);
    }
    long long ans = 0;
    int res = n;
    for(int i = n; i; i --) {
        res = min(res, nxt[i] - 1);
        ans += (res - i + 1);
    }
    cout << ans << endl;
}