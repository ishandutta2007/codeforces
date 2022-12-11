#pragma GCC diagnostic ignored "-Wunused-result"
#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;

void solve() {
    int n, p;
    cin >> n >> p;
    map<pair<int, int>, int> mp;
    vector<int> num(n);
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        if (a > b) swap(a, b);
        a--;
        b--;
        num[a]++;
        num[b]++;
        mp[make_pair(a, b)]++;
    }

    ll ans = 0;

    for (const auto &it : mp) {
        int a = it.first.first;
        int b = it.first.second;
        int cnt = it.second;
        if (num[a] + num[b] >= p && num[a] + num[b] - cnt < p) ans--;
    }
    // cout << ans << endl;

    sort(all(num));
    // for (int i = 0; i < n; i++) cout << num[i] << " ";
    // cout << endl;
    for (int i = 0; i < n; i++) {        
        int pos = lower_bound(all(num), p - num[i]) - num.begin();
        // cout << i << " " << pos << " " << p - num[i] << endl;
        ans += n - max(pos, i + 1);
    }

    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
#ifdef SERT
    int T = 3;
    for (int i = 1; i < T; i++) solve();    
#endif
}