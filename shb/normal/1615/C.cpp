#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

char a[100010], b[100010];

int main() {
    ios::sync_with_stdio(false);
    int T;
    scanf("%d",&T);
    while(T--) {
        int n;
        scanf("%d",&n);
        scanf("%s",a + 1);
        scanf("%s",b + 1);
        vector<vector<int>> cnt(2, vector<int>(2));
        for (int i = 1; i <= n; i++) {
            cnt[a[i] - '0'][b[i] - '0']++;
        }
        const int INF = 1e9;
        int ans = INF;
        if (cnt[1][1] == cnt[0][0] + 1) ans = min(ans, 2 * cnt[1][1] - 1);
        if (cnt[1][0] == cnt[0][1]) ans = min(ans, 2 * cnt[0][1]);
        if (ans == INF) ans = -1;
        printf("%d\n",ans);
    }
}