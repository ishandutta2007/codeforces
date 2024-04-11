#include <bits/stdc++.h>
#define pii pair<int, int>
#define fi first
#define se second
#define ll long long

using namespace std;

const int N = 200500;
const int inf = 1e9 + 50;
const int mod = 998244353;

char str[N], ans[N];
int cnt[105], dp[105][105];

int main() {

    int tcase;
    scanf("%d", &tcase);
    while (tcase--) {
        int n, k;
        scanf("%d%d%s", &n, &k, str);
        fill(cnt, cnt + 50, 0);
        for (int i = 0; i < 25; i++) for (int j = 0; j < k; j++) dp[j][i] = 0;
        for (int i = 0; i < n; i++) cnt[str[i] - 'a']++;
        for (int i = 0; i < 25; i++) {
            for (int j = 0; j < cnt[i] && j < k; j++) {
                dp[j][i] = 1;
            }
        }
        for (int i = 0; i < k; i++) {
            int j = 0;
            for (j = 0; j < 25 && j < n / k; j++) if (dp[i][j] == 0) break;
            ans[i] = 'a' + j;
        }
        ans[k] = 0;
        printf("%s\n", ans);
    }

    return 0;
}