#include <bits/stdc++.h>
using namespace std;

#define N 200005

int g[26];
bool vis[N];
int ans, n, m, k;
char s[N];

int main() {
    int T;
    for (scanf("%d", &T); T --; ) {
        scanf("%d %d %d", &n, &m, &k);
        scanf("%s", s);
		memset(g, 0, sizeof g);
        for (int i = 0; i < k; i ++) g[s[i]-'A'] ++;
        ans = 1e9;
        for (int i = 0; i < 26; i ++) if (g[i]) {
            vis[0] = 1;
            for (int j = 0; j < 26; j ++) if (j != i) {
                for (int x = k; x >= 0; x --) if (vis[x]) vis[x+g[j]] = 1;
            }
            for (int j = 0; j <= k; j ++) if (vis[j]) {
                if (n <= j + g[i] && m <= k - j) {
                    ans = min(ans, max(n-j, 0) * max(m-(k-j-g[i]), 0));
                }
            }
            for (int i = 0; i <= k; i ++) vis[i] = 0;
        }
        printf("%d\n", ans);
    }
    return 0;
}