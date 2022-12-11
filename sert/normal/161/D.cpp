#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 100010;
int dp[N][502];
vector <int> es[N];
long long ans;
int n, k, v1, v2;

void dfs(int v, int pr) {
    int w;
    ll sum[502];
    for (int i = 0; i <= k; i++) sum[i] = 0;

    dp[v][0] = 1;

    for (int i = 0; i < es[v].size(); i++) {
        w = es[v][i];
        if (w == pr)
            continue;
        dfs(w, v);

        for (int j = 0; j < k - 1; j++) {
            dp[v][j + 1] += dp[w][j];
            sum[j] += dp[w][j];
        }
        ans += 2 * dp[w][k - 1];
    }

    for (int i = 0; i < es[v].size(); i++) {
        w = es[v][i];
        if (w == pr)
            continue;

        for (int j = 0; j < k - 1; j++)
            ans += (sum[k - j - 2] - dp[w][k - j - 2]) * dp[w][j];
    }
}

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);

    cin >> n >> k;

    for (int i = 1; i < n; i++) {
        cin >> v1 >> v2;
        v1--;
        v2--;
        es[v1].push_back(v2);
        es[v2].push_back(v1);
    }

    dfs(0, -1);

    cout << ans / 2;


    return 0;
}