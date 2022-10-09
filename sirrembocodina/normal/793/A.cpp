#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < n; ++i)
#define pb push_back
#define fs first
#define sc second
#define mp make_pair

long long a[100100];

int main() {
    ios::sync_with_stdio(0);
    int n, k;
    cin >> n >> k;
    long long ans = 0;
    long long mn = 2000000000;
    forn (i, n) {
        cin >> a[i];
        if (a[i] % k != a[0] % k) {
            cout << -1 << endl;
            return 0;
        }
        mn = min(mn, a[i]);
    }
    forn (i, n) {
        ans += (a[i] - mn) / k;
    }
    cout << ans << endl;
    return 0;
}