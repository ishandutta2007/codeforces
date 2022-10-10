#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAXN = 2e5 + 10;
int pr[MAXN], a[MAXN], dp[MAXN];

void sieve() {
    for(int p = 2; p < MAXN; p++) {
        if(pr[p])
            continue;
        for(int q = p; q < MAXN; q += p)
            pr[q] = p;
    }
}

void solve() {
    //cout << "SOLVING TESTCASE" << endl;
    int n, ans = 0;
    cin >> n;
    memset(a, 0, sizeof a);
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a[x]++;
    }
    for(int i = 1; i < MAXN; i++) {
        dp[i] = a[i];
        int x = i;
        vector<int> pf;
        while(x > 1) {
            int p = pr[x];
            pf.push_back(p);
            while(x % p == 0)
                x /= p;
        }
        for(auto &p : pf)
            dp[i] = max(dp[i], a[i] + dp[i / p]);
        ans = max(ans, dp[i]);
    }
    cout << n - ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    sieve();

    int t;
    cin >> t;
    while(t--)
        solve();
}