#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void printv(vector<ll> v) {
    for (int i = 0; i < v.size(); ++i) {
        cout << v[i] << " ";
    }
    cout << "\n";
}

ll max_sum(vector<ll> v) {
    int n = v.size();
    if (n == 0) {
        return 0LL;
    }
    vector<ll> pref(n);
    pref[0] = v[0];
    for (int i = 1; i < n; ++i) {
        pref[i] = pref[i - 1] + v[i];
    }
    vector<ll> mpref(n);
    mpref.back() = pref.back();
    for (int i = n - 2; i >= 0; --i) {
        mpref[i] = max(mpref[i + 1], pref[i]);
    }
    
    ll ans = max(0LL, mpref[0]);
    for (int i = 1; i < n; ++i) {
        ans = max(ans, mpref[i] - pref[i - 1]);
    }
    return ans;
}

void solve() {
    int n;
    cin >> n;
    ll sum = 0;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (i % 2 == 0) {
            sum += a[i];
        }
    }
    
    ll ans1, ans2;
    vector<ll> que;
    que.clear();
    for (int i = 0; i < n - 1; i += 2) {
        que.push_back(a[i + 1] - a[i]);
    }
    ans1 = max_sum(que);
    que.clear();
    for (int i = 1; i < n - 1; i += 2) {
        que.push_back(a[i] - a[i + 1]);
    }
    ans2 = max_sum(que);
    sum += max(ans1, ans2);
    
    cout << sum << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int t;
    cin >> t;
    for (int qq = 0; qq < t; ++qq) {
        solve();
    }
    
    return 0;
}