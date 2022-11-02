#include <bits/stdc++.h>
using namespace std;

#define N 33

bool vis[N][N];
typedef pair <int, int> pii;

map <string, pii> mp;
char s[N];
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    while (k --) {
        scanf("%s", s);
        if (s[0] == '+') {
            int x, y;
            scanf("%d %d %s", &x, &y, s);
            while (x <= n && vis[x][y]) {
                y ++; if (y > m) y = 1, x ++;
            }
            if (x <= n) vis[x][y] = 1, mp[s] = pii(x, y);
        }
        else {
            scanf("%s", s);
            pii p = mp[s]; mp.erase(s);
            if (p.first) printf("%d %d\n", p.first, p.second), vis[p.first][p.second] = 0;
            else puts("-1 -1");
        }
    }

    return 0;
}