#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const li INF64 = 1e18 + 13;
const int M = 1e9 + 7;
const int N = 5000 + 13;
const int LOGN = 30;
const int L = 2001;

int mul(int a, int b) {
    return a * 1ll * b % M;
}

int a[N];
int lst[N];
int lf[N];
bool is[N][N];
int dp[N];

void solve() {
    int n;
    cin >> n;

    for(int i = 0; i <= n; i++) {
        lst[i] = -1;
        lf[i] = -1;
        dp[i] = 0;

        for(int j = 0; j <= n; j++)
            is[i][j] = false;
    }

    for(int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;

        lf[i] = lst[a[i]];
        lst[a[i]] = i;
    }

    for(int l = 0; l < n; l++) {
        is[l][l] = true;
        vector<int> cnt(n, 0);
        int mx = 0;
        for(int r = l + 1; r <= n; r++) {
            cnt[a[r - 1]]++;
            mx = max(mx, cnt[a[r - 1]]);

            int len = r - l;
            if(len % 2 == 0 && mx * 2 <= len)
                is[l][r] = true;
        }
    }
    is[n][n] = true;

    for(int i = 0; i < n; i++) {
        if(is[0][i])
            dp[i] = 1;
        else
            dp[i] = -INF;
        for(int j = lf[i]; j > -1; j = lf[j])
            if(is[j + 1][i])
                dp[i] = max(dp[i], dp[j] + 1);
    }

    int ans = 0;
    for(int i = 0; i < n; i++) {
        if(is[i + 1][n])
            ans = max(ans, dp[i]);
    }

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}