#include<bits/stdc++.h>
using namespace std;

#define int long long

#define x first
#define y second
#define pb push_back
#define mp make_pair

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()

void solve() {
    int n, s;
    cin >> n >> s;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> pr(n), mx(n);
    for (int i = 0; i < n; i++) {
        pr[i] = a[i];
        mx[i] = i;
        if (i != 0) {
            pr[i] += pr[i - 1];
            if (a[mx[i - 1]] > a[i]) mx[i] = mx[i - 1];
        }
    }
    int ans = 0, ansid = -1;
    for (int i = 0; i < n; i++) {
        if (pr[i] <= s && i + 1 > ans) {
            ans = i + 1;
            ansid = -1;
        }
        if (pr[i] - a[mx[i]] <= s && i > ans) {
            ans = i;
            ansid = mx[i];
        }
    }
    cout << ansid + 1 << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}