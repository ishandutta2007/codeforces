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
    int t, q, n;
    cin >> t;
    rep(z, t) {
        cin >> n >> q;
        vector<int> a(n), dp(n + 1);
        rep(i, n)
            cin >> a[i];
        for (int i = n - 1; i >= 0; --i) {
            dp[i] = dp[i + 1];
            if (a[i] > dp[i])
                dp[i]++;
        }
        int ans = 0, cc = 0, ca, pos = n;
        rep(i, n) {
            if (dp[i] <= q) {
                ca = cc + n - i;
                if (ca > ans) {
                    ans = ca;
                    pos = i;
                }
            }
            if (q >= a[i])
                cc++;
        }
        rep(i, n) {
            if (a[i] <= q || i >= pos)
                cout << 1;
            else
                cout << 0;
        }
        cout << '\n';
    }
}