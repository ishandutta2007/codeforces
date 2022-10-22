#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    int n;
    ll m;
    ll k;
    vector<ll> h;
    for (int qq = 0; qq < t; qq++) {
        cin >> n >> m >> k;
        h.resize(n);
        for (int i = 0; i < n; i++)
            cin >> h[i];
        bool can = true;
        for (int i = 1; i < n; i++) {
            if (h[i-1] + k < h[i]) {
                m -= (h[i] - h[i-1] - k);
            }
            else {
                 m += min(h[i-1], h[i-1] - (h[i] - k));
            }
            if (m < 0) {
                can = false;
                break;
            }
        }
        if (!can) {
            cout << "NO" << '\n';
        }
        else {
            cout << "YES" << '\n';
        }
    }
    return 0;
}