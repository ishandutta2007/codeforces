#include<bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
#define mp make_pair

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()

#define ll long long
#define ld long double
#define int long long

void solve() {
    int n;
    cin >> n;
    vector<int> e(n);
    for (int i = 0; i < n; i++) cin >> e[i];
    sort(all(e));
    int ans = 0, pos = 0;
    while (pos < n) {
        int lst = pos;
        while (pos < n && pos - lst + 1 < e[pos]) pos++;
        if (pos < n) {
            pos++;
            ans++;
        }
    }
    cout << ans << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}