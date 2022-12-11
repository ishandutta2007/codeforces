#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int N = 1e6 + 34;

int n, m, v1, v2;
ll dp[N];
vector <int> es[N];


int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &v1, &v2);
        v1--;
        v2--;
        es[v1].push_back(v2);
        es[v2].push_back(v1);
    }

    for (int i = 0; i < n; i++) {
        dp[i] = 1;
        for (int j = 0; j < es[i].size(); j++)
            if (es[i][j] < i)
                dp[i] = max(dp[i], 1 + dp[es[i][j]]);
    }

    long long ans = 0;
    for (int i = 0; i < n; i++)
        ans = max(ans, dp[i] * es[i].size());

    printf("%I64d", ans);


    return 0;
}