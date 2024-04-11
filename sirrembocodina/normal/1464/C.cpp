#include "bits/stdc++.h"

#define int long long
#define forn(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

int mod = 998244353;

int32_t main() {
    ios_base::sync_with_stdio(0);
    int n, x;
    cin >> n >> x;
    string s;
    cin >> s;
    for (auto& c: s) {
        c -= 'a';
    }
    x -= 1 << s[n - 1];
    x += 1 << s[n - 2];
    n -= 2;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += 1 << s[i];
    }
    sum -= x;
    if (sum < 0 || sum % 2) {
        cout << "No" << endl;
        return 0;
    }
    sum /= 2;
    vector<int> cnt(26);
    forn (i, n) {
        cnt[s[i]]++;
    }
    for (int i = cnt.size() - 1; i >= 0; i--) {
        int cur = min(sum / (1 << i), cnt[i]);
        sum -= cur * (1 << i);
    }
    if (sum) {
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
    }
}