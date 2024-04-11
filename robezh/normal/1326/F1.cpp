#include <bits/stdc++.h>
using namespace std;

const int N = 14, K = (1 << 14) + 1;
typedef long long ll;

int n;
string str[N];
int to[N][N];
vector<ll> dp[K][N];
ll res[K];

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> str[i];
        for(int j = 0; j < n; j++) to[i][j] = (str[i][j] - '0');
    }
//    n = 14;
    for(int i = 1; i < (1 << n); i++) {
        for(int b = 0; b < n; b++) {
            if(i >> b & 1) dp[i][b].resize(1 << (__builtin_popcount(i)));
        }
    }
    for(int i = 0; i < n; i++) {
        dp[(1 << i)][i][0] = 1;
    }
    for(int i = 1; i < (1 << n); i++) {
        for(int b = 0; b < n; b++) {
            if(dp[i][b].empty()) continue;
            int sz = dp[i][b].size();
            for(int nx = 0; nx < n; nx++) {
                if((i >> nx & 1)) continue;
                for(int j = 0; j < sz; j++) {
                    dp[i ^ (1 << nx)][nx][j * 2 + to[b][nx]] += dp[i][b][j];
                }
            }
        }
    }
    for(int b = 0; b < n; b++) {
        for(int j = 0; j < (1 << (n - 1)); j++) res[j] += dp[(1 << n) - 1][b][j];
    }
//    cout << (double)clock() / CLOCKS_PER_SEC << endl;
    for(int j = 0; j < (1 << (n - 1)); j++) cout << res[j] << " ";
    cout << '\n';


}