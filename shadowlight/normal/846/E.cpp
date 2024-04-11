#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const ll INF = 1e12 + 7;
const ll MAXN = 1e6 + 7;
const double EPS = 1e-8;

vector <ll> a, b;

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
    ll n;
    cin >> n;
    a.resize(n);
    b.resize(n);
    for (ll i = 0; i < n; i++) {
        cin >> b[i];
    }
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector <ll> x(n), k(n);
    for (ll i = 1; i < n; i++) {
        cin >> x[i] >> k[i];
        x[i]--;
    }
    for (ll i = n - 1; i > 0; i--) {
        ll need = a[i] - b[i];
        if (need <= 0) {
            b[x[i]] += -need;
            continue;
        }
        if (INF / k[i] < need) {
            cout << "NO\n";
            return 0;
        }
        b[x[i]] -= k[i] * need;
    }
    ll need = a[0] - b[0];
    if (need > 0) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
    }
}