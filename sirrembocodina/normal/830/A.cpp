#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <string>
#include <set>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second

typedef long long ll;

int mod = 1000000007;

int a[1010], b[2010];

int main() {
    ios::sync_with_stdio(false);
    int n, k, p;
    cin >> n >> k >> p;
    forn (i, n) {
        cin >> a[i];
    }
    sort(a, a + n);
    forn (i, k) {
        cin >> b[i];
    }
    sort(b, b + k);
    int ans = 2100000000;
    forn (l, k - n + 1) {
        int cur = 0;
        forn (i, n) {
            cur = max(cur, abs(a[i] - b[l + i]) + abs(b[l + i] - p));
        }
        ans = min(ans, cur);
    }
    cout << ans << endl;
    return 0;
}