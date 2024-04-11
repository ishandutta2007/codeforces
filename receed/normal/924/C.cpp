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
const double INF = 1e9;
const double EPS = 1e-9;
const int MSIZE = 200000;

void solve(){
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    b[n - 1] = a[n - 1];
    for (int i = n - 2; i >= 0; i--)
        b[i] = max(a[i], b[i + 1] - 1);
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        if (i < n - 1)
            b[i + 1] = max(b[i + 1], b[i] + (a[i] == b[i] ? 1 : 0));
        if (i < n - 1 && b[i + 1] <= b[i] || i == n - 1 && a[i] < b[i])
            ans--;
        ans += b[i] - a[i];
    }
    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
#endif
    solve();
    return 0;
}