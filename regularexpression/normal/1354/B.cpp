#include<bits/stdc++.h>
using namespace std;

#define int long long

#define x first
#define y second
#define pb push_back
#define mp make_pair

#define all(a) (a).begin(), (a).end()
#define sz(a) ((int)(a).size())

void solve() {
    string s;
    cin >> s;
    map<char, int> ls;
    int ans = 2e18 + 7;
    for (int i = sz(s) - 1; i > -1; i--) {
        ls[s[i]] = i;
        if (sz(ls) == 3) ans = min(ans, max({ls['1'], ls['2'], ls['3']}) - i + 1);
    }
    cout << (ans == 2e18 + 7 ? 0 : ans) << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}