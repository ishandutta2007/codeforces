#include "bits/stdc++.h"

#define int long long
#define forn(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

const int mod = 998244353;

int32_t main() {
    ios_base::sync_with_stdio(0);;
    string s;
    cin >> s;
    int x, y;
    cin >> x >> y;
    if (x < y) {
        swap(x, y);
        forn (i, s.size()) {
            if (s[i] == '0') {
                s[i] = '1';
            } else if (s[i] == '1') {
                s[i] = '0';
            }
        }
    }
    vector<int> cnt0(s.size() + 1);
    vector<int> cnt1(s.size() + 1);
    vector<int> cntq(s.size() + 1);
    forn (i, s.size()) {
        cnt0[i + 1] = cnt0[i] + (s[i] == '0');
        cnt1[i + 1] = cnt1[i] + (s[i] == '1');
        cntq[i + 1] = cntq[i] + (s[i] == '?');
    }
    vector<int> sc0(s.size());
    vector<int> sc1(s.size());
    forn (i, s.size()) {
        if (s[i] == '?') {
            sc0[i] = y * cnt1[i] + x * (cnt1[s.size()] - cnt1[i]);
            sc1[i] = x * cnt0[i] + y * (cnt0[s.size()] - cnt0[i]);
        }
    }
    /*forn (i, s.size()) {
        cerr << sc0[i] << " ";
    }
    cerr << endl;
    forn (i, s.size()) {
        cerr << sc1[i] << " ";
    }
    cerr << endl;*/
    vector<int> sum0(s.size() + 1);
    vector<int> sum1(s.size() + 1);
    forn (i, s.size()) {
        sum0[i + 1] = sum0[i] + sc0[i];
        sum1[i + 1] = sum1[i] + sc1[i];
    }
    int ans = 2e18;
    for (int i = 0; i <= s.size(); i++) {
        ans = min(ans, sum1[i] + sum0[s.size()] - sum0[i] + cntq[i] * (cntq[s.size()] - cntq[i]) * y);
    }
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '0') {
            ans += y * cnt1[i];
        } else if (s[i] == '1') {
            ans += x * cnt0[i];
        }
    }
    cout << ans << endl;
}