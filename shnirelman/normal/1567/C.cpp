#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define f first
#define s second
//#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;
using pli = pair<li, li>;
//using matr

const li INF = 2e18 + 13;
const int N = 3e5 + 13;
const int M = 998244353;
const int B = 300;
const int A = 26;
const ld e = 1e-8;
const int LOGN = 20;
const int K = 170;

mt19937 rnd(0);

/*
*/


void solve() {
    int n;
    cin >> n;

    vector<int> a;
    while(n > 0) {
        a.push_back(n % 10);
        n /= 10;
    }

    vector<vector<vector<int>>> dp(a.size() + 1, vector<vector<int>>(2, vector<int>(2, 0)));
    dp[0][0][0] = 1;
    for(int i = 0; i < a.size(); i++) {
        for(int j = 0; j < 2; j++) {
            for(int k = 0; k < 2; k++) {
                for(int x = 0; x < 10; x++) {
                    for(int y = 0; y < 10; y++) {
                        if(x + y + j == a[i]) {
                            dp[i + 1][k][0] += dp[i][j][k];
                        } else if(x + y + j == a[i] + 10) {
                            dp[i + 1][k][1] += dp[i][j][k];
                        }
                    }
                }
            }
        }
    }

    cout << dp[a.size()][0][0] - 2 << endl;
}

int main() {
//    ios::sync_with_stdio(0);
//    cin.tie(0);
    int t;
    cin >> t;

    while(t--)
        solve();
}