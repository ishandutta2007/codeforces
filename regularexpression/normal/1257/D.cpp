#include<bits/stdc++.h>
using namespace std;
 
#define x first
#define y second
#define pb push_back
#define mp make_pair
 
#define all(a) (a).begin(), (a).end()
#define sz(a) (int) (a).size()
 
#define ll long long
#define int long long
 
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    reverse(all(a));
    int m;
    cin >> m;
    vector<int> mx(n + 1, 0);
    for (int i = 0; i < m; i++) {
        int p, s;
        cin >> p >> s;
        mx[s] = max(mx[s], p);
    }
    for (int i = n - 1; i > -1; i--) {
        mx[i] = max(mx[i], mx[i + 1]);
    }
    bool ok = true;
    int ans = 0;
    while (!a.empty()) {
        ans++;
        int l = 0, cur = 0;
        while (l + 1 <= sz(a)) {
            if (max(cur, a[sz(a) - l - 1]) > mx[l + 1]) {
                break;
            }
            cur = max(cur, a[sz(a) - l - 1]);
            l++;
        }
        if (l == 0) {
            ok = false;
            break;
        }
        while (l--) {
            a.pop_back();
        }
    }
    cout << (ok ? ans : -1) << '\n';
}
 
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}