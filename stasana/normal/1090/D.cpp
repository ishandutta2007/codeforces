// Megumin top

#include <algorithm>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
#include <cmath>
#include <set>

using namespace std;

typedef int64_t ll;

void start() {
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
}

void solve() {
    ll n, m;
    cin >> n >> m;
    set<pair<ll, ll>> a;
    for (ll i = 0; i < m; ++i) {
        ll v, u;
        cin >> v >> u;
        a.insert(make_pair(v - 1, u - 1));
        a.insert(make_pair(u - 1, v - 1));
    }
    ll v = -1, u = -1;
    for (ll i = 0; i < n; ++i) {
        for (ll j = i + 1; j < n; ++j) {
            if (a.find(make_pair(i, j)) == a.end()) {
                v = i;
                u = j;
                break;
            }
        }
    }
    if (v == -1) {
        cout << "NO";
    }
    else {
        cout << "YES";
        cout << endl;
        vector<ll> a(n);
        for (ll i = 0; i < n; ++i) {
            a[i] = i + 1;
        }
        if (v > u) {
            swap(v, u);
        }
        swap(a[0], a[v]);
        if (v == 1) {
            swap(a[0], a[u]);
        }
        else {
            swap(a[1], a[u]);
        }
        for (ll i : a) {
            cout << i << " ";
        }
        cout << endl;
        a[u] = 1;
        for (ll i : a) {
            cout << i << " ";
        }
    }
}

int main() {
    start();
    solve();
    return 0;
}