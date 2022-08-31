#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

#define FOR(i,a,b) for(int _n(b),i(a);i<_n;i++) 
#define REP(i,n) FOR(i,0,n)

void setIO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

const int MX = 200005;
const int K = 17;
int nxt[K][MX];
int n, k;
string s;

bool poss(int len) {
    for (int c = 0; c < k; c++) {
        nxt[c][n] = nxt[c][n+1] = n + 1;
        for (int i = n - 1, cnt = 0; i >= 0; i--) {
            if (s[i] == '?' || s[i] - 'a' == c) {
                cnt++;
            } else {
                cnt = 0;
            }
            nxt[c][i] = (cnt >= len) ? (i + len) : nxt[c][i+1];
        }
    }

    vector<int> dp(1<<k, n + 1);
    dp[0] = 0;
    for (int mask = 0; mask < (1 << k); mask++) {
        for (int c = 0; c < k; c++) {
            if (mask >> c & 1)
                continue;
            int nmask = mask | (1 << c);
            dp[nmask] = min(dp[nmask], nxt[c][dp[mask]]);
        }
    }

    return dp.back() <= n;
}

int solve() {
    int lo = 0, hi = n / k;
    while (lo < hi) {
        int mid = (lo + hi + 1) >> 1;
        if (poss(mid))
            lo = mid;
        else
            hi = mid - 1;
    }
    return lo;
}

int main() {
    setIO();
    int t=1; // cin>>t;
    while(t--) {
        cin>>n>>k>>s;
        cout << solve() << endl;
    }
    
    return 0;
}