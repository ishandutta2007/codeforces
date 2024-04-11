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
    vector <ll> b(n);
    bool equals = true;
    for (ll i = 0; i < n; i++) {
        cin >> b[i];
        if (i && b[i] != b[i - 1]) {
            equals = false;
        }
    }
    if (equals) {
        if (b[0]) {
            cout << "NO\n";
            return 0;
        }
        cout << "YES\n";
        for (ll i = 0; i < n; i++) {
            cout << "1 ";
        }
        return 0;
    }
    cout << "YES\n";
    vector <ll> a(n);
    ll pos = 0;
    while (b[pos] >= b[(pos + 1) % n]) {
        pos++;
    }
    a[(pos + 1) % n] = b[(pos + 1) % n];
    a[pos] = a[(pos + 1) % n] * INF + b[pos];
    for (ll i = (pos + n - 1) % n; i != (pos + 1) % n; i = (i + n - 1) % n) {
        a[i] = a[(i + 1) % n] + b[i];
    }
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
}