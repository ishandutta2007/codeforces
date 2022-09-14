#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <assert.h>
#include <algorithm>
#include <bitset>
#include <cmath>
#include <unordered_map>
#include <iomanip>
using namespace std;

typedef long long ll;

const long long BIT = 64;
const long double INF = 1e9;
const long double EPS = 1e-9;
const int MSIZE = 200000;
typedef long double ld;
const int N = 10003;

void solve(){
    int n, l, r, s = 0;
    cin >> n >> l >> r;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<int> v1, v2;
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        s += a[i];
        if (b[i])
            v2.push_back(a[i]);
        else
            v1.push_back(a[i]);
    }
    swap(l, r);
    l = s - l;
    r = s - r;
    vector<int> dp(N, -INF);
    dp[0] = 0;
    for (int i : v1) 
        for (int j = N - 1; j >= i; j--)
            dp[j] = max(dp[j], dp[j - i]);
    sort(v2.rbegin(), v2.rend());
    for (int i : v2)
        for (int j = N - 1; j >= i; j--)
            dp[j] = max(dp[j], dp[j - i] + (l <= j && j <= r ? 1 : 0));
    int ans = 0;
    for (int i = 0; i < N; i++)
        ans = max(ans, dp[i]);
    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    solve();
    return 0;
}