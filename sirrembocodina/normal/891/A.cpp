#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <string>
#include <set>
#include <map>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second

typedef long long ll;

int mod = 1000000007;

int a[2010];

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main() {
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    bool was = false;
    forn (i, n) {
        cin >> a[i];
        if (a[i] == 1) {
            was = true;
        }
    }
    if (was) {
        int ans = 0;
        forn (l, n) {
            ans += a[l] != 1;
        }
        cout << ans << endl;
        return 0;
    }
    int mn = 1000000000;
    forn (l, n) {
        int d = 0;
        for (int r = l; r < n; ++r) {
            d = gcd(d, a[r]);
            if (d == 1) {
                mn = min(mn, r - l);
                break;
            }
        }
    }
    if (mn == 1000000000) {
        cout << -1 << endl;
        return 0;
    }
    cout << mn + n - 1 << endl;
    return 0;
}