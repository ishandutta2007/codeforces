#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 76, K = 20, mod = (int)1e9 + 7;

int n;
string str;
int dp[N][(1 << K)];
int num[N][N];
int full[K + 2];
bool good[1 << (K + 2)];
int nxt1[N];

int res = 0;

void add(int &to, int x) {
    to += x;
    if(to >= mod) to -= mod;
}

int main() {
    cin >> n >> str;
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j <= n; j++) {
            for(int k = i; k < j; k++) {
                num[i][j] *= 2;
                num[i][j] += str[k] - '0';
            }
            num[i][j] --;
        }
    }
    int cur = n;
    for(int i = n; i >= 0; i--) {
        if (str[i] == '1') cur = i;
        nxt1[i] = cur;
    }

    for(int i = 1; i < K + 1; i++) full[i] = ((1 << i) - 1), good[full[i]] = true;
    for(int i = 0; i <= n; i++) {
        for(int mask = 0; mask < (1 << K); mask++) {
            if(mask == 0) dp[i][mask] = 1;
            for(int nxt = nxt1[i] + 1; nxt <= min(n, nxt1[i] + 5); nxt++) {
                int cur = num[i][nxt];
                if(cur >= 20 || cur == -1) continue;
                add(dp[nxt][mask | (1 << cur)], dp[i][mask]);
            }

            if(good[mask] && dp[i][mask]) add(res, dp[i][mask]);
        }
    }
    cout << res << endl;
}