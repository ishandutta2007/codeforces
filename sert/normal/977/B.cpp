#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = (ll)2e5 + 34;
const int INF = (int)1e9 + 34;

void solve() {
    int n;
    string s;
    cin >> n >> s;
    vector<int> kk(10000, 0);
    for (int i = 1; i < n; i++) {
        int code = (s[i - 1] - 'A') * 26 + s[i] - 'A';
        kk[code]++;
    }
    int mx = 0;
    for (int i = 0; i < (int)kk.size(); i++) {
        if (kk[i] > kk[mx]) {
            mx = i;
        }
    }
    cout << char('A' + mx / 26) << char('A' + mx % 26) << "\n";
}

int main() {
#ifdef FIRE_MIND
    freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
#endif
    //solve();
    solve();
    return 0;
}