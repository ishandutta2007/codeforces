#include <iostream>
#include <map>
#include <vector>
#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); ++i)

#define pb push_back

int a[200100];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    n *= 2;
    forn (i, n) {
        cin >> a[i];
    }
    sort(a, a + n);
    long long ans = (a[n / 2 - 1] - a[0]) * 1ll * (a[n - 1] - a[n / 2]);
    forn (i, n / 2 - 1) {
        ans = min(ans, (a[n - 1] - a[0]) * 1ll * (a[i + n / 2] - a[i + 1]));
    }
    cout << ans << endl;
}