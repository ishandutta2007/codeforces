#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    for(auto &x : v)
        cin >> x;
    int s = accumulate(v.begin(), v.end(), 0);
    if(abs(s) % 2) {
        cout << "-1\n";
        return;
    }
    if(s < 0) {
        s *= -1;
        for(auto &x : v)
            x *= -1;
    }
    s /= 2;
    int pv = -1;
    vector<int> take;
    for(int i = 0; i < n; i++) {
        if(take.size() == s)
            break;
        if(i == pv + 1 || v[i] != 1)
            continue;
        take.push_back(i);
        pv = i;
    }
    vector<int> used(n);
    vector<array<int, 2>> ans;
    if(take.size() < s) {
        cout << "-1\n";
        return;
    }
    for(auto x : take) {
        ans.push_back({x, x + 1});
        used[x - 1] = used[x] = 1;
    }
    for(int i = 0; i < n; i++) {
        if(!used[i])
            ans.push_back({i + 1, i + 1});
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << '\n';
    for(auto &[l, r] : ans)
        cout << l << " " << r << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
        solve();
}