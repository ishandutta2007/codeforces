//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define f first
#define s second
//#define x first
//#define y second
//#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;
using pli = pair<li, li>;
//using matr

const li INF = 2e18 + 13;
const int N = 2e5 + 13;
const int M = 998244353;
const int B = 300;
//const int A = 26;
const ld e = 1e-8;
const int LOGN = 20;
const int K = 170;

mt19937 rnd(0);

int sum(int a, int b) {
    a += b;

    return (a >= M ? a - M : a);
}

int dif(int a, int b) {
    return sum(a, M - b);
}

int mul(int a, int b) {
    return a * 1ll * b % M;
}

/*
1
5
0
2 1 5
2 4 5
3 1 2 5
0
*/

vector<int> g[N];
int dp[N];
int used[N];

bool dfs(int v) {
    used[v] = 1;

//    if(g[v].size() == 0) {
//        dp[v] = 1;
//        return false;
//    }

    dp[v] = 1;
    for(auto u : g[v]) {
        if(used[u] == 1)
            return true;

        if(used[u] == 0) {
            if(dfs(u))
                return true;

        }
//            continue;


        dp[v] = max(dp[v], dp[u] + (u > v));
    }

//    cout << v << ' ' << dp[v] << endl;

    used[v] = 2;
    return false;
}

void solve() {
    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        dp[i] = used[i] = 0;
        g[i].erase(g[i].begin(), g[i].end());
    }

    for(int i = 0; i < n; i++) {
        int k;
        cin >> k;

        g[i].resize(k);
        for(int j = 0; j < k; j++) {
            cin >> g[i][j];
            g[i][j]--;
        }
    }

    int ans = 0;
    for(int i = 0; i < n; i++) {
        if(used[i])
            continue;

        if(dfs(i)) {
            cout << -1 << '\n';
            return;
        } else {
            ans = max(ans, dp[i]);
        }
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--) {
        solve();
    }
}