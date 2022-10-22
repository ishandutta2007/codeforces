#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const ll INF = 1e9 + 7;
const ll MAXN = 1e6 + 7;
const double EPS = 1e-8;
const ll MOD = 1e12 + 7;

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
    #endif // MY;
    ll n, k;
    cin >> n >> k;
    vector <bool> exist(n + 1, false);
    vector <ll> a(n + 1);
    ll cnt = 0;
    for (ll i = 0; i <= n; i++) {
        string s;
        cin >> s;
        if (s == "?") {
            cnt++;
            continue;
        }
        bool fl = 0;
        ll d = 0;
        for (char c : s) {
            if (c == '-') {
                fl = true;
            } else {
                d = 10 * d + c - '0';
            }
        }
        if (fl) {
            d = -d;
        }
        a[i] = d;
        exist[i] = true;
    }
    if (!k) {
        if (exist[0]) {
            if (a[0]) {
                cout << "No\n";
            } else {
                cout << "Yes\n";
            }
        } else {
            cout << ((n - cnt + 1) % 2 == 0 ? "No" : "Yes");
        }
        return 0;
    }
    if (cnt) {
        cout << (n % 2 == 0 ? "No" : "Yes");
        return 0;
    }
    ll x = 1;
    ll res = 0;
    for (ll i = 0; i <= n; i++) {
        res += x * a[i] % MOD;
        res %= MOD;
        x = x * k % MOD;
        //cout << res << "\n";
    }
    if (!res) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
}