#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const ll INF = 1e9 + 7;
const ll MAXN = 1e6 + 7;
const double EPS = 1e-8;

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
    vector <ll> a(n);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }
    ll m;
    cin >> m;
    vector <ll> b(m);
    for (ll i = 0; i < m; i++) {
        cin >> b[i];
    }
    ll res = 0;
    ll i = 1, j = 1;
    ll suma = a[0], sumb = b[0];
    while (true) {
        if (suma == sumb) {
            res++;
            if (i == n && j == m) break;
            if (i == n || j == m) {
                cout << -1;
                return 0;
            }
            suma = a[i], sumb = b[j];
            i++, j++;
            continue;
        }
        if (suma > sumb) {
            if (j == m) {
                cout << -1;
                return 0;
            }
            sumb += b[j++];
        } else {
            if (i == n) {
                cout << -1;
                return 0;
            }
            suma += a[i++];
        }
        //cout << suma << " " << sumb << "\n";
    }
    cout << res;
}