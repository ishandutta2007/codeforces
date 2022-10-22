#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 2e9 + 13;
const int M = 1e9 + 7;
const int N = 3e5 + 13;
const ld eps = 1e-4;

void solve() {
    string s;
    cin >> s;

    int n = s.size();
    vector<bool> dp(n + 1, false);
    dp[0] = true;
    for(int i = 1; i < n; i++) {
        if(s[i] == 'a' && s[i - 1] == 'a' || s[i] == 'b' && s[i - 1] == 'b') {
            dp[i + 1] = dp[i - 1];
            if(i > 1 && s[i - 2] == s[i] && dp[i - 2])
                dp[i + 1] = true;
        }
    }

    cout << (dp[n] ? "YES\n" : "NO\n");
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}