// Yunyun loli

#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

typedef int64_t ll;

void start() {
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
}

int main() {
    start();

    ll n, m;
    cin >> n >> m;
    vector<ll> cord(n + m);
    for (ll i = 0; i < n + m; ++i) {
        cin >> cord[i];
    }
    vector<ll> t;
    vector<ll> a;
    vector<ll> res(m);
    for (ll i = 0; i < n + m; ++i) {
        ll type;
        cin >> type;
        if (type == 1) {
            t.push_back(cord[i]);
        }
        else {
            a.push_back(cord[i]);
        }
    }
    for (auto i : a) {
        ll left  = 0;
        ll right = m;
        while (right - left > 1) {
            ll mid = (left + right) / 2;
            if (t[mid] > i) {
                right = mid;
            }
            else {
                left = mid;
            }
        }
        if (right == m || t[right] - i >= i - t[left]) {
            ++res[left];
        }
        else {
            ++res[right];
        }
    }
    for (auto i : res) {
        cout << i << " ";
    }
    return 0;
}