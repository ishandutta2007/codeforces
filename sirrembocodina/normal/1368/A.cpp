#include "bits/stdc++.h"
 
#define int long long
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
 
using namespace std;
 
vector<vector<pair<int, int>>> g;

int32_t main() {
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    forn (q, t) {
        int a, b, n;
        cin >> a >> b >> n;
        int ans = 0;
        while (a <= n && b <= n) {
            if (a > b) {
                b += a;
            } else {
                a += b;
            }
            ans++;
        }
        cout << ans << endl;
    }
}