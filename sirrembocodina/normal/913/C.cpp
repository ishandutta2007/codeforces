#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <string>
#include <cmath>
#include <set>
#include <map>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second

typedef long long ll;
typedef double ld;

int mod = 1000000007;

ll x[100100];

int main() {
    ios::sync_with_stdio(false);
    int n, l;
    cin >> n >> l;
    ll ans = 0;
    forn (i, 31) {
        if (i < n) {
            cin >> x[i];
        } else {
            x[i] = 2 * x[i - 1];
        }
        if (i) {
            x[i] = min(x[i], 2 * x[i - 1]);
        }
        if (l & (1 << i)) {
            ans += x[i];
        } else {
            ans = min(ans, x[i]);
        }
    }
    cout << ans << endl;
    return 0;
}