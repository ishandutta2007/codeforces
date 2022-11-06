#include<bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
#define mp make_pair

#define all(x) (x).begin(), (x).end()
#define sz(x) (int) (x).size()

#define int long long

void solve() {
    int n;
    cin >> n;
    vector<int> p(n), v;
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        v.pb(p[i]);
    }
    sort(all(v));
    v.erase(unique(all(v)), v.end());
    vector<int> cnt(sz(v), 0);
    for (int i = 0; i < n; i++) {
        p[i] = lower_bound(all(v), p[i]) - v.begin();
        cnt[p[i]]++;
    }
    reverse(all(cnt));
    vector<int> pr(sz(v) + 1, 0);
    for (int i = 0; i < sz(v); i++) pr[i + 1] = pr[i] + cnt[i];
    int i = 1;
    while (i < sz(v) && pr[i + 1] - pr[1] <= cnt[0]) i++;
    int g = cnt[0];
    if (i == sz(v)) {
        cout << "0 0 0\n";
        return;
    }
    int s = pr[i + 1] - pr[1];
    int j = i + 1;
    while (j < sz(v) && pr[j + 1] - pr[i + 1] <= cnt[0]) j++;
    if (j == sz(v)) {
        cout << "0 0 0\n";
        return;
    }
    int b = pr[j + 1] - pr[i + 1];
    if (g + s + b > n / 2) {
        cout << "0 0 0\n";
        return;
    }
    for (int k = j + 1; k < sz(v); k++) {
        if (g + s + b + cnt[k] <= n / 2) {
            b += cnt[k];
        } else {
            break;
        }
    }
    cout << g << " " << s << " " << b << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}