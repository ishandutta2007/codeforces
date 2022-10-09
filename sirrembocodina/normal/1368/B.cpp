#include "bits/stdc++.h"
 
#define int long long
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
 
using namespace std;
 
vector<vector<pair<int, int>>> g;

int32_t main() {
    ios_base::sync_with_stdio(0);
    int k;
    vector<int> cnt(10, 1);
    cin >> k;
    int n = 1;
    int cur = 0;
    while (n < k) {
        n /= cnt[cur];
        cnt[cur]++;
        n *= cnt[cur];
        cur++;
        cur %= 10;
    }
    string s = "codeforces";
    forn (i, 10) {
        forn (j, cnt[i]) {
            cout << s[i];
        }
    }
    cout << endl;
}