#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

int n;
string s;

void read() {
    cin >> n >> s;
}

ll ans;

void run() {
    ans = (ll)n * (n + 1) / 2;
    int cnt = 1;
    vector<int> have;
    for (int i = 1; i < n; i++) {
        if (s[i] == s[i - 1]) {
            cnt++;
        } else {
            have.push_back(cnt);
            cnt = 1;
        }
    }
    have.push_back(cnt);
    for (int i = 0; i < (int)have.size(); i++) {
        ans -= have[i];
        if (i > 0) ans -= have[i];
        if (i < (int)have.size() - 1) ans -= have[i];
    }
    ans += have.size() - 1;
}

void write() {
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    read();
    run();
    write();
    return 0;
}