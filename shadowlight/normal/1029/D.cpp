#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const ll INF = 1e9 + 7;
const ll MAXN = 1e6 + 7;
const double EPS = 1e-8;

ll cnt(ll x) {
    ll res = 0;
    do {
        x /= 10;
        res++;
    } while (x > 0);
    return res;
}

int main() {
    #ifdef MY
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #else
        //freopen(TASKNAME".in", "r", stdin);
        //freopen(TASKNAME".out", "w", stdout);
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
    #endif // MY
    int n, k;
    cin >> n >> k;
    vector <int> all[11];
    vector <int> a(n), c(n);
    for (ll i = 0; i < n; i++) {
        int x;
        cin >> x;
        a[i] = x % k;
        c[i] = cnt(x);
        all[c[i]].push_back(a[i]);
    }
    for (ll i = 0; i < 11; i++) {
        sort(all[i].begin(), all[i].end());
    }
    ll res = 0;
    for (int i = 0; i < n; i++) {
        ll d = a[i];
        for (int j = 1; j < 11; j++) {
            d = d * 10 % k;
            ll f = (d ? k - d : 0);
            auto lt = lower_bound(all[j].begin(), all[j].end(), f);
            auto rt = upper_bound(all[j].begin(), all[j].end(), f);
            res += rt - lt;
            if (j == c[i] && a[i] == (d ? k - d : 0)) {
                res--;
            }
        }
        //cout << i << " " << res << "\n";
    }
    cout << res;
}