#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
    ll n, m;
    cin >> n >> m;
    vector<ll> a(m);
    vector<ll> c2n(70, 0LL);
    vector<ll> c2a(70, 0LL);
    for (int i = 0; i < m; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int ci = 62;
    int cia = a.size() - 1;
    for (ll cl = (1LL << ci); cl > 0; cl = (cl >> 1)) {
        if (n >= cl) {
            n -= cl;
            ++c2n[ci];
        }
        while (cia >= 0 && a[cia] == cl) {
            ++c2a[ci];
            --cia;
        }
        --ci;
    }

    int mia = 0;
    int ans = 0;
    for (int ni = 0; ni < 65; ++ni) {
        if (mia < ni) {
            c2a[ni] += c2a[ni - 1] / 2;
            ++mia;
        }
        while (mia < 65 && c2a[mia] == 0) {
            ++mia;
        }
        if (c2n[ni] == 0) {
            continue;
        }
        if (mia == 65) {
            cout << "-1\n";
            return;
        }
        while (mia > ni) {
            --c2a[mia];
            --mia;
            c2a[mia] += 2;
            ++ans;
        }
        --c2a[mia];
    }
    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        solve();
    }
    return 0;
}