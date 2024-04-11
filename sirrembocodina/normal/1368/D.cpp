#include "bits/stdc++.h"
 
#define int long long
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
 
using namespace std;
 
vector<vector<pair<int, int>>> g;

int32_t main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> cnt(20);
    forn (i, n) {
        cin >> a[i];
        forn (j, 20) {
            if (a[i] & (1 << j)) {
                cnt[j]++;
            }
        }
    }
    int ans = 0;
    forn (i, n) {
        int cur = 0;
        forn (j, 20) {
            if (cnt[j] > i) {
                cur |= 1 << j;
            }
        }
        ans += cur * cur;
    }
    cout << ans << endl;
}