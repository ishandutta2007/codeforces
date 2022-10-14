#include <bits/stdc++.h>

#define pb push_back
#define int long long
#define ld long double
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, t;
    cin >> n >> t;
    string s;
    cin >> s;
    int kekw = (1LL << (s[n - 1] - 'a')) - (1LL << (s[n - 2] - 'a')) - t;
    s.pop_back();
    s.pop_back();
    sort(s.rbegin(), s.rend());
    for (int i = 0; i < n - 2; i++) {
        int num = (1LL << (s[i] - 'a'));
        if (kekw >= 0) {
            kekw -= num;
        } else {
            kekw += num;
        }
    }
    if (kekw == 0) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }

}