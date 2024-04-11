//        
//   @roadfromroi 
//        
#include <iostream>
#include "vector"
#include "algorithm"
#include "numeric"
#include "climits"
#include "iomanip"
#include "bitset"
#include "cmath"
#include "map"
#include "deque"
#include "array"
#include "set"
#define all(x) x.begin(), x.end()
using namespace std;
#define int long long 

int dp[105][105][2][2];
void solve() {
    int n;
    cin >> n;
    int cnt1 = 0, cnt0 = 0;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        if (x % 2)
            cnt1++;
    }
    cnt0 = n - cnt1;
    if (dp[cnt1][cnt0][0][0]) {
        cout << "Alice\n";
    } else {
        cout << "Bob\n";
    }
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            dp[0][0][i][j] = i ^ j ^ 1;
        }
    }
    for (int i = 0; i < 105; ++i) {
        for (int j = 0; j < 105; ++j) {
            for (int k = 0; k < 2; ++k) {
                for (int l = 0; l < 2; ++l) {
                    if (l == 0) {
                        if (i > 0 and dp[i - 1][j][k ^ 1][l ^ 1] == 0) {
                            dp[i][j][k][l] = 1;
                        }
                        if (j > 0 and dp[i][j - 1][k][l ^ 1] == 0) {
                            dp[i][j][k][l] = 1;
                        }
                    } else {
                        if (i > 0 and dp[i - 1][j][k][l ^ 1] == 0) {
                            dp[i][j][k][l] = 1;
                        }
                        if (j > 0 and dp[i][j - 1][k][l ^ 1] == 0) {
                            dp[i][j][k][l] = 1;
                        }
                    }
                }
            }
        }
    }
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}