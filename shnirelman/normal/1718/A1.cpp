#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 2e9 + 13;
const li INF64 = 2e18 + 13;
const int M = 998244353;
//const int A = 1e6 + 13;
const int N = 1e6 + 13;
const int B = 400;
const int LOGN = 20;

mt19937 rnd(7476);

int a[N];
int p[N];
int lst[N];
int dp[N];

void solve() {
    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    p[0] = 0;
    for(int i = 0; i < n; i++) {
        p[i + 1] = p[i] ^ a[i];
        lst[p[i + 1]] = -1;
    }

    int ans = 0;

    dp[0] = 0;
    for(int i = 0; i < n; i++) {
//        lst[p[i]] = i;

        dp[i + 1] = dp[i] + 1;
        for(int j = 0; j <= i; j++) {
            if(p[j] == p[i + 1])
                dp[i + 1] = min(dp[i + 1], dp[j] + i - j);
        }

//        if(lst[p[i + 1]] != -1) {
//            dp[i + 1] = dp[lst[p[i + 1]]] + i - lst[p[i + 1]];
//        } else {
//            dp[i + 1] = dp[i] + 1;
//        }
    }

    cout << dp[n] << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}