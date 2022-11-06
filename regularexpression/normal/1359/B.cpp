#include<bits/stdc++.h>
using namespace std;

#define int long long
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<vi> vvi;

#define x first
#define y second
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define mt make_tuple

#define len(a) ((int)(a).size())
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()

void solve() {
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    y = min(y, 2 * x);
    vector<string> a(n);
    for (auto &s : a) cin >> s;
    int ans = 0;
    for (auto s : a) {
        int cur = 0;
        for (int i = 0; i < m; i++) {
            if (s[i] == '.') cur++; else cur = 0;
            if (i + 1 == m || s[i + 1] == '*') ans += cur / 2 * y + cur % 2 * x;
        }
    }
    cout << ans << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}