#include<bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
#define mp make_pair

#define sz(a) (int)(a).size()
#define all(a) (a).begin(), (a).end()

#define ll long long
#define ld long double
#define int long long

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> bad;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        int num = 0;
        for (auto c : s) num = num * 2 + c - '0';
        bad.pb(num);
    }
    sort(all(bad));
    int k = (1LL << m) - n;
    int num = (k - 1) / 2;
    bad.pb(1LL << m);
    auto pr = [&] (int num) {
        for (int i = m - 1; i > -1; i--) cout << ((num >> i) & 1);
        cout << '\n';
    };
    if (num < bad[0]) {
        pr(num);
        return;
    }
    for (int i = 0; i + 1 < sz(bad); i++) {
        int bef = bad[i] - i;
        int need = num - bef;
        if (bad[i] + 1 + need < bad[i + 1]) {
            pr(bad[i] + 1 + need);
            return;
        }
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}