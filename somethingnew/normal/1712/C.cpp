//        
//   @roadfromroi 
//        
#include <iostream>
#include "vector"
#include "algorithm"
#include "numeric"
#include "climits"
#include "iomanip"
#include "bitset"
#include "cmath"
#include "map"
#include "deque"
#include "array"
#include "set"
#define all(x) x.begin(), x.end()
using namespace std;
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<int> srt(n);
    srt[n - 1] = 1;
    for (int i = n - 2; i >= 0; --i) {
        srt[i] = srt[i + 1];
        if (a[i] > a[i + 1])
            srt[i] = 0;
    }
    vector<int> islst(n);
    vector<int> isfrst(n);
    set<int> beb;
    for (int i = 0; i < n; ++i) {
        if (beb.find(a[i]) == beb.end())
            isfrst[i] = 1;
        beb.insert(a[i]);
    }
    beb.clear();
    for (int i = n - 1; i >= 0; --i) {
        if (beb.find(a[i]) == beb.end())
            islst[i] = 1;
        beb.insert(a[i]);
    }
    int res = n;
    int ans = 0;
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (srt[i] and cnt == 0) {
            res = min(res, ans);
        }
        cnt += isfrst[i];
        cnt -= islst[i];
        ans += isfrst[i];
    }
    res = min(res, ans);
    cout << res << '\n';
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}