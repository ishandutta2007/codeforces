#include <iostream>
#include <map>
#include <vector>
#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define fs first
#define sc second
#define pb push_back

int n;

int f[300100];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    f[0] = 1;
    forn (i, n) {
        f[i + 1] = f[i] * 1ll * (i + 1) % m;
    }
    long long ans = 0;
    for (int l = 1; l <= n; ++l) {
        long long cur = (n - l + 1) * 1ll * (n - l + 1) % m;
        cur *= f[n - l];
        cur %= m;
        cur *= f[l];
        cur %= m;
        ans += cur;
        ans %= m;
    }
    cout << ans << endl;
}