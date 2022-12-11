// Bipolar disorder is very cool

#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

typedef int64_t ll;

void solve() {
    ll n, x, y;
    cin >> n >> x >> y;
    set<pair<ll, ll>> kek;
    vector<set<ll>> cnt(n + 1);
    vector<ll> a(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
        --a[i];
        cnt[a[i]].insert(i);
    }
    ll zero_color = -1;
    for (ll i = 0; i <= n; ++i) {
        kek.insert(make_pair(-((ll)cnt[i].size()), i));
        if (cnt[i].empty()) {
            zero_color = i;
        }
    }
    vector<ll> result(n, zero_color);
    while (x) {
        --x;
        --y;
        ll color = kek.begin()->second;
        kek.erase(kek.begin());
        ll index = (*cnt[color].begin());
        cnt[color].erase(cnt[color].begin());
        kek.insert(make_pair(-((ll)cnt[color].size()), color));
        result[index] = color;
    }
    while (y) {
        if (y == 3) {
            vector<ll> colors;
            for (ll i = 0; i <= n; ++i) {
                if (cnt[i].empty()) {
                    continue;
                }
                colors.emplace_back(i);
            }
            if (colors.size() >= 3) {
                colors.resize(3);
                ll color1 = colors[0];
                ll color2 = colors[1];
                ll color3 = colors[2];
                y -= 3;
                ll index1 = *cnt[color1].begin();
                ll index2 = *cnt[color2].begin();
                ll index3 = *cnt[color3].begin();
                result[index1] = color2;
                result[index2] = color3;
                result[index3] = color1;
                break;
            }
        }
        ll color1 = kek.begin()->second;
        kek.erase(kek.begin());
        ll color2 = kek.begin()->second;
        kek.erase(kek.begin());
        if (cnt[color2].empty()) {
            cout << "NO" << "\n";
            return;
        }
        ll index1 = (*cnt[color1].begin());
        ll index2 = (*cnt[color2].begin());
        cnt[color1].erase(cnt[color1].begin());
        cnt[color2].erase(cnt[color2].begin());
        kek.insert(make_pair(-((ll)cnt[color1].size()), color1));
        kek.insert(make_pair(-((ll)cnt[color2].size()), color2));
        if (y >= 2) {
            result[index1] = color2;
            result[index2] = color1;
            y -= 2;
        } else {
            result[index1] = color2;
            --y;
        }
    }
    cout << "YES" << "\n";
    for (ll i : result) {
        cout << i + 1 << " ";
    }
    cout << "\n";
}

int main() {
    ll t;
    cin >> t;
    while (t) {
        --t;
        solve();
    }
    return 0;
}