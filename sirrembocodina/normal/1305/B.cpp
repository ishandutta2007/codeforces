#include "bits/stdc++.h"

#define int long long
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(0);
    string s;
    cin >> s;
    int n = s.size();
    int A = 0, B = 0;
    forn (i, n) {
        if (s[i] == ')') {
            ++B;
        }
    }
    int ans = 0;
    forn (i, n) {
        if (A == B) {
            ans = i;
            break;
        }
        if (s[i] == ')') {
            --B;
        } else {
            ++A;
        }
        if (A == B) {
            ans = i + 1;
            break;
        }
    }
    if (A == 0) {
        cout << 0 << endl;
        return 0;
    }
    cout << 1 << endl;
    cout << A + B << endl;
    forn (i, ans) {
        if (s[i] == '(') {
            cout << i + 1 << " ";
        }
    }
    for (int i = ans; i < n; ++i) {
        if (s[i] == ')') {
            cout << i + 1 << " ";
        }
    }
    cout << endl;
}