#include <algorithm>
#include <iostream>
#include <vector>
#include <set>

using namespace std;

typedef int64_t ll;

void start() {
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
}

void solve() {
    ll n, k;
    cin >> n >> k;
    string a;
    cin >> a;
    ll count = 0;
    ll cnt = 0;
    string s = a;
    bool f = true;
    while (f) {
        f = false;
        string t = s;
        for (ll j = 1; j < n; ++j) {
            if (s[j - 1] == 'R' && s[j] == 'L') {
                swap(t[j - 1], t[j]);
                if (!f) {
                    ++cnt;
                    f = true;
                }
                ++count;
            }
        }
        s = t;
    }
    if (k < cnt || k > count) {
        cout << -1 << endl;
        return;
    }
    vector<ll> kek;
    for (ll it = 0; it < k; ++it) {
        if (kek.empty()) {
            for (ll i = 0; i + 1 < n; ++i) {
                if (a[i] == 'R' && a[i + 1] == 'L') {
                    kek.emplace_back(i);
                }
            }
        }
        vector<ll> ans;
        while (!kek.empty() && count > k - it - 1) {
            ans.emplace_back(kek.back());
            --count;
            kek.pop_back();
        }
        cout << ans.size();
        for (ll i : ans) {
            cout << " " << i + 1;
            swap(a[i], a[i + 1]);
        }
        cout << "\n";
    }
}

int main() {
    start();
    solve();
    return 0;
}