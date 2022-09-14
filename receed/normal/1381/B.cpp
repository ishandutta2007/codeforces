#include <iostream>
#include <iomanip>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <random>
#include <bitset>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <queue>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

using namespace std;
using ll = long long;
using ul = unsigned long long;
using ld = long double;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t, n;
    cin >> t;
    rep(z, t) {
        cin >> n;
        vector<int> p(2 * n), dp(2 * n + 1);
        int cx = 0, cc = 0;
        dp[0] = 1;
        rep(i, 2 * n) {
            cin >> p[i];
            if (p[i] < cx)
                cc++;
            else if (i == 0) {
                cc = 1;
                cx = p[i];
            }
            else {
                for (int j = 2 * n; j >= cc; j--)
                    if (dp[j - cc])
                        dp[j] = 1;
                cc = 1;
                cx = p[i];
            }
        }
        for (int j = 2 * n; j >= cc; j--)
            if (dp[j - cc])
                dp[j] = 1;
        if (dp[n])
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}