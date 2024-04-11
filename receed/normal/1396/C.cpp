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

const int N = 1000001;
ll a[N], dp[N], d2[N], t1[N], t2[N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n, r1, r2, r3, d;
    cin >> n >> r1 >> r2 >> r3 >> d;
    rep(i, n) {
        cin >> a[i];
        t1[i] = r1 * a[i] + r3;
        t2[i] = min(r1 * (a[i] + 1), r2) + r1;
    }
    ll s2 = t2[n - 1];
    dp[n - 1] = t1[n - 1];
    d2[n - 1] = t2[n - 1] + d * 2;
    for (int i = n - 2; i >= 0; i--) {
        s2 += t2[i];
        dp[i] = min(s2 + d * (n - i + 1), s2 + d * (n - i - 1) + t1[n - 1] - t2[n - 1]);
        dp[i] = min(dp[i], t1[i] + dp[i + 1]);
        d2[i] = t2[i] + d * 2 + min(d2[i + 1], dp[i + 1]);
        if (i < n - 2) {
            dp[i] = min(dp[i], d2[i + 2] + t2[i + 1] + t1[i]);
            d2[i] = min(d2[i], d2[i + 2] + t2[i + 1] + t2[i] + d * 2);
        }
    }
    cout << min(dp[0], d2[1] + t2[0]) + d * (n - 1);
}