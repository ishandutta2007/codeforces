#include <bits/stdc++.h>
using namespace std;
bool D = false;
const int INF = (int)1e9 + 41;
typedef long long ll;

void solve() {
    string s;
    int sum;
    ll x;
    cin >> x >> sum;

    s = to_string(x);
    int remLen = -1;
    int pref = 0;
    for (int i = 0; i < (int)s.length(); i++) {
        pref += s[i] - '0';
        if (pref + 1 <= sum && s[i] != '9') remLen = i;
    }
    if (pref <= sum) {
        cout << "0\n";
        return;
    }

    ll y = (remLen == -1 ? 1 : 0);
    for (int i = 0; i < (int)s.length(); i++) {
        y *= 10;
        int c = s[i] - '0';
        if (i < remLen) y += c;
        if (i == remLen) y += c + 1;
    }

    cout << y - x << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
#ifdef SERT
    freopen("a.in", "r", stdin);
    D = true;
    t = 4;
#else

#endif
    cin >> t;
    while (t--) {
        solve();
    }
}